void lineFollow(int tableNo)
{
  int error, delspeed;
  error = conditions();
  if (error == 1000)
  {
    count++;
    //    lcd.setCursor(0, 1);
    //    lcd.print(count);

    if ((((tableNo == 1 || tableNo == 2) && count == 2) || ((tableNo == 3 || tableNo == 4) && count == 3)) && analogRead(A10) > 360)
    {
      show_message("Please Take", 0, 2, true);
      Serial1.print("#");
      stopBot(0);
      
      digitalWrite(buzzPin, HIGH);
      delay(400);
      digitalWrite(buzzPin, LOW);
      delay(400);
      digitalWrite(buzzPin, HIGH);
      delay(400);
      digitalWrite(buzzPin, LOW);
      delay(400);
      
      while (analogRead(A10) > 360)
      {
        stopBot(0);
      }
      show_message("Thank you", 0, 3, true);
      delay(3000);
      Serial1.print("$");
      show_message("Returning back", 0, 1, true);
      show_message("to the kitchen", 1, 1, false);
    }

    bool fright = false;
    bool fleft = false;
    bool fstraight = false;
    if (tableNo == 1)
    {
      fright = readArray(rightOne, nrOne, count);
      fleft = readArray(leftOne, nlOne, count);
      fstraight = readArray(straightone, nsOne, count);
    }
    else if (tableNo == 2)
    {
      fright = readArray(rightTwo, nrTwo, count);
      fleft = readArray(leftTwo, nlTwo, count);
      fstraight = readArray(straightTwo, nsTwo, count);
    }
    else if (tableNo == 3)
    {
      fright = readArray(rightThree, nrThree, count);
      fleft = readArray(leftThree, nlThree, count);
      fstraight = readArray(straightThree, nsThree, count);
    }
    else if (tableNo == 4)
    {
      fright = readArray(rightFour, nrFour, count);
      fleft = readArray(leftFour, nlFour, count);
      fstraight = readArray(straightFour, nsFour, count);
    }
    if (fright)
    {
      turnRight();
    }
    else if (fleft)
    {
      turnLeft();
    }
    else if (fstraight)
    {
      goStraight();
    }
  }
  else
  {
    if ((tableNo == 1 || tableNo == 2) && count >= stopRobot1)
    {
      show_message("Ready to serve", 0, 1 , true);
      Serial1.print("*");
      digitalWrite(irEnb, LOW);
      startFlag = 0;
      count = 0;
      stopBot(0);
    }
    else if ((tableNo == 3 || tableNo == 4) && count >= stopRobot2)
    {
      show_message("Ready to serve", 0, 1 , true);
      Serial1.print("*");
      digitalWrite(irEnb, LOW);
      startFlag = 0;
      count = 0;
      stopBot(0);
    }
    if (startFlag)
    {
      delspeed = (kp * error) + (kd * (error - preverror));
      leftspeed = leftbasespeed + delspeed;
      rightspeed = rightbasespeed - delspeed;
      wheel(leftspeed , rightspeed);
      preverror = error;
    }
  }
}

void lineFollow(int tableNo)
{
  int error, delspeed;
  error = conditions();
  //  Serial.println(error);
  if (error == 1000)
  {
    count++;
    bool fright = false;
    bool fleft = false;
    bool fstraight = false;
    if (tableNo == 1)
    {
//      Serial.println("Table 1");
//      Serial.println(count);
      fright = readArray(rightOne, nrOne, count);
      fleft = readArray(leftOne, nlOne, count);
      fstraight = readArray(straightone, nsOne, count);
    }
    else if (tableNo == 2)
    {
//      Serial.println("Table 2");
//      Serial.println(count);
      fright = readArray(rightTwo, nrTwo, count);
      fleft = readArray(leftTwo, nlTwo, count);
      fstraight = readArray(straightTwo, nsOne, count);
    }
    else if (tableNo == 3)
    {
//      Serial.println("Table 3");
//      Serial.println(count);
      fright = readArray(rightThree, nrThree, count);
      fleft = readArray(leftThree, nlThree, count);
      fstraight = readArray(straightThree, nsThree, count);
    }
    else if (tableNo == 4)
    {
//      Serial.println("Table 4");
//      Serial.println(count);
      fright = readArray(rightFour, nrFour, count);
      fleft = readArray(leftFour, nlFour, count);
      fstraight = readArray(straightFour, nsFour, count);
    }
    if (fright)
    {
//      Serial.println("Right");
      turnRight();
    }
    else if (fleft)
    {
//      Serial.println("Left");
      turnLeft();
    }
    else if (fstraight)
    {
//      Serial.println("Straight");
      goStraight();
    }
  }
  else
  {
    if ((tableNo == 1 || tableNo == 2) && count == stopRobot1)
    {
      digitalWrite(irEnb, LOW);
      startFlag = 0;
      count = 0;
      stopBot(0);
    }
    else if ((tableNo == 3 || tableNo == 4) && count == stopRobot2)
    {
      digitalWrite(irEnb, LOW);
      startFlag = 0;
      count = 0;
      stopBot(0);
    }
    if (startFlag)
    {
      //    Serial.println("Here");
      delspeed = (kp * error) + (kd * (error - preverror));
      leftspeed = leftbasespeed + delspeed;
      rightspeed = rightbasespeed - delspeed;
      wheel(leftspeed , rightspeed);
      preverror = error;
    }
  }
}

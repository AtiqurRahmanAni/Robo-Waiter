void lineFollow()
{
  int error, delspeed;
  error = conditions();
  //  Serial.println(error);
  if (error == 1000)
  {
    int flag = 0;
    //right flag = 1
    //left flag = 2
    //forwardright flag = 3
    //forwardleft flag = 4
    count++;
    for (int i = 0; i < nr; i++)
    {
      if (count == right[i])
      {
        flag = 1;
        break;
      }
    }
    for (int i = 0; i < nl; i++)
    {
      if (count == left[i])
      {
        flag = 2;
        break;
      }
    }
    //      lcd.setCursor(0, 0);
    //      lcd.print(flag);
    //      lcd.setCursor(0, 1);
    //      lcd.print(count);
    if (flag == 1)
    {
      turnRight();
    }
    else if (flag == 2)
    {
      turnLeft();
    }
  }
  else
  {
    if (count == 12 && sums == 0)
    {
      wheel(0, 0);
      delay(20000);
    }
    //    Serial.println("Here");
    delspeed = (kp * error) + (kd * (error - preverror));
    leftspeed = leftbasespeed + delspeed;
    rightspeed = rightbasespeed - delspeed;
    wheel(leftspeed , rightspeed);
    preverror = error;
  }
}

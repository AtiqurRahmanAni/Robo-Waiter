void lineFollow()
{
  int error, delspeed;
  error = conditions();
  //  if (error == 1000)
  //  {
  //
  //  }
  //  else
  //  {
  delspeed = (kp * error) + (kd * (error - preverror));
  
  leftspeed = leftbasespeed + delspeed;
  rightspeed = rightbasespeed - delspeed;
  wheel(leftspeed , rightspeed);
  preverror = error;
  //  }
}

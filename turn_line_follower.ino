void turnRight()
{
  readLine();
  while (sums >= 4)
  {
    readLine();
    wheel(turnspeedleft, turnspeedright);
  }
  delay(70);
  stopBot(150);
  while (true)
  {
    readLine();
    if (sensorReading[7])
    {
      break;
    }
    wheel(turnspeedleft, -turnspeedright);
  }
  stopBot(150);
}
void turnLeft()
{
  readLine();
  while (sums >= 4)
  {
    readLine();
    wheel(turnspeedleft, turnspeedright);
  }
  delay(70);
  stopBot(150);
  while (true)
  {
    readLine();
    if (sensorReading[0])
    {
      break;
    }
    wheel(-turnspeedleft, turnspeedright);
  }
  stopBot(150);
}
void goStraight()
{
  readLine();
  while (sums >= 4)
  {
    readLine();
    wheel(turnspeedleft, turnspeedright);
  }
}
void stopBot(int del)
{
  //digitalWrite(13, HIGH);
  wheel(0, 0);
  delay(del);
}

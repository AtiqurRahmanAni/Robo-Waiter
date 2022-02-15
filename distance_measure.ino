int measureDistance()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duration = pulseIn(echo, HIGH, 15000);
  
  if (duration == 0)
  {
    return 20;
  }
  int distance = (duration * 0.034) / 2.00 ;

  return distance;
}

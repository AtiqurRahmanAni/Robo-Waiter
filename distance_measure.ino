int measureDistance()
{
  digitalWrite(trig,LOW);
  delay(1);
  digitalWrite(trig,HIGH);
  delay(10);
  digitalWrite(trig, LOW);
  
  long duration = pulseIn(echo, HIGH);
  int distance = (duration * 0.034)/2.00 ;

  return distance;
}

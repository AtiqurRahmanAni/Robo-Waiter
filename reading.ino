void readLine()
{
  for(int i = 0; i < num_sensor; i++)
  {
    sensorReading[i] = analogRead(i) < threshold ? 1 : 0;
  }
  sums = 0;
  for(int i = 0; i < num_sensor; i++)
  {
    sums += sensorReading[i];
//    Serial.print(sensorReading[i]);
//    Serial.print(" ");
  }
//  Serial.println("");
}

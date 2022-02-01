void readLine()
{

//  sensorReading[0] = !digitalRead(sen1);
//  sensorReading[7] = !digitalRead(sen8);
  sensorReading[0] = analogRead(5) < threshold ? 1 : 0;
  sensorReading[7] = analogRead(4) < threshold ? 1 : 0;
  int j = 0;
  
  for(int i = 7; i >= 0; i--)
  {
    if(i == 4 || i == 5)
    {
      continue;
    }
    sensorReading[++j] = analogRead(i) < threshold ? 1 : 0;
  }
  sums = 0;
  j = 15;
  for(int i = 0; i < num_sensor; i++)
  {
    sums += sensorReading[i];
  }
}

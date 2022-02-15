int conditions()
{
  int i, error, linepos, sumws;
  readLine();
  if(sums >= 3)
  {
    return 1000;
  }
  sumws = (sensorReading[0] * 10 + sensorReading[1] * 20 + sensorReading[2] * 30 + sensorReading[3] * 40 + sensorReading[4] * 50 + sensorReading[5] * 60 + sensorReading[6] * 70 + sensorReading[7] * 80 + sensorReading[8] * 90 + sensorReading[9] * 100);
  linepos = sumws / (float)sums;
  error = linepos - 55;
  return error;
}

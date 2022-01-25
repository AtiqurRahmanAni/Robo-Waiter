int conditions()
{
  int i, error, linepos, sumws;
  readLine();
  if(sums >= 4)
  {
    return 1000;
  }
  sumws = (sensorReading[0] * 10 + sensorReading[1] * 20 + sensorReading[2] * 30 + sensorReading[3] * 40 + sensorReading[4] * 50 + sensorReading[5] * 60 + sensorReading[6] * 70 + sensorReading[7] * 80);
  linepos = sumws / sums;
  error = linepos - 45;
  return error;
}

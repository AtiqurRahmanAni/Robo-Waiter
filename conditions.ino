int conditions()
{
  int i, error, linepos, sumws;
  readLine();
  //  //End of condition
  sumws = (sensorReading[0] * 10 + sensorReading[1] * 20 + sensorReading[2] * 30 + sensorReading[3] * 40 + sensorReading[4] * 50 + sensorReading[5] * 60 + sensorReading[6] * 70 + sensorReading[7] * 80);
  linepos = sumws / sums;
  error = linepos - 45;
  //  if (s[0] == 1 || s[1]==1)
  //    lastsensor = 1;
  //  else if (s[6]==1 || s[7] == 1)
  //    lastsensor = 2;
  //  else if(s[3]==1 || s[4]==1 && s[0]+s[1]+s[6]+s[7]==0)
  //    lastsensor=3;
  return error;
}

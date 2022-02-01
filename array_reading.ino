bool readArray(int ara[], int sz, int cnt)
{
  for(int i = 0; i < sz; i++)
  {
    if(ara[i] == cnt)
    {
      return true;
    }
  }
  return false;
}

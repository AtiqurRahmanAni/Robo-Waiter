void show_message(String s, int row, int col, bool clr)
{
  if (prevMsg != s)
  {
    if(clr)
    {
       lcd.clear();
    }
    lcd.setCursor(col, row);
    lcd.print(s);
    prevMsg = s;
  }
}

#include<LiquidCrystal_I2C.h>
#include<Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const byte echo = 8;
const byte trig = 9;
const byte irEnb = 13;
const byte ina = 3;
const byte inb = 4;
const byte inc = 5;
const byte ind = 6;
const byte ena = 2;
const byte enb = 7;
const byte buzzPin = 10;

const int leftbasespeed = 150; //Speed for line follow
const int rightbasespeed = 150; //Speed for line follow
const int maxspeed = 170; //Speed for line follow
const int turnspeedright = 100; //Speed for line follow
const int turnspeedleft = 100; //Speed for line follow
int lastsensor, num_sensor = 10, threshold = 600, preverror;
int leftspeed = 0, rightspeed = 0;
float kp = 6; //4
float kd = 42; //33
int sums = 0, count = 0;
int sensorReading[10];
int right[] = {1, 3, 4, 5, 9};
int left[] = {2, 6, 7, 8, 10, 11, 12};

//table 1
int rightOne[] = {2, 3, 4};
int leftOne[] = {1};
int straightone[] = {};
int nrOne = sizeof(rightOne) / sizeof(int);
int nlOne = sizeof(leftOne) / sizeof(int);
int nsOne = sizeof(straightone) / sizeof(int);

//table 2
int rightTwo[] = {1, 4};
int leftTwo[] = {2, 3};
int straightTwo[] = {};
int nrTwo = sizeof(rightTwo) / sizeof(int);
int nlTwo = sizeof(leftTwo) / sizeof(int);
int nsTwo = sizeof(straightTwo) / sizeof(int);
int stopRobot1 = 4;

//table 3
int rightThree[] = {2, 3};
int leftThree[] = {4, 6};
int straightThree[] = {1, 5};
int nrThree = sizeof(rightThree) / sizeof(int);
int nlThree = sizeof(leftThree) / sizeof(int);
int nsThree = sizeof(straightThree) / sizeof(int);

//table 4
int rightFour[] = {4, 6};
int leftFour[] = {2, 3};
int straightFour[] = {1, 5};
int nrFour = sizeof(rightFour) / sizeof(int);
int nlFour = sizeof(leftFour) / sizeof(int);
int nsFour = sizeof(straightFour) / sizeof(int);
int stopRobot2 = 6;

int straight[] = {};
int forwardright[] = {};
int forwardleft[] = {};
int nr = sizeof(right) / sizeof(int);
int nl = sizeof(left) / sizeof(int);
int ns = sizeof(straight) / sizeof(int);
int nfr = sizeof(forwardright) / sizeof(int);
int nfl = sizeof(forwardleft) / sizeof(int);
int startFlag = 0;
char ch;
String prevMsg = "", msg = "";

byte customChar[] = {
  0x1F,
  0x1F,
  0x1F,
  0x1F,
  0x1F,
  0x1F,
  0x1F,
  0x1F
};

//function definitions
int conditions();
void lineFollow();
void wallFollow();
void readLine();
void turnRight();
void turnLeft();
void goStraight();
void stopBot(int del);
bool readArray(int ara[], int sz, int cnt);
int measureDistance();
void show_message(String s);

void setup()
{
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(ina, OUTPUT);
  pinMode(inb, OUTPUT);
  pinMode(inc, OUTPUT);
  pinMode(ind, OUTPUT);

  pinMode(trig, OUTPUT);
  pinMode(irEnb, OUTPUT);

  pinMode(buzzPin, OUTPUT);

  pinMode(echo, INPUT);

  lcd.init();
  lcd.backlight();
  lcd.home();
  lcd.setCursor(5, 0);
  lcd.print("Hello");
  lcd.setCursor(0, 1);
  lcd.print("I am robo waiter");
  digitalWrite(irEnb, LOW);
  Serial1.begin(9600);
  Serial.begin(9600);
  delay(1000);
  Serial1.print("*");
}
void loop()
{
  if (Serial1.available())
  {
    ch = Serial1.read();
    if (ch >= '1' && ch <= '4')
    {
      show_message("Going table " + (String)ch, 0, 0, true);
      digitalWrite(irEnb, HIGH);
      startFlag = 1;
      delay(400);
    }
  }
  //  readLine();

  if (startFlag)
  {
    int distance = measureDistance();
    //Serial.println(distance);
    if ( distance > 10)
    {
      digitalWrite(buzzPin, LOW);
      lineFollow(ch - '0');
    }
    else
    {
      // Serial1.println(distance);
      stopBot(0);
      digitalWrite(buzzPin, HIGH);
    }
  }
}

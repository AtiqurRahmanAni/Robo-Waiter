#include<LiquidCrystal_I2C.h>
#include<Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const byte echo = 12;
const byte trig = 13;
const byte irEnb = 4;
const byte ina = 8;
const byte inb = 7;
const byte inc = 6;
const byte ind = 5;
const byte ena = 9;
const byte enb = 3;
const byte sen1 = 10;
const byte sen8 = 11;

const int leftbasespeed = 150; //Speed for line follow
const int rightbasespeed = 150; //Speed for line follow
const int maxspeed = 170; //Speed for line follow
const int turnspeedright = 100; //Speed for line follow
const int turnspeedleft = 100; //Speed for line follow
int lastsensor, num_sensor = 8, threshold = 550, preverror;
int leftspeed = 0, rightspeed = 0;
float kp = 6.20; //4
float kd = 40; //33
int sums = 0, count = 0;
int sensorReading[8];
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
void turnRight(int del1, int del2);
void turnLeft(int del1, int del2);
void goStraight(int del, int wheelspeed);
void stopBot(int del);

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

  pinMode(echo, INPUT);
  pinMode(sen1, INPUT);
  pinMode(sen8, INPUT);

  //  lcd.init();
  //  lcd.backlight();
  //  lcd.home();
  digitalWrite(irEnb, LOW);
  Serial.begin(9600);
}
void loop()
{
  if (Serial.available())
  {
    ch = Serial.read();
    if (ch >= '1' && ch <= '4')
    {
      digitalWrite(irEnb, HIGH);
      startFlag = 1;
    }
  }
  //  readLine();
  //  conditions();
  
  if (startFlag)
  {
    int limit = 10;
    int distance = measureDistance();
    //Serial.println(distance);
    if( distance > limit)
    {
      lineFollow(ch - '0');
    }
    else
    {
      stopBot(0);
    }
  }
}

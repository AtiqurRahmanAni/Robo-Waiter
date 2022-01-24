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
int duration;
float distance;
const int leftbasespeed = 150; //Speed for line follow
const int rightbasespeed = 150; //Speed for line follow
const int maxspeed = 170; //Speed for line follow
const int turnspeedright = 100; //Speed for line follow
const int turnspeedleft = 100; //Speed for line follow
int lastsensor, num_sensor = 8, threshold = 450, preverror;
int leftspeed = 0, rightspeed = 0;
float kp = 6.20; //4
float kd = 90; //33
int sums = 0;
int sensorReading[8];
/*int right[] = {1, 3, 4, 5, 11};
  int left[] = {2, 7, 8, 10, 13, 14};
  int straight[] = {6, 9};
  int forwardright[] = {};
  int forwardleft[] = {12};*/
int right[] = {1, 2, 5, 6, 7, 11};
int left[] = {4, 8, 9, 10, 12};
int straight[] = {};
int forwardright[] = {3};
int forwardleft[] = {};
int nr = sizeof(right) / sizeof(int);
int nl = sizeof(left) / sizeof(int);
int ns = sizeof(straight) / sizeof(int);
int nfr = sizeof(forwardright) / sizeof(int);
int nfl = sizeof(forwardleft) / sizeof(int);
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
int conditions();
void lineFollow();
void wallFollow();
void readLine();
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

  lcd.init();
  digitalWrite(irEnb, HIGH);
  Serial.begin(9600);
}
void loop()
{
  //  readLine();
  //  conditions();
  lineFollow();
}

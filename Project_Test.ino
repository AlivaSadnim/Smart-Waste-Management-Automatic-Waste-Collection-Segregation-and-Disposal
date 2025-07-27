// For 4 wheels -> en1,en2,in1,in2,in3,in4

int r_en1 = 12;
int l_en1=9;
int rpwm1 = 11;
int lpwm1 = 10;
int r_en2=2;
int l_en2=3;
int rpwm2=5;
int lpwm2=6;
int trig = 8;
int echo = 7;
int out1 =A1;

int out2 =A2;
int out3 =A3;
int out4 =A4;
int out5 =A5;
int speed=100;

int blackThreshold=750;

long timeInMicro;
long distanceInCm;



void moveForward()
{
  
  analogWrite(rpwm1,speed);
  analogWrite(rpwm2,0);
  analogWrite(lpwm1,0);
  analogWrite(lpwm2,speed);

}
void turnLeft()
{
  analogWrite(rpwm1,0);
  analogWrite(rpwm2,0);
  analogWrite(lpwm1,speed);
  analogWrite(lpwm2,speed);
  delay(80);

}

void turnRight()
{ 
  analogWrite(rpwm1,speed);
  analogWrite(rpwm2,speed);
  analogWrite(lpwm1,0);
  analogWrite(lpwm2,0);
  delay(80);
}
void stop()
{ 
  analogWrite(rpwm1,0);
  analogWrite(rpwm2,0);
  analogWrite(lpwm1,0);
  analogWrite(lpwm2,0);
 

}
void setup() {
  // put your setup code here, to run once:
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);  
  pinMode(r_en1, OUTPUT);
  pinMode(l_en1, OUTPUT);
  pinMode(rpwm1, OUTPUT );
  pinMode(lpwm1, OUTPUT);
  pinMode(r_en2, OUTPUT);
  pinMode(l_en2, OUTPUT);
  pinMode(rpwm2, OUTPUT);
  pinMode(lpwm2, OUTPUT);
  digitalWrite(r_en1, HIGH);  
  digitalWrite(l_en1,HIGH);
  digitalWrite(r_en2,HIGH);
  digitalWrite(l_en2,HIGH);
  Serial.begin(9600);
  analogWrite(rpwm1,0);
  analogWrite(rpwm2,0);
  analogWrite(lpwm1,0);
  analogWrite(lpwm2,0);
 
}

void loop() {
  

int s1 = 0;
int s2 = 0;
int s3= 0;
int s4 = 0;
int s5 = 0;
  

  // put your main code here, to run repeatedly:
  int sensor5Value = analogRead(A1);
  int sensor1Value = analogRead(A2);
  int sensor3Value = analogRead(A3);
  int sensor2Value = analogRead(A4);
  int sensor4Value = analogRead(A5);
  
if(sensor1Value > blackThreshold)
{

  s1 = 1;
  
}

if(sensor2Value > blackThreshold)
{

  s2 = 1;
  
}
if(sensor3Value > blackThreshold)
{
  
  s3 = 1;
  
}
if(sensor4Value > blackThreshold)
{
  s4 = 1;
  
}
if(sensor5Value > blackThreshold)
{
  s5 = 1;
  
}

digitalWrite(trig,LOW);

digitalWrite(trig,HIGH);

digitalWrite(trig,LOW);
timeInMicro= pulseIn(echo,HIGH);
distanceInCm = ((timeInMicro/29)/2);
if(distanceInCm <= 10 )
  {
  analogWrite(rpwm1,0);
  analogWrite(rpwm2,0);
  analogWrite(lpwm1,0);
  analogWrite(lpwm2,0);

  
   }
else{
if((s1==0)&&(s2==1)&&(s3==1)&&(s4==1)&&(s5==1))
{
  
  turnRight();
  stop();
 
}
else if((s1==1)&&(s2==0)&&(s3==1)&&(s4==1)&&(s5==1))
{
  turnRight();
  stop();

}
else if((s1==0)&&(s2==0)&&(s3==1)&&(s4==1)&&(s5==1))
{
  turnRight();
  stop();
}
else if((s1==0)&&(s2==0)&&(s3==0)&&(s4==1)&&(s5==1))
{
  turnRight();
  stop();
}

else if ((s1==1)&&(s2==1)&&(s3==1)&&(s4==0)&&(s5==1))
{
  turnLeft();
  stop();
}
else if ((s1==1)&&(s2==1)&&(s3==1)&&(s4==1)&&(s5==0))
{
  turnLeft();
  stop();
 
}
else if((s1==1)&&(s2==1)&&(s3==1)&&(s4==0)&&(s5==0))
{
  turnLeft();
  stop();
  
}
else if((s1==1)&&(s2==1)&&(s3==0)&&(s4==0)&&(s5==0))
{
  turnLeft();
  stop();
}
else if((s1==1)&&(s2==1)&&(s3==1)&&(s4==1)&&(s5==1))
{
  turnRight();
  stop();
}
else
{
  moveForward();
  
}

}

/*else
{
 if((s1==0)&&(s2==0))
  {
    turnRight();
  }
 else if((s4==0)&&(s5==0))
  {
    turnRight();
  }
 else
 {
   moveForward();
 }
}*/
/*Serial.print(s1);
Serial.print("----");
Serial.print(s2);
Serial.print("----");
Serial.print(s3);
Serial.print("----");
Serial.print(s4);
Serial.print("----");
Serial.print(s5);
Serial.println("----");
delay(1000);
*/
}

   
 
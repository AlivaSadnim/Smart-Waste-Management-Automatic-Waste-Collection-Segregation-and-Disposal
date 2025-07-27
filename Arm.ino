#include <Servo.h>

 Servo base,shoulder,elbow,roll,pitch,grip;
void setup() {
  base.attach(5);
  shoulder.attach(6);
  elbow.attach(7);
  roll.attach(8);
  pitch.attach(9);
  grip.attach(10);

}
void baseforward()
{ 
  base.write(0);
  }
void basebackward()
{ 
  base.write(180);
  }
void shoulderup()
{ 
  shoulder.write(120);
  }
 void shoulderdown()
{ 
  shoulder.write(50);
  }
 void elbowup()
{ 
  elbow.write(120);
  }
void elbowdown()
{ 
  elbow.write(180);
  }
 void gripon()
{ 
  grip.write(180);
  }
 void gripoff()
{ 
  grip.write(20);
  }
 void rollup()
 {
  roll.write(65);
  }
 void pitchup()
 {
    pitch.write(0);
  }
 void pitchdown()
 {
  pitch.write(120);
  }
void grab()
{
 delay(1000);
 baseforward();
 delay(2000);
 gripon();
 delay(2000);
 shoulderdown();
 delay(2000);
 elbowup();
 delay(2000);
 //rollup();
 //delay(2000);
 //pitchdown();
 //delay(2000);
 gripoff();
 delay(3000);
 shoulderup();
 delay(2000);
 basebackward();
 delay(5000);
 gripon();
 delay(2000);
}
 
void loop() {
  grab();

}

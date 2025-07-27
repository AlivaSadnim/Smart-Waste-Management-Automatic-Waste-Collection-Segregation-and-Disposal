#include <Servo.h>

 Servo pitch;
void setup() {
  pitch.attach(7);
}

void loop() {
  // put your main code here, to run repeatedly:
  pitch.write(120);//up
  delay(2000);
  //pitch.write(120);//down
  //delay(2000);
  

}

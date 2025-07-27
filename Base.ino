#include <Servo.h>

 Servo base;
void setup() {
  base.attach(10);
}

void loop() {
  // put your main code here, to run repeatedly:
  base.write(300);
  delay(2000);
  base.write(0);
  delay(2000);
  

}

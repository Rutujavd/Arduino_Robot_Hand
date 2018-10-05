#include <Servo.h>

#define FINGER_PIN_1 2
#define FINGER_PIN_2 3
#define FINGER_PIN_3 4
#define FINGER_PIN_4 5
#define FINGER_PIN_5 6
#define PUSH_PIN 53

#define CALIB_MODE false

Servo servo_1, servo_2, servo_3, servo_4, servo_5;

void setup() {
  Serial.begin(9600);

  pinMode(PUSH_PIN, INPUT);

  servo_1.attach(FINGER_PIN_1);
  servo_2.attach(FINGER_PIN_2);
  servo_3.attach(FINGER_PIN_3);
  servo_4.attach(FINGER_PIN_4);
  servo_5.attach(FINGER_PIN_5);

  if(CALIB_MODE){
    servo_1.write(90);
    servo_2.write(90);
    servo_3.write(90);
    servo_4.write(90);
    servo_5.write(90);
    Serial.println("Calib Mode On!");
    Serial.println("Center Angle Value: 90");
  }
  else{
    servo_1.write(30);
    servo_2.write(150);
    servo_3.write(150);
    servo_4.write(30);
    servo_5.write(150);
  }

  Serial.println("Motor Setting Completed!");

  delay(1000);
  Serial.println("Robot Hand Run!");
}


void loop() {
  int isPushPressed = digitalRead(PUSH_PIN);
  if(!CALIB_MODE){
    if(isPushPressed){
      servo_1.write(30);
      servo_2.write(150);
      servo_3.write(150);
      servo_4.write(30);
      servo_5.write(150);
    }
    else{
      servo_1.write(150);
      servo_2.write(30);
      servo_3.write(30);
      servo_4.write(150);
      servo_5.write(30);
      Serial.println("Pressing!");
    }
  }
}

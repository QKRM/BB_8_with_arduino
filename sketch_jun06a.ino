#include <SoftwareSerial.h>

SoftwareSerial BTSerial(4, 5); // 소프트웨어 시리얼 (TX,RX)

int MotorA1 = 8;
int MotorA2 = 9;
int MotorB1 = 10;
int MotorB2 = 11;

void setup() {
  pinMode(MotorA1, OUTPUT);
  pinMode(MotorA2, OUTPUT);
  pinMode(MotorB1, OUTPUT);
  pinMode(MotorB2, OUTPUT);
  Serial.begin(9600);
  Serial.println("Hello!");
  BTSerial.begin(9600);
}

void loop() {
  char command = (char)BTSerial.read();
  if (command == 'f')
  {
    Serial.println('f');
    digitalWrite(MotorA1, HIGH);
    digitalWrite(MotorB1, HIGH);
    digitalWrite(MotorA2, LOW);
    digitalWrite(MotorB2, LOW);
  }
  else  if (command == 'b')
  {
    digitalWrite(MotorA2, HIGH);
    digitalWrite(MotorB2, HIGH);
    digitalWrite(MotorA1, LOW);
    digitalWrite(MotorB1, LOW);
  }
  else  if (command == 'l')
  {
    digitalWrite(MotorA1, HIGH);
    digitalWrite(MotorB2, HIGH);
    digitalWrite(MotorA2, LOW);
    digitalWrite(MotorB1, LOW);
  }
  else  if (command == 'r')
  {
    digitalWrite(MotorA2, HIGH);
    digitalWrite(MotorB1, HIGH);
    digitalWrite(MotorA1, LOW);
    digitalWrite(MotorB2, LOW);
  }
  else if (command == 's')
  {
    digitalWrite(MotorA1, HIGH);
    digitalWrite(MotorB1, HIGH);
    digitalWrite(MotorA2, HIGH);
    digitalWrite(MotorB2, HIGH);
  }
}

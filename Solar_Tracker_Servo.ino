#include <Servo.h>
Servo myServo;
int iRotationServo = 90;

int iPhotoValue1 = 0;
int myPin1 = A0;

int iPhotoValue2 = 0;
int myPin2 = A1;

void setup()
{
  Serial.begin(9600);
  myServo.attach(8);
  myServo.write(iRotationServo); // Rappel : iRotationServo = 90
  delay(500);
}

void loop()
{
  iPhotoValue1 = analogRead(myPin1); // Rappel : myPin1 = A0
  Serial.println("Valeur 1 : ");
  Serial.println(iPhotoValue1); // Affichage de ma valeur
  
  iPhotoValue2 = analogRead(myPin2); // Rappel : myPin2 = A1
  Serial.println("Valeur 2 : ");
  Serial.println(iPhotoValue2); // Affichage de ma valeur
  
  if (iPhotoValue1 > iPhotoValue2){
    while (analogRead(A0) > analogRead(A1)){
      myServo.write(iRotationServo++);
      delay(50);
    }
  } else if ( iPhotoValue1 < iPhotoValue2 ){
    while (analogRead(A0) < analogRead(A1)){
      myServo.write(iRotationServo--);
      delay(50);
    }
  }
  
  delay(500);
}

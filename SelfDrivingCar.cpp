#include <AFMotor.h>  
#include <Servo.h>    
#include <NewPing.h>
const int Trig_Pin =A0;
const int Echo_Pin =A1;
const int Max_Speed =200;
const int Max_Dist = 250;
NewPing ultra_sonic(Trig_Pin, Echo_Pin, Max_Dist);
AF_DCMotor motor1(1,MOTOR12_1KHZ);
AF_DCMotor motor2(2,MOTOR12_1KHZ);
AF_DCMotor motor3(3,MOTOR34_1KHZ);
AF_DCMotor motor4(4,MOTOR34_1KHZ);
Servo myservo;
int distance=250;
int speedSet=0;
boolean goesForward=false;
void setup() {
  myservo.attach(10);
  myservo.write(0);
  delay(2000);
  distance=readDistance();
  delay(100);
  moveForward();
}
void loop() {
  int dist_R = 0;
  int dist_L = 0;
  delay(100);
  if(distance<=25){
    moveStop();
    delay(100);
    moveBackward();
    delay(200);
    moveStop();
    delay(100);
    dist_R = right_Distance();
    delay(100);
    dist_L = left_Distance();
    delay(100);
    if(dist_R <= dist_L){
      turnLeft();
      moveStop();
    }else{
      turnRight();
      moveStop();
    }
  }else{
    moveForward();
  }
  distance = readDistance();
}
int left_Distance(){
  myservo.write(170);
  delay(500);
  int dist = readDistance();
  delay(100);
  myservo.write(90);
  return dist;
  delay(100); 
}
int right_Distance(){
   myservo.write(10);
  delay(500);
  int dist = readDistance();
  delay(100);
  myservo.write(90);
  return dist;
  delay(100);
}
int readDistance(){
  int cm = ultra_sonic.ping_cm();
  if(cm<=0){                       
   cm=250;
  }
 return cm;
}
void moveStop() {
  motor1.run(RELEASE); 
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  } 
void moveForward() {
 if(!goesForward){
    goesForward=true;
    motor1.run(FORWARD);      
    motor2.run(FORWARD);
    motor3.run(FORWARD); 
    motor4.run(FORWARD);     
   for (speedSet = 0; speedSet < Max_Speed; speedSet +=2){
    motor1.setSpeed(speedSet);
    motor2.setSpeed(speedSet);
    motor3.setSpeed(speedSet);
    motor4.setSpeed(speedSet);
    delay(5);
   }
  }
}
void moveBackward() {
    goesForward=false;
    motor1.run(BACKWARD);      
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);  
  for (speedSet = 0; speedSet < Max_Speed; speedSet +=2){
    motor1.setSpeed(speedSet);
    motor2.setSpeed(speedSet);
    motor3.setSpeed(speedSet);
    motor4.setSpeed(speedSet);
    delay(5);
  }
}
void turnRight() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);     
  delay(500);
  motor1.run(FORWARD);      
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD); 
}
void turnLeft() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);     
  delay(500);
  motor1.run(FORWARD);      
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD); 
}
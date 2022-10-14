// Black Line Follower 
int IR1=8;      //Right sensor
int IR2=9;    //left Sensor
// motor one
int enA = 3;    //Right motor
int MotorAip1=2;
int MotorBip1=4;
// motor two
int enB = 5;    //Left motor

void setup() 
{
  // put your setup code here, to run once:
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(IR1,INPUT);
  pinMode(IR2,INPUT);
  pinMode(MotorAip1,OUTPUT);
  pinMode(MotorBip1,OUTPUT);
}
void loop() 
{
   if(digitalRead(IR1)==HIGH && digitalRead(IR2)==HIGH) //IR will not glow on black line
  {
    //Stop both Motors
    digitalWrite(MotorAip1,LOW);
    digitalWrite(MotorBip1,LOW);
   analogWrite (enA, 0);
   analogWrite (enB, 0);
  }

  else if(digitalRead(IR1)==LOW && digitalRead(IR2)==LOW)  //IR not on black line
  {
    //Move both the Motors
    digitalWrite(MotorAip1,HIGH);
    digitalWrite(MotorBip1,HIGH);
    analogWrite (enA, 200);
    analogWrite (enB, 200);
  }

  else if(digitalRead(IR1)==LOW && digitalRead(IR2)==HIGH)
  {
    //Tilt robot towards left by stopping the left wheel and moving the right one
    digitalWrite(MotorAip1,HIGH);     
    digitalWrite(MotorBip1,LOW);
    analogWrite (enA, 200);
    analogWrite (enB, 0);
   delay(100);
  }

  else if(digitalRead(IR1)==HIGH && digitalRead(IR2)==LOW)
  {
    //Tilt robot towards right by stopping the right wheel and moving the left one
     digitalWrite(MotorAip1,LOW);     // If I want to turn right then the speed of the right wheel should be less than that of the left wheel, here, let a be the right wheel
     digitalWrite(MotorBip1,HIGH);
    analogWrite (enA, 0);
   analogWrite (enB, 200);
   delay(100);
  }

  else
  {
    //Stop both the motors
    digitalWrite(MotorAip1,LOW);
    digitalWrite(MotorBip1,LOW);
    analogWrite (enA, 0);
   analogWrite (enB, 0);
  }
}

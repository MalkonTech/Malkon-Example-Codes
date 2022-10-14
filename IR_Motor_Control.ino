#include <IRremote.h>
char t;
int echo = 10;
int trig= 11;
int en1 =3; 
int en2 =5;
int m1p1 =2; //IN1
int m1p2 =4; //IN2
long distance, duration;
int buzzer=12;
int IRpin = 8;
IRrecv irrecv(IRpin);
 decode_results results;

 long UP =16718055;
 long DOWN = 16730805;
 long LEFT =1253111735;
 long RIGHT = 904583189;
 long OK = 16726215;


void setup() {
pinMode(en1,OUTPUT);  
pinMode(en2,OUTPUT);  
pinMode(m1p1,OUTPUT);   
pinMode(m1p2,OUTPUT); 
pinMode(echo, INPUT);
pinMode(trig, OUTPUT);  
pinMode(buzzer, OUTPUT);   
Serial.begin(9600);
 irrecv.enableIRIn();

}

void loop() {
 //**************************REMOTE CODES*****************************
  // NB: THESE WILL DIFFER WITH DIFFERENT REMOTE SETS. YOU WILL PROBABLY HAVE TO MAP THE BUTTONS
   
  // UP: 16718055
  // DOWN: 16730805
  // LEFT: 1253111735
  // RIGHT: 904583189
  // OK:  16726215

  // 1: 16753245
  //2: 16736925
  //3: 16769565

   //**************************REMOTE CODES END*****************************

//*******************************CALCULATE DISTANCE*******************************//
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  duration=pulseIn(echo, HIGH, 100000); 
  distance=duration/58.2;

 Serial.println(distance);
  //delay(10);

//*******************************CALCULATE DISTANCE END*******************************//

 if(irrecv.decode(&results)){

  
  //int results.value = results;
  Serial.print("Code:");  
  Serial.println(results.value);


  
  if(results.value == UP){
    //Press Up button. Move forward(all motors rotate in forward direction) 
    
     analogWrite(en1, 150);
  analogWrite(en2, 150);
  digitalWrite(m1p1, LOW);
  digitalWrite(m1p2, LOW); // 
    }
    else if(results.value == DOWN) {
   digitalWrite(en1, 150);
  digitalWrite(en2, 150);
  digitalWrite(m1p1,HIGH);
  digitalWrite(m1p2,HIGH);
      }
      else if(results.value == LEFT) {
       analogWrite(en1,150);
  analogWrite(en2,0);
  digitalWrite(m1p1,LOW);
  digitalWrite(m1p2,HIGH);
    }
        else if(results.value == RIGHT) {
      analogWrite(en1,0);
  analogWrite(en2,150);
  digitalWrite(m1p1,HIGH);
  digitalWrite(m1p2,LOW);
    }
        else{
   analogWrite(en1,0);
  analogWrite(en2,0);
  digitalWrite(m1p1,LOW);
  digitalWrite(m1p2,LOW);
    }
    
    if(distance < 50){    //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
   digitalWrite(buzzer, HIGH);
} 
else
{
  digitalWrite(buzzer, LOW);
}
  irrecv.resume();

  
 }

}

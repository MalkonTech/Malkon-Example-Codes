//*********************CODE BY BRUTEFORCE ZW****************************
//MALKON SMARS STRESS TEST// MOTORS CODE*************************
#include <uptime.h>
#include <uptime_formatter.h>


int echo = 6;
int trig= 7;

int en1 =8; 
int en2 =5;
int m1p1 =2; //IN1
int m1p2 =4; //IN2
long distance, duration;
void setup() {
pinMode(en1,OUTPUT);  
pinMode(en2,OUTPUT);  
pinMode(m1p1,OUTPUT);   
pinMode(m1p2,OUTPUT); 
pinMode(echo, INPUT);
pinMode(trig, OUTPUT);  
Serial.begin(9600); 
}


void loop() {
uptime::calculateUptime();
  Serial.println("up " + uptime_formatter::getUptime());

analogWrite(en1, 150);
  analogWrite(en2, 150);
  digitalWrite(m1p1, HIGH);
  digitalWrite(m1p2, HIGH); // Move FORWARD
delay(100000);
  analogWrite(en1, 150);
  analogWrite(en2, 150);
  digitalWrite(m1p1, LOW);
  digitalWrite(m1p2, HIGH); // Turn LEFT
  delay(10000);
  analogWrite(en1, 150);
  analogWrite(en2, 0);
  digitalWrite(m1p1, HIGH);
  digitalWrite(m1p2, HIGH); // Move FORWARD
delay(100000);
  analogWrite(en1, 0);
  analogWrite(en2, 150);
  digitalWrite(m1p1, HIGH);
  digitalWrite(m1p2, LOW); // Turn LEFT
  delay(10000);
  analogWrite(en1, 150);
  analogWrite(en2, 150);
  digitalWrite(m1p1, LOW);
  digitalWrite(m1p2, LOW); // Move FORWARD
delay(100000);
  analogWrite(en1, 150);
  analogWrite(en2, 150);
  digitalWrite(m1p1, LOW);
  digitalWrite(m1p2, HIGH); // Turn LEFT
  delay(10000);
  analogWrite(en1, 150);
  analogWrite(en2, 0);
  digitalWrite(m1p1, HIGH);
  digitalWrite(m1p2, HIGH); // Move FORWARD
delay(100000);
  analogWrite(en1, 0);
  analogWrite(en2, 150);
  digitalWrite(m1p1, HIGH);
  digitalWrite(m1p2, LOW); // Turn LEFT
  delay(10000);
  
  



















/*

if(t == 'B'){            //move forward(all motors rotate in forward direction) 
  analogWrite(en1,155);
  analogWrite(en2,155);
  digitalWrite(m1p1,LOW);
  digitalWrite(m1p2,LOW);

} 
else if(t == 'F'){      //move reverse (all motors rotate in reverse direction)
    analogWrite(en1,155);
  analogWrite(en2,155);
  digitalWrite(m1p1,HIGH);
  digitalWrite(m1p2,HIGH);

}
else if(t == 'R'){      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
   analogWrite(en1,0);
  analogWrite(en2,155);
  digitalWrite(m1p1,LOW);
  digitalWrite(m1p2,HIGH);

}

else if(t == 'L'){    //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
   analogWrite(en1,155);
  analogWrite(en2,0);
  digitalWrite(m1p1,HIGH);
  digitalWrite(m1p2,LOW);

} 
else if(t == 'S'){      //STOP (all motors stop)
 analogWrite(en1,0);
  analogWrite(en2,0);
  digitalWrite(m1p1,LOW);
  digitalWrite(m1p2,LOW);

}*/

delay(10);
}

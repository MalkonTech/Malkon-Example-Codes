//*********************CODE BY BRUTEFORCE ZW****************************
//DC Motors will be controlled by an Android Application called Bluetooth RC Car (https://play.google.com/store/apps/details%3Fid%3Dbraulio.calle.bluetoothRCcontroller%26hl%3Den_US%26gl%3DUS&sa=U&ved=2ahUKEwjz0dDa8d72AhWuTDABHaqhDzcQFnoECAUQAg&usg=AOvVaw0TkDtiHC9b64huIKwZr69g)
//DC Motors will be connected to the Arduino Nano via L298N module. The motors will be controlled via the Bluetooth module (HC-06)
//The control character will be relayed to the Arduino via the Bluetooth module from the android app
#include <Servo.h>
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

#include <SoftwareSerial.h>
SoftwareSerial bt(7,6);

int pos = 0;

char t;
int echo = 10;
int trig= 11;

int en1 =3; 
int en2 =5;
int m1p1 =2;   //IN1
int m1p2 =4;   //IN2

long distance, duration;
long distVar = 20;

int buzzer=9;
int spd = 155;

int left=50;
int right=160;
int centre=120;

void setup() {
pinMode(en1,OUTPUT);  
pinMode(en2,OUTPUT);  
pinMode(m1p1,OUTPUT);   
pinMode(m1p2,OUTPUT); 
pinMode(echo, INPUT);
pinMode(trig, OUTPUT);  
pinMode(buzzer, OUTPUT);
myservo.attach(8);
myservo.write(centre);
digitalWrite(buzzer,LOW);
Serial.begin(9600); 
bt.begin(9600);
}


void loop() {

 
//*******************************CALCULATE DISTANCE*******************************//
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  duration=pulseIn(echo, HIGH); 
  distance=duration/58.2;

 Serial.println(distance);
  //delay(10);

//*******************************CALCULATE DISTANCE END*******************************//

if(bt.available()){
  bt.setTimeout(60); //Decrease the lag by avoiding the serial buffer over-fill
  
  t = bt.read();
  Serial.println(t);

//*******************************CHECK SPEED & HOOTER*******************************//
 switch(t)
 {
  case '0': 
  spd= 0;
  distVar = 20;
  break;
   case '1': 
  spd= 25;
   distVar = 20;
  break;
  case '2': 
  spd= 50;
   distVar = 20;
  break;
  case '3': 
  spd= 75;
   distVar = 20;
  break;
  case '4': 
  spd= 100;
   distVar = 20;
  break;
  case '5': 
  spd= 125;
   distVar = 20;
  break;
  case '6': 
  spd= 150;
   distVar = 25;
  break;
  case '7': 
  spd= 175;
   distVar = 35;
  break;
  case '8': 
  spd= 200;
   distVar = 45;
  break;
  case '9': 
  spd= 225;
   distVar = 55;
  break;
  case 'q': 
  spd= 254;
   distVar = 60;
  break;
  case 'V': 
  digitalWrite(buzzer,HIGH);
  break;
   case 'v': 
  digitalWrite(buzzer,LOW);
  break;
  default:
  goto HERE;
  
 } 
//******************************CHECK SPEED & HOOTER*******************************//
 
HERE:
if((t == 'F' && distance>distVar) ){            //move forward(all motors rotate in forward direction) 
  myservo.write(centre);
  analogWrite(en1,spd);
  analogWrite(en2,spd);
  digitalWrite(m1p1,LOW);
  digitalWrite(m1p2,LOW);

  goto SKIP;

} 
else if(t == 'B'){      //move reverse (all motors rotate in reverse direction)
  myservo.write(centre);
  analogWrite(en1,spd);
  analogWrite(en2,spd);
  digitalWrite(m1p1,HIGH);
  digitalWrite(m1p2,HIGH);
  goto SKIP;

}


else if(t == 'H'){     //BACKLEFT
  myservo.write(left); 
  analogWrite(en1,spd);
  analogWrite(en2,spd);
  digitalWrite(m1p1,HIGH);
  digitalWrite(m1p2,HIGH);  
  goto SKIP;

}

else if(t == 'J'){     //BACKRIGHT
  myservo.write(right); 
  analogWrite(en1,spd);
  analogWrite(en2,spd);
  digitalWrite(m1p1,HIGH);
  digitalWrite(m1p2,HIGH);  
  goto SKIP;

}

else if(t == 'G' && distance>distVar){     //FORWARDLEFT
  myservo.write(left); 
  analogWrite(en1,spd);
  analogWrite(en2,spd);
  digitalWrite(m1p1,0);
  digitalWrite(m1p2,0);  
  goto SKIP;

}

else if((t == 'I' && distance>distVar)){     //FORWARDRIGHT
  myservo.write(right); 
  analogWrite(en1,spd);
  analogWrite(en2,spd);
  digitalWrite(m1p1,0);
  digitalWrite(m1p2,0);  
  goto SKIP;

}

else if(t == 'L'){      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
    
    myservo.write(left);              // tell servo to go to position in variable 'pos'
    //delay(15);
   // t = 'X';
  
goto SKIP;
}

else if(t == 'R'){    //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  
    myservo.write(right);              // tell servo to go to position in variable 'pos'
    //delay(15);
   //t = 'X';
goto SKIP;
} 
else if(t == 'S'){      //STOP (all motors stop)
 analogWrite(en1,0);
  analogWrite(en2,0);
  digitalWrite(m1p1,LOW);
  digitalWrite(m1p2,LOW);

}
else {      //STOP (all motors stop)
 analogWrite(en1,0);
  analogWrite(en2,0);
  digitalWrite(m1p1,LOW);
  digitalWrite(m1p2,LOW);

}

//delay(10);
}

if(distance < distVar){    //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  tone(buzzer, 200);
} 
else
{
  noTone(buzzer);
}

SKIP:


Serial.println(spd);

}

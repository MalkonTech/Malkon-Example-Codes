#include <IRremote.h>
int IRpin = 8;
IRrecv irrecv(IRpin);
 decode_results results;
void setup() {
pinMode (2, OUTPUT);
pinMode (3, OUTPUT);
pinMode (4, OUTPUT); 
pinMode (5, OUTPUT); 
 Serial.begin(9600);
 irrecv.enableIRIn();
}
void loop() {
  // UP: 16718055
  // DOWN: 16730805
  // LEFT: 1253111735
  // RIGHT: 904583189
  // OK:  16726215
  // 1: 16753245
  //2: 16736925
  //3: 16769565
 if(irrecv.decode(&results)){
  Serial.print("Code:");  
  Serial.println(results.value);
  if(results.value == 16753245){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    
    }
    else if(results.value == 16736925) {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
      }
      else if(results.value == 16769565) {
          digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
     
    }
  irrecv.resume();
  
 }
}

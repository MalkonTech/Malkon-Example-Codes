#include <IRremote.h>
int RGB_RED = 9;
int RGB_GREEN = 10;
int RGB_YELLOW = 11;
int IRpin = 8;
IRrecv irrecv(IRpin);
 decode_results results;
void setup() {
  // put your setup code here, to run once:
pinMode (RGB_RED, OUTPUT);
pinMode (RGB_GREEN, OUTPUT);
pinMode (RGB_BLUE, OUTPUT); 
 Serial.begin(9600);
 irrecv.enableIRIn();
}
void loop() {
  // 1: 16753245
  //2: 16736925
  //3: 16769565
 if(irrecv.decode(&results)){
  Serial.print("Code:");  
  Serial.println(results.value);
   if(results.value == 16753245){
    digitalWrite(RGB_RED, HIGH);
    digitalWrite(RGB_GREEN, LOW);
    digitalWrite(RGB_BLUE, LOW);
    }
    else if(results.value == 16736925) {
       digitalWrite(RGB_RED, LOW);
    digitalWrite(RGB_GREEN, HIGH);
    digitalWrite(RGB_BLUE, LOW);
      }
      else if(results.value == 16769565) {
         digitalWrite(RGB_RED, LOW);
    digitalWrite(RGB_GREEN, LOW);
    digitalWrite(RGB_BLUE, HIGH);
    }
  irrecv.resume(); 
 }
}

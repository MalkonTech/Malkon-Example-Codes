#include <IRremote.h>
int IRpin = 8;
IRrecv irrecv(IRpin);
 decode_results results;
void setup() {
 pinMode(IRpin, INPUT); 
 Serial.begin(9600);
 irrecv.enableIRIn();

}
 

void loop() {
  
 if(irrecv.decode(&results)){

  //int results.value = results;
  Serial.print("Code:");  
  Serial.println(results.value);
  irrecv.resume();
  
 }

}

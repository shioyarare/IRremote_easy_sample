/*
 * IRremote version 3.0.0
 * Device ELEGOO UNO R3
 */
#include <IRremote.h>

#define IR_RECEIVE_PIN 11

void setup(){
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN);
}

void loop(){
  if(IrReceiver.decode()){
    if(IrReceiver.decodedIRData.flags & IRDATA_FLAGS_WAS_OVERFLOW){
      IrReceiver.decodedIRData.flags = false;
      Serial.println(F("Overflow detected"));
    }else{
      IRData recv_data = *IrReceiver.read();
      IrReceiver.resume(); // Enable receiving of the next value
      Serial.println("data");
      Serial.print("protocol: "); Serial.println( recv_data.protocol );
      Serial.print("address: "); Serial.println( recv_data.address );
      Serial.print("command: "); Serial.println( recv_data.command );
    }
  }
  delay(1000); // Accepting input every second
}

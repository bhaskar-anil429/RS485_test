byte command[8] = {0x01, 0x03, 0x10, 0x44, 0x00, 0x01,0xC0,0xDF};

unsigned long tOut = 1000;
unsigned long start;


void setup() {

    pinMode(19, OUTPUT); 
    digitalWrite(19, LOW); 
    delay(1000);
    Serial1.begin(57600); 
    Serial.begin(115200);
   
  
    delay(5000);

}

void loop() {
        
        Serial1.write(command, 8);
        char returnData[8];
        String postData;
        while(Serial1.available() != 0){
            byte in = Serial1.read();
            Serial.printf("%02X, ",in);
            sprintf(returnData, "%02X,", in);
            postData.concat(returnData);
        }
        Particle.publish("return data: ", postData);
        

    
       delay(3000);
}

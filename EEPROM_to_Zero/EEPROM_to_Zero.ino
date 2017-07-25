 #include <EEPROM.h> //EEPROM interface
 int addr = 0;
 float len;
 int pcComplete;

void setup() {

 Serial.begin (9600);
 Serial.println ("EEPROM Eraser");
 Serial.print("Size of EEPROM =");
 len = EEPROM.length();
 Serial.print (len);
 Serial.println (" bytes");
 delay (1000);
 pinMode(13, OUTPUT);
 }



void loop() {
 EEPROM.write (addr,0);
 Serial.print (addr);
 Serial.print ("  ");
 pcComplete = (addr / len)*100;
 Serial.print (pcComplete);
 Serial.println ("%");
 addr ++;
 if (addr == len+1){
  addr = 0;
  Serial.println ("Complete");
  blinkPin();
  
 }
 }

 void blinkPin () {
  while (1) {
  digitalWrite(13, HIGH);  
  delay(1000);             
  digitalWrite(13, LOW);   
  delay(1000);             
  }
 }

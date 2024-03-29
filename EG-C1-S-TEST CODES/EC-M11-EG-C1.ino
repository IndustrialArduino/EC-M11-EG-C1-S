// EC-M11-EG-C1
/*
 * Digital Input Test
 * RS-485 Serial print
 * 12V Booster Enable / Disable
 * 
 */

#include <Adafruit_ADS1015.h>

Adafruit_ADS1115 ads1(0x49);
String adcString[8];


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial1.begin(9600);
  Wire.begin(16,17);

  Serial.println("The device is powered up");
  
  pinMode(35, INPUT);    // Digital Input 1
  pinMode(34, INPUT);    // Digital Input 2

  pinMode(21, INPUT);    // ADS1115 Interrupt
    
  pinMode(13, OUTPUT);    // RS-485 flow control
  
  digitalWrite(13, HIGH);
  
  ads1.begin();
  ads1.setGain(GAIN_ONE);

  Serial.println("Initialized analog inputs");

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("I1: ");Serial.println(digitalRead(35));
  Serial.print("I2: ");Serial.println(digitalRead(34));
  delay(800);
  printanalog();
  delay(800);
  Serial1.println("RS-485 TX TEST");
}

void printanalog(){
  adcString[0] = String(ads1.readADC_SingleEnded(0));
  adcString[0] = String(ads1.readADC_SingleEnded(0));
  delay(10);
  adcString[1] = String(ads1.readADC_SingleEnded(1));
  adcString[1] = String(ads1.readADC_SingleEnded(1));
  delay(10);
  adcString[2] = String(ads1.readADC_SingleEnded(2));
  adcString[2] = String(ads1.readADC_SingleEnded(2));
  delay(10);
  adcString[3] = String(ads1.readADC_SingleEnded(3));
  adcString[3] = String(ads1.readADC_SingleEnded(3));
  delay(10);
  Serial.print("A1: ");Serial.print(adcString[0]);Serial.print("  ");
  Serial.print("A2: ");Serial.println(adcString[1]);
  Serial.print("A3: ");Serial.print(adcString[2]);Serial.print("  ");
  Serial.print("A4: ");Serial.println(adcString[3]);

  Serial.println("____________________________________"); 
}

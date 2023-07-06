
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd (0x27, 16, 2);

void setup() {
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  Serial.begin(9600);

}

void loop() {
  float adc1=analogRead(A0);
  float adc2=analogRead(A1);
  
  float tegangan1 = adc1*5/1023;
  float tegangan2 = adc2*5/1023;

  float suhu1 = tegangan1*100;
  float suhu2 = tegangan2*100;

  float suhu = suhu1-suhu2;

  Serial.println(suhu); 
  
  lcd.setCursor(0,0);
  lcd.print("Suhu:");
  lcd.setCursor(7,0);
  lcd.print(suhu);

}

#include <LiquidCrystal.h>

//Moisture sensor
  #define Analogin0 A0
  #define Analogin1 A1
  #define Analogin2 A2
  #define Analogin3 A3

//Pump
const int Pump = LED_BUILTIN;
// or #define Pump 13

//LCD
  const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
  LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() {
//Pump
  pinMode(13, OUTPUT);     //set pin#13 as output
  digitalWrite(13, LOW);
//  digitalWrite(13, HIGH);
  
//moisture sensor
  pinMode(Analogin0, INPUT);
  pinMode(Analogin1, INPUT);
  pinMode(Analogin2, INPUT);
  pinMode(Analogin3, INPUT);
  
//LCD  
  lcd.begin(16, 2); //(no. of character, no. rows) 
  lcd.clear(); 

  lcd.clear();
  lcd.setCursor(2, 0); //(character, row)
  lcd.print("Project by");
  lcd.setCursor(5, 1);
  lcd.print("Brats");
  delay(3000); 

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Please Turn On");
  lcd.setCursor(0, 1);
  lcd.print("The Pump");
  delay(5000);

    Serial.begin(9600);
}

void loop() {
  int Ain0 = analogRead(Analogin0); //Read Moisture Sensor Value 
  int Ain1 = analogRead(Analogin1); 
  int Ain2 = analogRead(Analogin2); 
  int Ain3 = analogRead(Analogin3); 
  
  lcd.clear();

if (Ain0> 700 && Ain1> 700 && Ain2> 700 && Ain3> 700)   // for dry soil
  { 
        lcd.setCursor(3, 0);
        lcd.print("DRY SOIL");

        digitalWrite(13, LOW);
        lcd.setCursor(4, 1);
        lcd.print("PUMP:ON");
  }

 
     
if (Ain0<= 700 && Ain1<= 700 && Ain2<= 700 && Ain3<= 700) //for Moist Soil
  {
      lcd.setCursor(2, 0);
      lcd.print("MOIST SOIL");

      digitalWrite(13, HIGH);
      lcd.setCursor(3, 1);
      lcd.print("PUMP:OFF");  
  }

  delay(500);

}

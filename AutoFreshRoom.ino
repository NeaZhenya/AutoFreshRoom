#define analogPin A0
#include <LiquidCrystal.h>
//#define digitalPin 3
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

byte ena = 6;
byte in1 = 7;
byte in2 = 10;
bool n = 0;

const int LED1 = 9;
const int LED2 = 8;

float analogValue;
//bool digitalValue;

void setup() {
  Serial.begin(115200);

  pinMode( ena, OUTPUT );
  pinMode( in1, OUTPUT );
  pinMode( in2, OUTPUT );

  pinMode (LED1, OUTPUT);
  pinMode (LED2, OUTPUT);

  lcd.begin(16, 2);

  pinMode(analogPin, INPUT);
  //  pinMode(digitalPin, INPUT);
  delay(1000);
}

void loop() {
  // выставляем 100% мощность на моторе А - 255 из 255
  analogWrite( ena, 255 );
  analogValue = analogRead(analogPin);
  if (analogValue > 350 )
  {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Too much");
    if(n==0)
    {
      Serial.println("Provetrivanie ON");
      n=1;
    }
    
    digitalWrite( in1, HIGH );
    digitalWrite( in2, LOW );
  }
  if (analogValue < 280 )
  {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("It is OK");
    if(n==1)
    {
      Serial.println("Provetrivanie OFF");
      n=0;
    }
    digitalWrite( in1, LOW );
    digitalWrite( in2, LOW );
  }
  lcd.setCursor(0, 0);
  lcd.print("CO2:");
  lcd.setCursor(4, 0);
  lcd.print(analogValue);
  delay(1000);


}

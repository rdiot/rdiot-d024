/* Bargraph Segment LED Module (SHB10R) [D024] : http://rdiot.tistory.com/203 [RDIoT Demo] */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
 
LiquidCrystal_I2C lcd(0x27,20,4);  // LCD2004
 
int segPins[] = { 2,3,4,5,6,7,8,9,10,11 };
int idxBar = 0;
int minVal = 50;
int maxVal = 350;
int delayTime = 200;
 
byte digitsFill[10][10] = {
  {1,0,0,0,0,0,0,0,0,0},
  {1,1,0,0,0,0,0,0,0,0},
  {1,1,1,0,0,0,0,0,0,0},
  {1,1,1,1,0,0,0,0,0,0},
  {1,1,1,1,1,0,0,0,0,0},
  {1,1,1,1,1,1,0,0,0,0},
  {1,1,1,1,1,1,1,0,0,0},
  {1,1,1,1,1,1,1,1,0,0},
  {1,1,1,1,1,1,1,1,1,0},
  {1,1,1,1,1,1,1,1,1,1}
};
 
void setup()
{
  lcd.init();  // initialize the lcd 
  lcd.backlight();
  lcd.print("start LCD2004");
 
  for (int i=0; i<11; i++)
  {
    pinMode(segPins[i], OUTPUT);
  }
 
  delay(1000);
 
  lcd.clear();
}
 
void loop()
{
  lcd.setCursor(0,0);
  lcd.print("D024:Bargraph LED");
 
  idxBar = map(analogRead(A0), minVal, maxVal, 0, 9);
 
  lcd.setCursor(0,1);
  lcd.print("analog=" + (String)analogRead(A0) + "  ");
 
  for(int j=0; j<10; j++)
  {
    digitalWrite(segPins[j], digitsFill[idxBar][j]);
 
    lcd.setCursor(0,2);
    lcd.print("idxBar="+(String)idxBar+" "); 
  }
   delay(delayTime);
}

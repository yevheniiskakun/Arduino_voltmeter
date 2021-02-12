#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

float input_voltage = 0.0;
int analog_value;

void setup()
{
 lcd.init();                      // initialize the lcd 
 // Print a message to the LCD.
 lcd.backlight();
 lcd.print("Voltmeter");
 delay(1000);
}
void loop()
{
  analog_value = analogRead(A0);
  input_voltage = (analog_value * 5.0) / 1024.0; 

   
   if (input_voltage < 0.1) 
   {
     input_voltage=0.0;
   } 
    
    lcd.setCursor(0, 1);
    lcd.print("Voltage = ");
    lcd.print(input_voltage);
    delay(300);
}

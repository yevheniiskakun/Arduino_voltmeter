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
 lcd.print("Hello there");
 delay(3000);
 lcd.clear();
}
void loop()
{
  analog_value = analogRead(A0);
  // The number of analog-to-digital converter bits is the amount of bits that make up an ADC reading. 
  // For example, a particular ADC may hold 10 bits. That means that when it converts an analog value to a digital value, it stores it in 10 bits.
  input_voltage = (analog_value * 5.0) / 1024.0; 

   
   if (input_voltage < 0.1) 
   {
     input_voltage = 0.0;
   } 
    lcd.setCursor(0, 0);
    lcd.print("Voltmeter");
    lcd.setCursor(0, 1);
    lcd.print("Voltage = ");
    lcd.print(input_voltage);
    delay(300);
}

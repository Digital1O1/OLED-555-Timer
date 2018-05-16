#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_ADDR   0x3C

Adafruit_SSD1306 display(-1);  // -1 = no reset pin

int sensorValue = analogRead(A7);
int led_Pin = 2;

void setup() 
{
  pinMode(led_Pin , INPUT);
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
  display.display();
  Serial.begin(9600);
}

void loop() 
{
  sensorValue = analogRead(A7);
  sensorValue = (sensorValue/(2^10));                 //ADC conversion for capacitor
  //Serial.println(sensorValue);
  delay(10);

 DisplayCapacitor();
 DisplayLED();
}

void led_Display()
{
  int led_State = digitalRead(led_Pin);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(2,20);
    if(led_State == LOW)
    {
      display.print("LED Status = OFF");
      display.fillRect(80,19,19,10,BLACK);
      display.display();
    }
    else
    {
      display.print("LED Status = ON");
      display.fillRect(80,19,19,10,BLACK);
      display.display();
    }
    //Serial.println(led_State);
}

void DisplayCapacitor()
{
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(2,10);
  display.print("Capacitor Value = ");
  display.fillRect(110,9,30,10,BLACK);                //THIS FIXES THE REFRESHING PROBLEM YOU'VE HAD
  display.println(sensorValue);
  display.display();
  //display.clearDisplay();
}
void DisplayLED()
{
  int led_State = digitalRead(led_Pin);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(2,20);
  display.print("LED Status = ");
  display.fillRect(80,19,25,10,BLACK);                // X,Y,width,height
    if(led_State == HIGH)
    {
      display.println(" ON ");
    }
    else
    {
      display.println(" OFF ");
    }
  display.display();
 }

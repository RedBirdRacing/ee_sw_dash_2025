#include <LiquidCrystal_I2C.h>

#include <SPI.h>

#include <can.h>
#include <mcp2515.h>

#include <SoftwareSerial.h>

#include "pinMap.h"
#include "can_msg.h"

MCP2515 can0(CAN0_CS);
LiquidCrystal_I2C lcd(0x27,20,4);

//update ticks
uint32_t lastLcdTick = 0;


void setup() {
  // put your setup code here, to run once:

  can0.reset();
  can0.setBitrate(CAN_500KBPS,MCP_20MHZ);
  can0.setNormalMode();

  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Nigger");

  pinMode(HC12_SET,OUTPUT);
  digitalWrite(HC12_SET,LOW);

  Serial.begin(9600);
  Serial.println("AT+C069");

  digitalWrite(HC12_SET,HIGH);
}

void loop() {
    uint32_t tick = millis();

    if(tick - lastLcdTick >= 100) {
        lastLcdTick = tick;
        
        //update lcd
    }


    can_frame rx_msg;
    if(can0.readMessage(&rx_msg) == MCP2515::ERROR_OK) {
        //
    }
}

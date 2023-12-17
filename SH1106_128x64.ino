/*
 * This is a modified code of the original code whose author is silas parker
 */






#include<U8g2lib.h>
#include<Wire.h>
#define PACKET_SYNC 0xFF
#define PACKET_VER  2

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

// icons for the ui
static const unsigned char left_ind[] U8X8_PROGMEM = {0x08,0x00,0x0c,0x00,0xfe,0x01,0xff,0x01,0xfe,0x01,0x0c,0x00,0x08,0x00};
static const unsigned char right_ind[] U8X8_PROGMEM = {0x20,0x00,0x60,0x00,0xff,0x00,0xff,0x01,0xff,0x00,0x60,0x00,0x20,0x00};
static const unsigned char fuel_warning[] U8X8_PROGMEM = {0x10,0x00,0x38,0x00,0x28,0x00,0x6c,0x00,0x6c,0x00,0xfe,0x00,0xee,0x00,0xff,0x01};
static const unsigned char parking_break_warning[] U8X8_PROGMEM = {0x7c,0x00,0x82,0x00,0x39,0x01,0x7d,0x01,0x7d,0x01,0x7d,0x01,0x39,0x01,0x82,0x00,0x7c,0x00};

int serial_byte;

struct truck_data
{
  int speedd,RPM,fuel;
  bool left,right,fuel_warn,parkbreak;
  
};


struct truck_data data;


void setup()
{
  Serial.begin(115200);
  u8g2.begin();
  u8g2.setBitmapMode(1);
  u8g2.setFontMode(1);
  u8g2.clearBuffer();
  u8g2.setBitmapMode(1);
  
  u8g2.setFont(u8g2_font_profont22_tr);
  u8g2.setCursor(10, 34);
  u8g2.print("Starting");
  u8g2.sendBuffer();
  delay(1500);
  u8g2.clearBuffer();
  
  
  
}

void skip_serial_byte()
{
  (void)Serial.read();
}

void loop()
{
  if (Serial.available() < 16)
    return;

  serial_byte = Serial.read();
  if (serial_byte != PACKET_SYNC)
    return;
    
  serial_byte = Serial.read();
  if (serial_byte != PACKET_VER)
  {
    u8g2.clearBuffer();
    u8g2.setFontMode(1);
    u8g2.setFont(u8g2_font_profont22_tr);
    u8g2.drawStr(0, 36, "ERROR");
    u8g2.sendBuffer();
    return;
  }
   

  /* 
   *  I'm using structure to store this data as we may pass variables to  different 
   *  function there by calling by reference which saves space 
   *  bit      channel
   *  1    speed
   *  2   rpm 
   *  3 break air press
   *  4 break temp 
   *  5 fuel ratio
   *  6 oil pressure
   *  7 oil temp
   *  8 water temp
   *  9 battery vol
   *  10  left indication
   *  11 right indication 
   *  12 parrking break 
   *  13 fuel warning 
   *  
   *  
  */
  
  u8g2.clearBuffer();
  //u8g2.drawFrame(1, 1, 126, 62);
  data.speedd=Serial.read();
  u8g2.setFont(u8g2_font_logisoso62_tn);
  u8g2.setCursor(0,64);
  u8g2.print(data.speedd);
  


  
  



  skip_serial_byte();
  skip_serial_byte();
  skip_serial_byte();


  
  // fuel ratio code here 
  //data.fuel=Serial.read();
  

  
  skip_serial_byte();
  skip_serial_byte();
  skip_serial_byte();
  skip_serial_byte();


  
  // left ind code
  //data.left=Serial.read(); 
  //u8g2.setFont(u8g2_font_profont22_tr);
  //u8g2.setCursor(4, 59);
 // u8g2.print(data.left);



  
  //right idi code
  //data.right=Serial.read(); 


  
  //parking break
  //data.parkbreak=Serial.read();


  
  //fuel warning
  //data.fuel_warn=Serial.read();




  
  skip_serial_byte();
  skip_serial_byte();
  skip_serial_byte();
  
  
  
    
  
  u8g2.sendBuffer();
  
  


}

/*
    This is a demo to test Grove - Mini_Track_Ball

*/
#include "MiniTrackball.h"
#include "Wire.h"


MTB MiniTrackball = MTB();

void test_PrintTrackData(void)
{
  for(int i=0;i<500;i++)
  {
    Serial.print(MiniTrackball.ReadByte(MOTION_REG_UP));
    Serial.print("-");
    Serial.print(MiniTrackball.ReadByte(MOTION_REG_DOWN));
    Serial.print("-");
    Serial.print(MiniTrackball.ReadByte(MOTION_REG_LEFT));
    Serial.print("-");
    Serial.print(MiniTrackball.ReadByte(MOTION_REG_RIGHT));
    Serial.print("-");
    Serial.println(MiniTrackball.ReadByte(MOTION_REG_CONFIRM));
    delay(100);
  }
}


void test_WriteReg(void)
{ 
  unsigned char tmp[8]={0};
  tmp[0] = 0X4A;
  MiniTrackball.WriteByte(CONFIG_REG_I2C_ADDR ,tmp[0]);
  delay(100);
  tmp[0] = 0X64;
  tmp[1] = 0X00;
  MiniTrackball.WriteByte(CONFIG_REG_I2C_SPEED ,tmp[0]);
  MiniTrackball.WriteByte(CONFIG_REG_I2C_SPEED+1 ,tmp[1]);
  delay(100);
  tmp[0] = 10;
  MiniTrackball.WriteByte(CONFIG_REG_LED_MODE ,tmp[0]);
  delay(100);
  tmp[0] = 0xc8;
  tmp[1] = 0x00;
  MiniTrackball.WriteByte(CONFIG_REG_LED_FLASH_TIME ,tmp[0]);
  MiniTrackball.WriteByte(CONFIG_REG_LED_FLASH_TIME+1 ,tmp[1]);
  delay(100);
  tmp[0] = 0XEA;
  tmp[1] = 0X14;
  MiniTrackball.WriteByte(CONFIG_REG_DATA_CLEAR_TIME ,tmp[0]);
  MiniTrackball.WriteByte(CONFIG_REG_DATA_CLEAR_TIME+1 ,tmp[1]);
  delay(100);
  tmp[0] = 0X22;
  tmp[1] = 0X05;
  MiniTrackball.WriteByte(CONFIG_REG_DATA_READ_TIME ,tmp[0]);
  MiniTrackball.WriteByte(CONFIG_REG_DATA_READ_TIME+1 ,tmp[1]);
  delay(1000);
  Serial.println("Setted Value are over here");
  Serial.print("valid:0x");Serial.print(MiniTrackball.ReadByte(CONFIG_REG_VALID+3),HEX);Serial.print(MiniTrackball.ReadByte(CONFIG_REG_VALID+2),HEX);Serial.print(MiniTrackball.ReadByte(CONFIG_REG_VALID+1),HEX);Serial.println(MiniTrackball.ReadByte(CONFIG_REG_VALID+0),HEX);
  Serial.print("I2C_ADDR:0x");Serial.println(MiniTrackball.ReadByte(CONFIG_REG_I2C_ADDR+0),HEX);
  Serial.print("I2C_SPEED:0x");Serial.print(MiniTrackball.ReadByte(CONFIG_REG_I2C_SPEED+1),HEX);Serial.println(MiniTrackball.ReadByte(CONFIG_REG_I2C_SPEED+0),HEX);
  Serial.print("LED_MODE:0x");Serial.println(MiniTrackball.ReadByte(CONFIG_REG_LED_MODE+0),HEX);
  Serial.print("LED_FLASH_TIME:0x");Serial.print(MiniTrackball.ReadByte(CONFIG_REG_LED_FLASH_TIME+1),HEX);Serial.println(MiniTrackball.ReadByte(CONFIG_REG_LED_FLASH_TIME+0),HEX);
  Serial.print("DATA_CLEAR_TIME:0x");Serial.print(MiniTrackball.ReadByte(CONFIG_REG_DATA_CLEAR_TIME+1),HEX);Serial.println(MiniTrackball.ReadByte(CONFIG_REG_DATA_CLEAR_TIME+0),HEX);
  Serial.print("DATA_READ_TIME:0x");Serial.print(MiniTrackball.ReadByte(CONFIG_REG_DATA_READ_TIME+1),HEX);Serial.println(MiniTrackball.ReadByte(CONFIG_REG_DATA_READ_TIME+0),HEX);
  Serial.println();Serial.println();Serial.println();
  delay(3000);
  
}



void test_SetLedMode(void)
 {
	for(int i=0;i<LED_MODE_NUM;i++)
	{
      MiniTrackball.SetLedMode((enum LED_MODE)i);
	  delay(5000);
	}
 }

void test_SetDefault(void)
{ 
  Serial.println("Setting Default Value");
 
  MiniTrackball.SetDefault();
  Serial.println("Default Value are over here");
  Serial.print("valid:0x");Serial.print(MiniTrackball.ReadByte(CONFIG_REG_VALID+3),HEX);Serial.print(MiniTrackball.ReadByte(CONFIG_REG_VALID+2),HEX);Serial.print(MiniTrackball.ReadByte(CONFIG_REG_VALID+1),HEX);Serial.println(MiniTrackball.ReadByte(CONFIG_REG_VALID+0),HEX);
  Serial.print("I2C_ADDR:0x");Serial.println(MiniTrackball.ReadByte(CONFIG_REG_I2C_ADDR+0),HEX);
  Serial.print("I2C_SPEED:0x");Serial.print(MiniTrackball.ReadByte(CONFIG_REG_I2C_SPEED+1),HEX);Serial.println(MiniTrackball.ReadByte(CONFIG_REG_I2C_SPEED+0),HEX);
  Serial.print("LED_MODE:0x");Serial.println(MiniTrackball.ReadByte(CONFIG_REG_LED_MODE+0),HEX);
  Serial.print("LED_FLASH_TIME:0x");Serial.print(MiniTrackball.ReadByte(CONFIG_REG_LED_FLASH_TIME+1),HEX);Serial.println(MiniTrackball.ReadByte(CONFIG_REG_LED_FLASH_TIME+0),HEX);
  Serial.print("DATA_CLEAR_TIME:0x");Serial.print(MiniTrackball.ReadByte(CONFIG_REG_DATA_CLEAR_TIME+1),HEX);Serial.println(MiniTrackball.ReadByte(CONFIG_REG_DATA_CLEAR_TIME+0),HEX);
  Serial.print("DATA_READ_TIME:0x");Serial.print(MiniTrackball.ReadByte(CONFIG_REG_DATA_READ_TIME+1),HEX);Serial.println(MiniTrackball.ReadByte(CONFIG_REG_DATA_READ_TIME+0),HEX);
  Serial.println();Serial.println();Serial.println();
  delay(3000);
}

void setup() {
 
 Wire.begin();
 Serial.begin(115200);
}

void loop() {

 test_SetLedMode();

 test_PrintTrackData();

 test_WriteReg();  

 test_SetDefault();
 
 delay(3000);
}


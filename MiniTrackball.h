#ifndef _MINITRACKBALL_H_
#define _MINITRACKBALL_H_

#include "arduino.h"

/*---------------------------------------------------------------------------------------//
 * define the default data
 */
#define ReadMode 0
#define WriteMode 1
#define DeAddr 0X4A
#define ConfigValid 0x3a6fb67c

/*---------------------------------------------------------------------------------------//
 * define the enum type for Register
 */
enum MOTION_REG_ADDR
{
  MOTION_REG_UP = 0X00,
  MOTION_REG_DOWN,
  MOTION_REG_LEFT,
  MOTION_REG_RIGHT,
  MOTION_REG_CONFIRM,
  MOTION_REG_NUM
};

enum CONFIG_REG_ADDR
{
  CONFIG_REG_VALID = MOTION_REG_NUM,
  CONFIG_REG_I2C_ADDR = CONFIG_REG_VALID + 4,
  CONFIG_REG_I2C_SPEED,
  CONFIG_REG_LED_MODE = CONFIG_REG_I2C_SPEED + 2,
  CONFIG_REG_LED_FLASH_TIME,
  CONFIG_REG_DATA_CLEAR_TIME = CONFIG_REG_LED_FLASH_TIME + 2,  //CONFIG_REG_LED_FLASH_TIME has 2bytes
  CONFIG_REG_DATA_READ_TIME = CONFIG_REG_DATA_CLEAR_TIME + 2,
  CONFIG_REG_NUM = CONFIG_REG_DATA_READ_TIME + 2
};


/*---------------------------------------------------------------------------------------//
 * define the LED word mode
 */
enum LED_MODE
{
  LED_FLASH_1 = 0X00,
  LED_FLASH_2,
  LED_FLASH_TOGGLE,
  LED_FLASH_ALL,
  LED_ALWAYS_ON_1,
  LED_ALWAYS_ON_2, 
  LED_ALWAYS_ON_ALL,
  LED_ALWAYS_OFF,
  LED_BREATHING_1,
  LED_BREATHING_2,
  LED_BREATHING_ALL,
  LED_MOVE_FLASH,
  LED_MODE_NUM
};



class MTB
{
  public:
  
  void WriteByte(uint8_t Reg, uint8_t Value);
  void WriteNByte(uint8_t Reg , uint8_t * Value , uint8_t len);
  void WriteOneWord(uint8_t Reg, uint32_t Value);
  void WriteHalfWord(uint8_t Reg, uint16_t Value);
  
  uint8_t ReadByte(uint8_t Reg);
  uint16_t ReadHalfWord(uint8_t Reg);
  uint32_t ReadOneWord(uint8_t Reg);
  
  void SetLedMode(uint8_t LED_MODE);
  
  void SetDefault(void);
  
  void GetTrackData(uint8_t data[]);
  
  void test_SetLedMode(void);
  void test_WriteReg(void);
  void test_SetDefault(void);
  
  private:
  
};



#endif




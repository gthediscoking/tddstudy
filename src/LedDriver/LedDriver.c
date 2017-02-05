#include "LedDriver.h"

// Internal variables and functions
static uint16_t * ledsAddress;	// LED操作用
static uint16_t ledsImage;		// LED状態記憶用
enum{
	ALL_LEDS_ON  = 0xffff,		// "~0"ではコンパイル・エラー
	ALL_LEDS_OFF = 0x0000		// ~(ALL_LEDS_ON)ではコンパイル・エラー
};

static uint16_t convertLedNumberToBit(int ledNumber);
static void updateHardware(void);

// Implementation of functions
void LedDriver_Create(uint16_t * address)
{
//	*address = 0;	// hard coat
	ledsAddress = address;		// アドレスを設定
	ledsImage = ALL_LEDS_OFF;	// LED状態を全てOFF
	updateHardware();			// LEDに状態反映
}

void LedDriver_Destroy(void)
{
}

void LedDriver_TurnOn(int ledNumber)
{
//	*ledsAddress = 1;	// hard coat
	ledsImage |= convertLedNumberToBit(ledNumber);	//LED制御レジスタに対するbit	操作
	updateHardware();
}

void LedDriver_TurnAllOn(void)
{
	ledsImage = ALL_LEDS_ON;	// LEDを全てON
	updateHardware();
}

void LedDriver_TurnOff(int ledNumber)
{
//	*ledsAddress = 0;	// hard coat
	ledsImage &= ~(convertLedNumberToBit(ledNumber));	//LED制御レジスタに対するbit	操作
	updateHardware();
}

static uint16_t convertLedNumberToBit(int ledNumber)
{
	// int型引数を16bit値に変換して返す
	return (uint16_t)(1 << (ledNumber-1));
}

static void updateHardware(void)
{
	*ledsAddress = ledsImage;
}

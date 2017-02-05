#include "LedDriver.h"

// internal variables and functions
static uint16_t * ledsAddress;
static uint16_t convertLedNumberToBit(int ledNumber);

void LedDriver_Create(uint16_t * address)
{
//	*address = 0;	// hard coat
	ledsAddress = address;	// アドレスを設定
	*ledsAddress = 0;		// LEDを全てOFF
}

void LedDriver_Destroy(void)
{
}

void LedDriver_TurnOn(int ledNumber)
{
//	*ledsAddress = 1;	// hard coat
	*ledsAddress |= convertLedNumberToBit(ledNumber);	//LED制御レジスタに対するbit	操作
}

void LedDriver_TurnOff(int ledNumber)
{
//	*ledsAddress = 0;	// hard coat
	*ledsAddress &= ~(convertLedNumberToBit(ledNumber));	//LED制御レジスタに対するbit	操作
}

static uint16_t convertLedNumberToBit(int ledNumber)
{
	// int型引数を16bit値に変換して返す
	return (uint16_t)(1 << (ledNumber-1));
}

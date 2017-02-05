#include "LedDriver.h"

static uint16_t * ledsAddress;
void LedDriver_Create(uint16_t * address)
{
//	*address = 0;
	ledsAddress = address;	// アドレスを設定
	*ledsAddress = 0;		// LEDを全てOFF
}

void LedDriver_Destroy(void)
{
}

void LedDriver_TurnOn(int ledNumber)
{
	*ledsAddress |= 1 << (ledNumber-1);
}

void LedDriver_TurnOff(int ledNumber)
{
//	*ledsAddress = 0;
	*ledsAddress &= ~(1 << (ledNumber-1));
}

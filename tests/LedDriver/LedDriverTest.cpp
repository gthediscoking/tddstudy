extern "C"
{
#include "LedDriver.h"
}

#include "CppUTest/TestHarness.h"

static uint16_t virtualLeds;

TEST_GROUP(LedDriver)
{
    void setup()
    {
//      LedDriver_Create();
    	LedDriver_Create(&virtualLeds);
    }

    void teardown()
    {
       LedDriver_Destroy();
    }
};

TEST(LedDriver, LedsOffAfterCreate)
{
//  FAIL("Start here");
//	uint16_t virtualLeds = 0xffff;
	virtualLeds = 0xffff;
	LedDriver_Create(&virtualLeds);
	LONGS_EQUAL(0, virtualLeds);
}

TEST(LedDriver, TurnOnLedOne)
{
//	uint16_t virtualLeds = 0xffff;
//	LedDriver_Create(&virtualLeds);
	LedDriver_TurnOn(1);
	LONGS_EQUAL(1, virtualLeds);
}

TEST(LedDriver, TurnOffLedOne)
{
//	uint16_t virtualLeds = 0xffff;
//	LedDriver_Create(&virtualLeds);
	LedDriver_TurnOn(1);
	LedDriver_TurnOff(1);
	LONGS_EQUAL(0, virtualLeds);
}

TEST(LedDriver, TurnOnMultipleLeds)
{
	LedDriver_TurnOn(9);
	LedDriver_TurnOn(8);
	LONGS_EQUAL(0x180, virtualLeds);
}

TEST(LedDriver, TurnAllOn)
{
	LedDriver_TurnAllOn();
	LONGS_EQUAL(0xffff, virtualLeds);
}

TEST(LedDriver, TurnOffAnyLed)
{
	LedDriver_TurnAllOn();
	LedDriver_TurnOff(8);
	LONGS_EQUAL(0xff7f, virtualLeds);
}

TEST(LedDriver, LedMemoryIsNotReadable)
{
	virtualLeds = 0xffff;
	LedDriver_TurnOn(8);
	LONGS_EQUAL(0x80, virtualLeds);
}


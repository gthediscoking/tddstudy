extern "C"
{
#include "LedDriver.h"
}

#include "/usr/local/cpputest/include/CppUTest/TestHarness.h"

TEST_GROUP(LedDriver)
{
    void setup()
    {
//      LedDriver_Create();
    }

    void teardown()
    {
       LedDriver_Destroy();
    }
};

TEST(LedDriver, Create)
{
//  FAIL("Start here");
}

TEST(LedDriver, LedsOffAfterCreate)
{
	uint16_t virtualLeds = 0xffff;
	LedDriver_Create(&virtualLeds);
//	TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
	LONGS_EQUAL(0, virtualLeds);
}

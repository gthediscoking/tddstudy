#include "CppUTest/TestHarness.h"
#include "tddstudyBuildTime.h"

TEST_GROUP(tddstudyBuildTime)
{
  tddstudyBuildTime* projectBuildTime;

  void setup()
  {
    projectBuildTime = new tddstudyBuildTime();
  }
  void teardown()
  {
    delete projectBuildTime;
  }
};

TEST(tddstudyBuildTime, Create)
{
  CHECK(0 != projectBuildTime->GetDateTime());
}


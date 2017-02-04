#include "tddstudyBuildTime.h"

tddstudyBuildTime::tddstudyBuildTime()
: dateTime(__DATE__ " " __TIME__)
{
}

tddstudyBuildTime::~tddstudyBuildTime()
{
}

const char* tddstudyBuildTime::GetDateTime()
{
    return dateTime;
}


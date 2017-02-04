#ifndef D_tddstudyBuildTime_H
#define D_tddstudyBuildTime_H

///////////////////////////////////////////////////////////////////////////////
//
//  tddstudyBuildTime is responsible for recording and reporting when
//  this project library was built
//
///////////////////////////////////////////////////////////////////////////////

class tddstudyBuildTime
  {
  public:
    explicit tddstudyBuildTime();
    virtual ~tddstudyBuildTime();
    
    const char* GetDateTime();

  private:
      
    const char* dateTime;

    tddstudyBuildTime(const tddstudyBuildTime&);
    tddstudyBuildTime& operator=(const tddstudyBuildTime&);

  };

#endif  // D_tddstudyBuildTime_H

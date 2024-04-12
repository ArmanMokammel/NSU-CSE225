#ifndef TIMESTAMP_H_INCLUDED
#define TIMESTAMP_H_INCLUDED
#include <ostream>

using namespace std;

class TimeStamp
{
    public:
        TimeStamp();
        TimeStamp(int, int, int);
        bool operator == (TimeStamp);
        bool operator != (TimeStamp);
        bool operator > (TimeStamp);
        bool operator < (TimeStamp);
        friend ostream& operator<< (ostream &out, const TimeStamp &timeStamp);
    
    private:
        int sec;
        int min;
        int hour;
};

#endif
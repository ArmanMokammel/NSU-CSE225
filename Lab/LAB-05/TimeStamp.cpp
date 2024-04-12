#include "TimeStamp.h"

TimeStamp::TimeStamp()
{
    this->sec = 0;
    this->min = 0;
    this->hour = 0;
}

TimeStamp::TimeStamp(int seconds, int minutes, int hours)
{
    this->sec = seconds;
    this->min = minutes;
    this->hour = hours;
}

bool TimeStamp::operator == (TimeStamp timeStamp)
{
    return (this->sec == timeStamp.sec && this->min == timeStamp.min && this->hour == timeStamp.hour);
}

bool TimeStamp::operator != (TimeStamp timeStamp)
{
    return (this->sec != timeStamp.sec || this->min != timeStamp.min || this->hour != timeStamp.hour);
}

bool TimeStamp::operator < (TimeStamp timeStamp)
{
    return ((this->hour < timeStamp.hour) || (this->hour == timeStamp.hour && this->min < timeStamp.min) || (this->hour == timeStamp.hour && this->min == timeStamp.min && this->sec < timeStamp.sec));
}

bool TimeStamp::operator > (TimeStamp timeStamp)
{
    return ((this->hour > timeStamp.hour) || (this->hour == timeStamp.hour && this->min > timeStamp.min) || (this->hour == timeStamp.hour && this->min == timeStamp.min && this->sec > timeStamp.sec));
}

ostream& operator << (ostream &out, const TimeStamp &timeStamp)
{
    out << timeStamp.sec << ":" << timeStamp.min << ":" << timeStamp.hour << endl;;
    return out;
}
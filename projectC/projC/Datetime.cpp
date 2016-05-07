#include "Datetime.h"

DateTime::DateTime()
{
    time_t now;
    time( &now );
    this->datetime = localtime( &now );
}

DateTime::DateTime(int year, int month, int day, int hour, int minutes)
{
    this->datetime = new tm();
    this->datetime->tm_year = year;
    this->datetime->tm_mon = month;
    this->datetime->tm_mday = day;
    this->datetime->tm_hour = hour;
    this->datetime->tm_min = minutes;
}

DateTime::~DateTime()
{
    delete this->datetime;
}

//DateTime::DateTime(const DateTime &_datetime)
//{
//    //this->datetime
//}

void DateTime::Serialize(Json::Value &subroot)
{
    subroot["year"] = this->datetime->tm_year;
    subroot["month"] = this->datetime->tm_mon;
    subroot["day"] = this->datetime->tm_mday;
    subroot["hour"] = this->datetime->tm_hour;
    subroot["minutes"] = this->datetime->tm_min;

}

void DateTime::Deserialize(Json::Value &subroot)
{
    this->datetime->tm_year = subroot["year"].asInt();
    this->datetime->tm_mon = subroot["month"].asInt();
    this->datetime->tm_mday = subroot["day"].asInt();
    this->datetime->tm_hour = subroot["hour"].asInt();
    this->datetime->tm_min = subroot["minutes"].asInt();

}


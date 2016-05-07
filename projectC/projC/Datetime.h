#ifndef DATETIME_H
#define DATETIME_H
#pragma once
#include <stdio.h>
#include <iostream>
#include <ctime>
#include "ijsonserializable.h"

class DateTime : public IJsonSerializable
{
public:
    DateTime();
    DateTime(int year, int month, int day, int hour, int minutes);
    ~DateTime();
    //DateTime(const DateTime& d_datetime);

    virtual void Serialize( Json::Value &subroot );
    virtual void Deserialize( Json::Value &subroot );

private:
    tm* datetime;
};

#endif // DATETIME_H

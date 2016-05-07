#ifndef DATALAYER_H
#define DATALAYER_H
#pragma once
#include <stdio.h>
#include "Adapter.h"
#include "dist/json/json.h"
#include "User.h"

class Datalayer
{
public:
    Datalayer(std::string filename);
    ~Datalayer();
    void getData(User* user, TaskFactory* factory);
    void setData(User* user);
private:
    AdapterForFile* adapter;
};

#endif // DATALAYER_H

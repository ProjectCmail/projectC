
#pragma once
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "dist/json/json.h"

class AdapterForFile
{
public:
	AdapterForFile(std::string _fileName) : fileName(_fileName){}
	~AdapterForFile(){}

    Json::Value readData();
    void writeData(Json::Value& root);

	


private:
	std::string fileName;
    Json::Value parserJson(std::ifstream& in);

};

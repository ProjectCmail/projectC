#include "Datalayer.h"

Datalayer::Datalayer(std::string filename)
{
    this->adapter = new AdapterForFile(filename);
}

Datalayer::~Datalayer()
{
    delete this->adapter;
}

void Datalayer::getData(User* user, TaskFactory* factory)
{
    Json::Value root = this->adapter->readData();
    user->Deserialize(root, (*factory));

}

void Datalayer::setData(User* user)
{
    Json::Value root;
    user->Serialize(root);
    this->adapter->writeData(root);
}




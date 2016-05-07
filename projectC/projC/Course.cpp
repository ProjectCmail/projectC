#include "Course.h"
#include <typeinfo>
#include "dependency.h"
#include "Taskfactory.h"


void Course::Serialize(Json::Value &subroot)
{

    subroot["Name"] = this->getName();
    subroot["Status"] = this->getStatus();
    subroot["Progress"] = this->getProgress();


    for(int i = 0; i < this->size();i++)
    {
        Json::Value subObject;
        subObject["type"] = this->className(i);
        this->runSerialize(i, subObject);
        subroot["tasks"][to_string(i)] = subObject;
    }


//    object["Name"] = this->GetName();
//    object["Notification"] = this->GetNotification();
//    object["Deadline"] = this->GetDeadline();
//    object["Status"] = this->GetStatus();
//    object["Progres"] = this->GetProgress();
}

void Course::Deserialize(Json::Value &subroot, TaskFactory& factory)
{
    //  TaskFactory* factory
    this->setName(subroot["Name"].asString());
    this->setStatus(subroot["Status"].asInt());
    this->setProgress(subroot["Progress"].asInt());

    std::vector<std::string> members = subroot["tasks"].getMemberNames();

    for(unsigned int i = 0; i < members.size(); i++)
    {
        Json::Value root = subroot["tasks"][members.at(i)];
        std::string type = subroot["tasks"][members.at(i)]["type"].asString();
        Task* task = factory.create(type);
        task->Deserialize(subroot["tasks"][members.at(i)]);
        this->addTask(task);
    }

//    this->Name =  object["Name"];
//    this->Notification = object["Notification"];
//    this->Deadline = object["Deadline"];
//    this->Status = object["Status"];
//    this->Progress = object["Progres"];
}


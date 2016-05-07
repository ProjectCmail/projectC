#include "Task.h"

Task::Task()
{
    this->Notification = new DateTime();
    this->Deadline = new DateTime();
    this->Progress = 0;
}

void Task::Serialize(Json::Value &subroot)
{
    Json::Value json;

    subroot["Name"] = this->GetName();

    this->Notification->Serialize(json);
    subroot["Notification"] = json;

    json.clear();
//    this->Deadline->Serialize(json);
//    subroot["Deadline"] = json;

    subroot["Status"] = this->GetStatus();
    subroot["Progress"] = this->GetProgress();
}

void Task::Deserialize(Json::Value &subroot)
{
    this->Name =  subroot["Name"].asString();

    this->Notification->Deserialize(subroot["Notification"]);
    //this->Deadline->Deserialize(subroot["Deadline"]);
    this->Status = subroot["Status"].asString();
    this->Progress = subroot["Progress"].asInt();
}


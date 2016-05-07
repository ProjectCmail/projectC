#include "Exam.h"
#include <string>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "dependency.h"

Exam::Exam()
{
    this->Deadline = new DateTime();
}

void Exam::Serialize(Json::Value &subroot)
{

    for(int i = 0; i < this->size();i++)
    {
        Json::Value subObject;
        this->runSerialize(i, subObject);
        subroot[to_string(i)] = subObject;
    }

    Json::Value json;
    this->Deadline->Serialize(json);
    subroot["Deadline"] = json;

//    object["Name"] = this->GetName();
//    object["Notification"] = this->GetNotification();
//    object["Deadline"] = this->GetDeadline();
//    object["Status"] = this->GetStatus();
//    object["Progres"] = this->GetProgress();
}

void Exam::Deserialize(Json::Value &subroot)
{
    std::vector<std::string> members = subroot.getMemberNames();

    for(int i = 0; i < members.size(); i++)
    {
        if(members.at(i) != "type" && members.at(i) != "Deadline")
        {
            Task* task = new Task();
            task->Deserialize(subroot[members.at(i)]);
            this->addTask(task);
        }
    }
    this->Deadline->Deserialize(subroot["Deadline"]);


//    this->Name =  object["Name"];
//    this->Notification = object["Notification"];
//    this->Deadline = object["Deadline"];
//    this->Status = object["Status"];
//    this->Progress = object["Progres"];
}

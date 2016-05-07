#include "Test.h"
#include "dependency.h"

Test::Test()
{
     this->Deadline = new DateTime();
}

void Test::Serialize(Json::Value &object)
{

    for(int i = 0; i < this->size();i++)
    {
        Json::Value subObject;
        this->runSerialize(i, subObject);
        object[to_string(i)] = subObject;
    }


//    object["Name"] = this->GetName();
//    object["Notification"] = this->GetNotification();
//    object["Deadline"] = this->GetDeadline();
//    object["Status"] = this->GetStatus();
//    object["Progres"] = this->GetProgress();
}

void Test::Deserialize(Json::Value &subroot)
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

//    this->Name =  object["Name"];
//    this->Notification = object["Notification"];
//    this->Deadline = object["Deadline"];
//    this->Status = object["Status"];
//    this->Progress = object["Progres"];
}

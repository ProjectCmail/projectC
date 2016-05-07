#include "User.h"
#include "dependency.h"

void User::Serialize(Json::Value &subroot)
{

    subroot["User"]["UserName"] = this->getName();
    subroot["User"]["CourceLevel"] = this->getCourseLevel();


    for(int i = 0; i < this->size();i++)
    {
        Json::Value subObject;
        this->runSerialize(i, subObject);
        subroot["User"]["cources"][to_string(i)] = subObject;
    }


//    object["Name"] = this->GetName();
//    object["Notification"] = this->GetNotification();
//    object["Deadline"] = this->GetDeadline();
//    object["Status"] = this->GetStatus();
//    object["Progres"] = this->GetProgress();
}

void User::Deserialize(Json::Value &subroot, TaskFactory& factory)
{
    this->setName(subroot["User"]["UserName"].asString());
    this->setCourseLevel(subroot["User"]["CourceLevel"].asInt());


    std::vector<std::string> members = subroot["User"]["cources"].getMemberNames();

    for(unsigned int i = 0; i < members.size(); i++)
    {
        Course* _course = new Course();
        _course->Deserialize(subroot["User"]["cources"][members.at(i)], factory);
        this->addCourse(_course);
    }

}

void User::addTaskToCourse(int courseId, Task *task)
{
    this->courses.at(courseId)->addTask(task);
}

void User::deleteTaskToCourse(int courseId, int taskId)
{
    this->courses.at(courseId)->deleteTask(taskId);
}

void User::addTaskToCourseInGenlTask(int courseId, int taskId, Task *task)
{
    this->courses.at(courseId)->addTaskToGenlTask(taskId, task);
}

void User::deleteTaskToCourseInGenlTask(int courseId, int taskId, int taskInTaskId)
{
    this->courses.at(courseId)->deleteTaskToGelnTask(taskId, taskInTaskId);
}



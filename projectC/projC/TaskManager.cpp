#include "TaskManager.h"

TaskManager::TaskManager(std::string userName)
{
    this->user = new User();
    this->datalayer = new Datalayer(userName + ".txt");
    this->factory = new TaskFactory();
    factory->add<Test>("4Test");
    factory->add<Exam>("4Exam");
    factory->add<Homework>("4Homework");
}

TaskManager::~TaskManager()
{
	delete this->user;
    delete this->datalayer;
}

void TaskManager::createNewUser(std::string nameUser, int courseLevel)
{
//    if(this->user == NULL)
//    {
//        this->user = new User();
        this->user->setName(nameUser);
        this->user->setCourseLevel(courseLevel);
//    }else
//    {
//        throw "Error, user already exists!";
//    }
}


void TaskManager::loadUser()
{
//    if(this->user == NULL)
//    {
        this->datalayer->getData(this->user, this->factory);
//    }else
//    {
//        throw "Error, user already exists!";
//    }
}

void TaskManager::saveUser()
{
    if(this->user != NULL)
        this->datalayer->setData(this->user);
}

void TaskManager::addCourse(std::string name)
{
    this->user->addCourse(new Course(name));
    this->datalayer->setData(this->user);

}

void TaskManager::deleteCourse(int id)
{
    this->user->deleteCourse(id);
    this->datalayer->setData(this->user);

}

void TaskManager::addTaskToCourse(int courseId, std::string type, DateTime* deadline)
{
    Task* task = this->factory->create(type);
    task->SetDeadline(deadline);
    this->user->addTaskToCourse(courseId, task);
    this->datalayer->setData(this->user);
}

void TaskManager::deleteTaskToCourse(int courseId, int taskId)
{
    this->user->deleteTaskToCourse(courseId, taskId);
    this->datalayer->setData(this->user);
}

void TaskManager::addTaskToTaskInCourse(int courseId, int taskId, std::string Name, DateTime *Notification, DateTime* daedline, std::string Status, std::string Comment)
{
    this->user->addTaskToCourseInGenlTask(courseId, taskId, new Task(Name, Notification,daedline, Status, Comment));
    this->datalayer->setData(this->user);
}

void TaskManager::deleteTaskToTaskInCourse(int courseId, int taskId, int taskInTaskId)
{
    this->user->deleteTaskToCourseInGenlTask(courseId, taskId, taskInTaskId);
    this->datalayer->setData(this->user);

}

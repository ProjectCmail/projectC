#pragma once
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "Task.h"
#include <typeinfo>
#include "Taskfactory.h"

struct StructCourse
{
    int id;
    std::string Name;
    int Progress;
    int Status;
    StructCourse(int _id, std::string _name, int _progress, int _status):
        id(_id), Name(_name), Progress(_progress), Status(_status){}
};


class Course : public Task
{
public :
	Course(){}
    Course(std::string name) : Name(name), Status(0), Progress(0){}
	~Course(){}

	std::string getName(){ return this->Name; }
	void setName(std::string _Name){ this->Name = _Name; }

	int getProgress(){ return this->Progress; }
	void setProgress(int _Progress){ this->Progress = _Progress; }

	int getStatus(){ return this->Status; }
	void setStatus(int _Status){ this->Status = _Status; }

	void addTask(Task* task){ this->tasks.push_back(task); }
    void deleteTask(int id){ this->tasks.erase(this->tasks.begin() + id); }
    //Task* getTask(int index){ this->tasks.at(index); }
    //std::vector<Task*> getTasks(){ this->tasks; }
    int size(){ return this->tasks.size(); }

    std::string className(int num){ return typeid(*this->tasks.at(num)).name();}

    void runSerialize(int num, Json::Value &root){ this->tasks.at(num)->Serialize(root); }
    void runDeserialize(int num, Json::Value &root){ this->tasks.at(num)->Deserialize(root); }

    virtual void Serialize( Json::Value &root );
    virtual void Deserialize( Json::Value &root, TaskFactory& factory);

    StructCourse packaging(int id){
        return StructCourse(id, Name, Progress, Status);
    }

    void addTaskToGenlTask(int taskId, Task* task){

        this->tasks.at(taskId)->addTask(task);
    }
    void deleteTaskToGelnTask(int taskId, int taskInTaskId){ this->tasks.at(taskId)->deleteTask(taskInTaskId); }


private :
	std::string Name;
	std::vector<Task*> tasks;
	int Progress;
    int Status;


};

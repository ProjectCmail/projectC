#pragma once
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "Task.h"
#include <typeinfo>



class Test : public Task
{
public :
    Test();
    Test(DateTime* _deadline): Deadline(_deadline){}
	~Test(){}

	void addTask(Task* task){ this->tasks.push_back(task); }
	Task* getTask(int index){ this->tasks.at(index); }

    void deleteTask(int id){ this->tasks.erase(this->tasks.begin() + id); }
    //std::vector<Task*> getTasks(){ this->tasks; }
    int size(){ return this->tasks.size(); }

    std::string className(){ return typeid(this).name(); }

    void runSerialize(int num, Json::Value &root){ this->tasks.at(num)->Serialize(root); }

    virtual void Serialize( Json::Value &root );
    virtual void Deserialize( Json::Value &root );


    DateTime* GetDeadline(){ return this->Deadline; }
    void SetDeadline(DateTime* _deadline){ this->Deadline = _deadline; }


private :
	std::vector<Task*> tasks;
    DateTime* Deadline;


};

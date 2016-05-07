#pragma once
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "ijsonserializable.h"
#include "Datetime.h"
#include <typeinfo>
#include "ITask.h"



class Task : public ITask<Task>, public IJsonSerializable
{
public:
    Task();
    Task(std::string _Name, DateTime* _Notification, DateTime* deadline, std::string _Status, std::string  _Comment): Name(_Name), Notification(_Notification), Deadline(deadline), Status(_Status), Comment(_Comment), Progress(0) {}
    ~Task(){}

//    virtual void addTask(Task* task) = 0;
//    virtual void deleteTask(int id) = 0;
    void addTask(Task* task){}
    void deleteTask(int id){}

	std::string GetName(){ return this->Name; }
	void SetName(std::string _Name){ this->Name = _Name; }

    DateTime* GetNotification() { return this->Notification; }
    void SetNotification(DateTime* _Notification){ this->Notification = _Notification; }

	std::string GetStatus(){ return this->Status; }
	void SetStatus(std::string _Status) { this->Status = _Status; }

    DateTime* GetDeadline(){ return this->Deadline; }
    void SetDeadline(DateTime* _deadline){ this->Deadline = _deadline; }

    int GetProgress(){ return this->Progress; }
    void SetProgress(int _progress){ this->Progress = _progress; }

    //std::string className(){ return typeid(this).name(); }

    virtual void Serialize( Json::Value &root );
    virtual void Deserialize( Json::Value &root );

private:
	std::string Name;
    DateTime* Notification;
     DateTime* Deadline;
	std::string Status;
	std::string Comment;
	int Progress;
};



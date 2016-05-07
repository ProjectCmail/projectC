#pragma once
#include <stdio.h>
#include <iostream>
#include <vector>
#include "Course.h"
#include "Taskfactory.h"


class User
{
public:
    User(){}
    ~User(){}

	void addCourse(Course* course){ this->courses.push_back(course); }
    //Course* getCourse(int index){ this->courses.at(index); }
    //std::vector<Course*> getCourses(){ this->courses; }
    void deleteCourse(int id){ this->courses.erase(this->courses.begin() + id); }
    int size(){ return this->courses.size(); }

    std::string getName(){ return this->userName; }
    void setName(std::string name){ this->userName = name; }

	int getCourseLevel(){ return this->courseLevel; }
	void setCourseLevel(int _courseLevel ){ this->courseLevel = _courseLevel; }

    void runSerialize(int num, Json::Value &root){ this->courses.at(num)->Serialize(root); }

    virtual void Serialize( Json::Value &root );
    virtual void Deserialize( Json::Value &root, TaskFactory& factory );

    std::vector<StructCourse> getCourses()
    {
        std::vector<StructCourse> coursesData;
        for(int i = 0; i < this->courses.size(); i++)
            coursesData.push_back(this->courses.at(i)->packaging(i));
        return coursesData;
    }

    void addTaskToCourse(int courseId, Task* task);
    void deleteTaskToCourse(int courseId, int taskId);

    void addTaskToCourseInGenlTask(int courseId, int taskId, Task* task);
    void deleteTaskToCourseInGenlTask(int courseId, int taskId, int taskInTaskId);

private:
	std::vector<Course*> courses;
	int courseLevel;
    std::string userName;


};



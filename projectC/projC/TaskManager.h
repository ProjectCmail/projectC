#pragma once
#include <stdio.h>
#include <iostream>
#include "User.h"
#include "Datalayer.h"
#include "Exam.h"
#include "Test.h"
#include "Homework.h"

class TaskManager
{
public:
	TaskManager(std::string userName);
	~TaskManager();
    void createNewUser(std::string nameUser, int courseLevel);
    void loadUser();
    void saveUser();

    void addCourse(std::string Name);
    void deleteCourse(int id);

    void addTaskToCourse(int courseId, std::string type, DateTime* deadline);
    void deleteTaskToCourse(int courseId, int taskId);

    void addTaskToTaskInCourse(int courseId, int taskId, std::string Name, DateTime* Notification,
                               DateTime* deadline, std::string Status, std::string Comment);

    void deleteTaskToTaskInCourse(int courseId, int taskId, int taskInTaskId);

    void setUser(User* user){ this->user = user; }

    std::vector<StructCourse> getCoursesInfo(){ return this->user->getCourses(); }


private:
	User* user;
    Datalayer* datalayer;
    TaskFactory* factory;




};

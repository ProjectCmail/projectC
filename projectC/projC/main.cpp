#include <stdio.h>
#include <iostream>
#include <ctime>
#include <time.h>
#include "User.h"
#include "dist/json/json.h"
#include "Adapter.h"
#include "Datetime.h"
#include "Exam.h"
#include "Test.h"
#include "Taskfactory.h"
#include "TaskManager.h"


int main(void)
{

    TaskManager* tm = new TaskManager("Pety");
    tm->loadUser();


//    tm->addCourse("Filosofi");
//    tm->addTaskToCourse(0, "4Exam", new DateTime());
//    tm->addTaskToTaskInCourse(0, 0, "Write shpor", new DateTime(), new DateTime(), "in worck", "very hight");
//    tm->addTaskToTaskInCourse(0, 0, "Write qqqqq", new DateTime(), new DateTime(), "in worck", "very hight");


    std::vector<StructCourse> course = tm->getCoursesInfo();
    for(int i = 0; i < course.size(); i++)
    {
        std::cout<< course.at(i).id << " " << course.at(i).Name << " " << course.at(i).Progress <<std::endl;
    }
//    tm->createNewUser("Pety", 2);

//    tm->addCourse("Programmer");
//    tm->addTaskToCourse(0, "4Test");
//    tm->addTaskToTaskInCourse(0, 0, "Read Book", new DateTime(), new DateTime(), "in worck", "very hight");

    delete tm;


	return 0;
}



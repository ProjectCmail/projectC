#ifndef TASKFACTORY_H
#define TASKFACTORY_H
#pragma once
#include <map>
#include "Task.h"
#include "Test.h"
#include "Homework.h"



class abstractTaskCreator
{
public:
    //virtual taskCreator() {}
    virtual Task * create() const = 0;
};

template <class T>
class taskCreator : public abstractTaskCreator
{
public:
    virtual T * create() const { return new T(); }
};

class TaskFactory
{
protected:
    typedef std::map<std::string, abstractTaskCreator*> FactoryMap;
    FactoryMap _factory;

public:
    TaskFactory(){}
    ~TaskFactory(){}

    template <class T>
    void add(const std::string & id)
    {
        typename FactoryMap::iterator it = _factory.find(id);
        if (it == _factory.end())
            _factory[id] = new taskCreator<T>();
    }


    Task * create(const std::string & id)
    {
        typename FactoryMap::iterator it = _factory.find(id);
        if (it != _factory.end())
            return it->second->create();
        return 0;
    }
};

#endif // TASKFACTORY_H

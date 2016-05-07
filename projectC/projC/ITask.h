#ifndef ITASK
#define ITASK

template <class T>
class ITask
{
public:
    ITask(){}
    virtual void addTask(T* task) = 0;
    virtual void deleteTask(int id) = 0;
    virtual DateTime* GetDeadline() = 0 ;
    virtual void SetDeadline(DateTime* _deadline) = 0;
};
#endif // ITASK


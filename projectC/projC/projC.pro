QT += core
QT -= gui

TARGET = projC
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    main.cpp \
    TaskManager.cpp \
    dist/jsoncpp.cpp \
    Adapter.cpp \
    Task.cpp \
    Homework.cpp \
    Datetime.cpp \
    Exam.cpp \
    Test.cpp \
    Course.cpp \
    User.cpp \
    Datalayer.cpp

HEADERS += \
    Adapter.h \
    Course.h \
    Exam.h \
    Homework.h \
    Task.h \
    TaskManager.h \
    Test.h \
    User.h \
    dist/json/json-forwards.h \
    dist/json/json.h \
    ijsonserializable.h \
    Datetime.h \
    dependency.h \
    Taskfactory.h \
    Datalayer.h \
    ITask.h


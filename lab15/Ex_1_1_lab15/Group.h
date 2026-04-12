#pragma once
#include <string>
#include <list>
#include <algorithm>
#include "Student.h"

using namespace std;

class Group
{
private:
    string name;
    list<Student> masSt;
    list<Student>::iterator iter;

public:
    Group(string name);
    Group();

    void setName(string newName);
    string getName();

    int getSize();
    void addStudent(Student newStudent);
    void delStudent(Student oldStudent);
    Student findStudent(string, string);
    void GroupSort();
    void GroupOut();
};
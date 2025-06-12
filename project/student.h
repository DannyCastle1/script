#pragma once
#include <iostream>
#include "degree.h"
using std::cout;
using std::string;

class Student
{
private:
    string studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    int daysToComplete[3];
    DegreeProgram degreeProgram;

public:

    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    int* getDays();
    DegreeProgram getDegreeType();


    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmail(string email);
    void setAge(int age);
    void setDays(int daysToComplete[]);
    void setDegreeType(DegreeProgram degreeProgram);

    Student();
    Student(string sID, string fName, string lName, string email, int age, int days[], DegreeProgram degreeProgram);
    ~Student();

    void print();
};




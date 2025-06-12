#pragma once
#include "student.h"

class Roster
{
    public:
    int lastIndex;
    int numStudents;
    Student* classRosterArray;

    void parse(string row);
    void add(string studentID, 
        string firstName, 
        string lastName,
        string email,
        int age,
        int daysInCourse1,
        int daysInCourse2,
        int daysInCourse3,
        DegreeProgram degreeProgram);
    void remove(string studentID);
    void print();
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    Roster();
    ~Roster();
};

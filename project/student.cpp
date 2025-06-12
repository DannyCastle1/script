#include "student.h"


Student::Student()
{
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->email = "";
    this->age = -1;
    for (int i = 0; i < 3; i++)
        this->daysToComplete[i] = -1;
    this->degreeProgram = DegreeProgram::NETWORK;
};


Student::Student(string sID, string fName, string lName, string email, int age, int days[], DegreeProgram degreeProgram)
{
    this->studentID = sID;
    this->firstName = fName;
    this->lastName = lName;
    this->email = email;
    this->age = age;
    for (int i = 0; i < 3; i++)
        this->daysToComplete[i] = days[i];
    this->degreeProgram = degreeProgram;
};

Student::~Student() {};

string Student::getStudentID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmail() { return this-> email; }
int Student::getAge() { return this->age; }
int* Student::getDays() { return this->daysToComplete; }
DegreeProgram Student::getDegreeType() { return this->degreeProgram; }

void Student::setStudentID(string studentID){this->studentID = studentID;}
void Student::setFirstName(string firstName){this->firstName = firstName;}
void Student::setLastName(string lastName){this->lastName = lastName;}
void Student::setEmail(string email){this->email = email;}
void Student::setAge(int age){this->age = age;}
void Student::setDays(int days[]){this->daysToComplete[2]=days[2];}
void Student::setDegreeType(DegreeProgram degreeProgram){this->degreeProgram = degreeProgram;}

void Student::print()
{
    cout << this->getStudentID() << "\t";
    cout << this->getFirstName() << "\t";
    cout << this->getLastName() << "\t";
    cout << this->getEmail() << "\t";
    cout << this->getAge() << "\t";
    cout << this->getDays()[0] << ",";
    cout << this->getDays()[1] << ",";
    cout << this->getDays()[2] << "\t";
    cout << degreeProgramStrings[this->getDegreeType()] << "\n";
};

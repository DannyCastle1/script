#include "roster.h"

// constructor
Roster::Roster(){
    classRosterArray = new Student[5];
    numStudents = 5;
    lastIndex = -1;
};

// function to parse through a set of data
void Roster::parse(string data)
{
    size_t rhs = data.find(",");
    string sID = data.substr(0, rhs);

    size_t lhs = rhs + 1;
    rhs = data.find(",", lhs);
    string sFirst = data.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    string sLast = data.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    string sEmail = data.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    int sAge = stoi(data.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    int d1 = stoi(data.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    int d2 = stoi(data.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    int d3 = stoi(data.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    string sDegree = data.substr(lhs, rhs - lhs);
    
    DegreeProgram dp;
    if (sDegree == "NETWORK") {
        dp = NETWORK;
    } else if (sDegree == "SOFTWARE"){
        dp = SOFTWARE;
    } else {
        dp = SECURITY;
    };

    add(sID, sFirst, sLast, sEmail, sAge, d1, d2, d3, dp);

};

// adds Student to Roster class
void Roster::add(string studentID,
                 string firstName,
                 string lastName,
                 string email,
                 int age,
                 int daysInCourse1,
                 int daysInCourse2,
                 int daysInCourse3,
                 DegreeProgram degreeProgram)
{
    int daysArray[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    
    Student s(studentID, firstName, lastName, email, age, daysArray, degreeProgram);
    
    classRosterArray[++lastIndex] = s;
};

// function to remove a value with student ID as a parameter
void Roster::remove(string studentID)
{
    bool valid = false;
    Student* temp = new Student[numStudents - 1];
    int tempIndex = 0;
    for (int i = 0; i < numStudents; i++)
    {
        if (classRosterArray[i].getStudentID() == studentID)
        {
            valid = true;
            
        } else {
            
            temp[tempIndex++] = classRosterArray[i];
        }
    }
    if (valid)
    {
        classRosterArray = temp;
        
        numStudents--;
        
        cout << studentID << " removed from roster." << std::endl << std::endl;
        
    } else {
        
        cout << studentID << ": student with this id is not found." << std::endl << std::endl;
    }
        
}

// displays all information within a set of data
void Roster::printAll()
{

    for (int i = 0; i < numStudents; i++)
    {
        classRosterArray[i].print();
    }
    cout << "\n";
};

// displays the average from a set of integers with student ID as a parameter
void Roster::printAverageDaysInCourse(string studentID)
{
    cout << "Average Days In Course" << std::endl;
    
    for (int i = 0; i < numStudents; i++)
    {
        cout << classRosterArray[i].getStudentID() << ": ";
        
        cout << (classRosterArray[i].getDays()[0] + classRosterArray[i].getDays()[1] + classRosterArray[i].getDays()[2])/3.0 << std::endl;
    }
    cout << std::endl;
};

// checks whether the email values stored are saved correctly
void Roster::printInvalidEmails()
{
    bool valid = false;
    
    for (int i = 0; i < numStudents; i++)
    {
        string email = (classRosterArray[i].getEmail());
        
        if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos)
        {
            valid = true;
            
            cout << "Invalid email: " << classRosterArray[i].getEmail() << std::endl;
        }
    }
    cout << std::endl;
};

// sorts values based on degree type parameter
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
    cout << "Degree Program" << std::endl;
    
    for (int i = 0; i <= numStudents; i++)
    {
        if (classRosterArray[i].getDegreeType() == degreeProgram) classRosterArray[i].print();
    }
    cout << std::endl;
};

// function to display data
void Roster::print()
{
    cout << "867 Scripting Applications, C++, ID 12345, Daniel Castillo" << std::endl;
    
    cout << std::endl;
};

// fucntion to release memory allocation
Roster::~Roster()
{
    cout << "Destructor operating" << std::endl << std::endl;

        delete[] classRosterArray;
        
};

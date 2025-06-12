
#include "roster.h"

int main(int argc, const char * argv[]) {
    
    const string studentData[] =
    {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY","A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE","A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Daniel,Castillo,dannycastle@yahoo.com,38,30,20,30,SOFTWARE"};
    
    Roster classRoster;
    
    for (int i = 0; i < 5; i++) {
        classRoster.parse(studentData[i]);
    };
  
    classRoster.print();
    
    classRoster.printAll();
    
    classRoster.printInvalidEmails();
    
    classRoster.printAverageDaysInCourse("A3");
    
    classRoster.printByDegreeProgram(SOFTWARE);
    
    classRoster.remove("A3");
    
    classRoster.printAll();
    
    classRoster.remove("A3");
    
    return 0;
}

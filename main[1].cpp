//
//  main.cpp
//  PA_C867_Dodenhoff
//
//  Created by Samantha Dodenhoff on 3/12/23.
//

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string>
#include "roster.hpp"
#include "student.hpp"
#include "degree.h"
using namespace std;


int main(){
    const int studentTotal = 5;
    
    //modify student data table and input your own info as student A5 requirement A
    const string studentData[5] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Samantha,Dodenhoff,sdodenh@wgu.edu,31,4,7,30,SOFTWARE"
    };
  
    
    //print out course info, language, student ID, name requirement F.1
    cout << "C867 Scripting and Programming Applications" << endl;
    cout << "Language Used: C++" << endl;
    cout << "Western Governors University Student ID: 010906612" << endl;
    cout << "Student Name: Samantha Dodenhoff" << endl;
    
    //create instance of Roster class called classRoster requirement F.2
    Roster* classRoster = new Roster(studentTotal);
    
    //add students to classRoster requirement F.3
    for (int i = 0; i < studentTotal; i++){
        classRoster->parseArray(studentData[i]);
    }
    
    //Convert the following pseudo code to complete the rest of the  main() function requirement F.4
    cout << "All students: " << endl;
    classRoster->printAll();
    classRoster->printInvalidEmails();

    //loop through classRosterArray and for each element:
    cout << "Average days in course for each student: " << endl;
    for (int i = 0; i < 5; i++){
        classRoster->printAverageDaysInCourse(classRoster->classRosterArray[i]->GetStudentID());
    }

    cout << "Software Degrees: " << endl;
    classRoster->printByDegreeProgram(DegreeProgram::SOFTWARE);

    cout << "Removing student with ID A3" << endl;
    classRoster->removeStudent("A3");
    
    cout << "All students: " << endl;
    classRoster->printAll();
    
    cout << "All students: " << endl;
    classRoster->removeStudent("A3");
    cout << "Error: Student with this ID not found." << endl;
 
    
    //implement destructor requirement F.5
    char exitSign = 'a';
    while (exitSign != 'q'){
        cout << endl << "enter 'q' to quit...";
        cin >> exitSign;
        cout << endl;
    }
    
    return 0;
}


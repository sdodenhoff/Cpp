//
//  roster.cpp
//  PA_C867_Dodenhoff
//
//  Created by Samantha Dodenhoff on 3/12/23.
//

#include "roster.hpp"
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "student.hpp"
#include "degree.h"
using namespace std;

//add constructor without return
Roster::Roster(){};

Roster::Roster(int studentTotal){};

//add student object to classRoster using studentData table
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram){
    
    int DaysInCourse[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    
    classRosterArray[++studentIndex] = new Student(studentID, firstName, lastName, emailAddress, age, DaysInCourse, degreeProgram);
    
}

//parse student data requirement E.2.a
void Roster::parseArray(string studentData){
   
    
    size_t rhs = studentData.find(",");
    string studentID = studentData.substr(0, rhs);
    
    size_t lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string firstName = studentData.substr(lhs, rhs-lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string lastName = studentData.substr(lhs, rhs - lhs);
        
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string emailAddress = studentData.substr(lhs, rhs - lhs);
        
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int age = stoi(studentData.substr(lhs, rhs - lhs));
        
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse1 = stoi(studentData.substr(lhs, rhs - lhs));
        
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse2 = stoi(studentData.substr(lhs, rhs - lhs));
        
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse3 = stoi(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    if (studentData.substr(lhs, rhs - lhs) == "SECURITY") {
        degreeProgram = DegreeProgram::SECURITY;
    }
    else if (studentData.substr(lhs, rhs - lhs) == "NETWORK") {
        degreeProgram = DegreeProgram::NETWORK;
    }
    else if (studentData.substr(lhs, rhs - lhs) == "SOFTWARE") {
        degreeProgram = DegreeProgram::SOFTWARE;
    }
    else{
        cout << "Invalid degree program \"" << degreeProgramString << "\". Exiting." << endl;
    }
               
this->add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

//print tab-separated list of studentData
void Roster::printAll(){
    cout << "Student ID | First Name | Last Name | Email Address | Age | Days in Course | Degree Program \n";
    for ( int i = 0; i <= Roster::studentIndex; i++){
        cout << classRosterArray[i]->GetStudentID(); cout << '\t';
        cout << classRosterArray[i]->GetFirstName(); cout << '\t';
        cout << classRosterArray[i]->GetLastName(); cout << '\t';
        cout << classRosterArray[i]->GetEmailAddress(); cout << '\t';
        cout << classRosterArray[i]->GetAge(); cout << '\t';
        cout << classRosterArray[i]->GetDaysInCourse()[0]; cout << '\t';
        cout << classRosterArray[i]->GetDaysInCourse()[1]; cout << '\t';
        cout << classRosterArray[i]->GetDaysInCourse()[2]; cout << '\t' << endl;
       //cout << degreeProgramString[(int) classRosterArray[i]->GetDegreeProgram()] << endl;

        
        cout << endl;
    }
}
        
        
        //print student average days in courses
void Roster::printAverageDaysInCourse(string studentID){
    for (int i = 0; i <= Roster::studentIndex; i++) {
        if (classRosterArray[i]->GetStudentID() == studentID) {
            cout << "Student " << studentID << " has averaged" << ": ";
            cout << ((classRosterArray[i]->GetDaysInCourse()[0]
                    + classRosterArray[i]->GetDaysInCourse()[1]
                    + classRosterArray[i]->GetDaysInCourse()[2])
                    / 3.0) << endl;
                    cout << " days per course." << endl;
        }
    }
}
        
        
        
        //remove student by studentID, print error if not found
void Roster::removeStudent(string studentID){
    bool REMOVE = false;
    for (int i = 0; i <= Roster::studentIndex; i++){
        if (classRosterArray[i]->GetStudentID() == studentID){
            REMOVE = true;
            if (i < totalStudentNum - 1){
                Student* tempVal = classRosterArray[i];
                classRosterArray[i] = classRosterArray[totalStudentNum - 1];
                classRosterArray[totalStudentNum -1] = tempVal;
            }
            Roster::studentIndex--;
        }
    }
    
    if (REMOVE){
        cout << "Student " << studentID << " removed." << endl;
        this->printAll();
    }
    else {
        cout << "Student " << studentID << " not found in class roster." << endl;
    }
}
            
            
            
//verify student emails and print error message if invalid
void Roster::printInvalidEmails(){
    bool ALL = false;
    for (int i = 0; i <= Roster::studentIndex; i++){
        string aemailAddress = (classRosterArray[i]->GetEmailAddress());
        if (aemailAddress.find('@') == string::npos || (aemailAddress.find(' ') != string::npos) || aemailAddress.find('.') == string::npos){
            ALL = true;
            cout << aemailAddress << "is invalid" << endl;
        }
    }
}
            
//print degree program info
void Roster::printByDegreeProgram(DegreeProgram degreeProgram){
    cout << "Degree Program: \n";
    for (int i = 0; i <=Roster::studentIndex; i++){
        if (Roster::classRosterArray[i]->GetDegreeProgram() == degreeProgram){
            classRosterArray[i]->print();
        }
    }
    cout << endl;
}
  

//
//  roster.hpp
//  PA_C867_Dodenhoff
//
//  Created by Samantha Dodenhoff on 3/12/23.
//

#ifndef roster_hpp
#define roster_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include "student.hpp"
#include "degree.h"
using namespace std;

class Roster{
public:
    Roster(); //default constructor
    Roster(int studentTotal);
    Student** getStudents();
    ~Roster(); //deconstructor
    DegreeProgram degreeProgram;
    string degreeProgramString;
    Student* classRosterArray[5] = {nullptr, nullptr, nullptr, nullptr, nullptr};

    
    //add studentData to classRoster as object for each student
    void parseArray(string studentData);
    
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
    
    //print complete tab-separated list of student data
    void printAll();
    
    //remove student from roster using studentID
    void removeStudent(string studentID);
    
    //print student average days in course
    void printAverageDaysInCourse(string studentID);
    
    //verify emails and display invalid ones
    void printInvalidEmails();
    
    //print degree program info
    void printByDegreeProgram(DegreeProgram degreeProgram);
    
   
    
private:
   //array of pointers to hold StudentData table data
    int studentIndex = -1;
    const static int totalStudentNum = 5;
 
    
};




#endif /* roster_hpp */

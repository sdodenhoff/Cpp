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
using namespace std;


class Roster{
public:
    Roster(); //default constructor
    Roster(int studentTotal);
    Student** getStudents();
    ~Roster(); //deconstructor
    
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
    void printByDegreeProgram();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    
    
    //array of pointers to hold data from studentData table
    const static int totalStudentNum = 5;
    Student* classRosterArray[totalStudentNum] = {nullptr, nullptr, nullptr, nullptr, nullptr};
    
private:
  //FIXME  int studentIndex = -1;
    int MAX_COURSES = 3;
    const int ROSTER_SIZE = 5;
};




#endif /* roster_hpp */



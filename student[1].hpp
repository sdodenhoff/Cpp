//
//  student.hpp
//  PA_C867_Dodenhoff
//
//  Created by Samantha Dodenhoff on 3/12/23.
//
#ifndef student_h
#define student_h
#include "degree.h"
#include <string>
#include <stdio.h>
using namespace std;


class Student {
public:
    DegreeProgram degreeProgram;
    static const string degreeProgramString[];
    Student(); //default constructor
    Student (string studentID, string firstName, string lastName, string emailAddress,
             int age, int daysInCourse[], DegreeProgram degreeProgram); //constructor for all parameters
    const static int daysArray = 3;
    
    
    ~Student(); //deconstructor
    
    //accessors for each instance
    string GetStudentID();
    string GetFirstName();
    string GetLastName();
    string GetEmailAddress();
    int GetAge();
    const int* GetDaysInCourse();
    DegreeProgram GetDegreeProgram();
    
    //mutators for each instance
    void SetStudentID(string studentID);
    void SetFirstName(string firstName);
    void SetLastName(string lastName);
    void SetEmailAddress(string emailAddress);
    void SetAge(int age);
    void SetDaysInCourse(const int daysInCourse[]);
    void SetDegreeProgram(DegreeProgram degreeprogram);
    
    //print specific student data
    static void printHeader();
    void print();
    
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysInCourse[daysArray];
    
    
};

#endif

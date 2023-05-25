//
//  student.cpp
//  PA_C867_Dodenhoff
//
//  Created by Samantha Dodenhoff on 3/12/23.
//

#include "student.hpp"
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string>
#include "degree.h"
using namespace std;


 //constructor with input parameters (defaults) requirement 2.d
 Student::Student(){
 this->studentID = "";
 this->firstName = "";
 this->lastName = "";
 this->emailAddress = "";
 this->age = -1;
 for (int i = 0; i < daysArray; i++){
 this->daysInCourse[i] = 0;
 }
 this->degreeProgram = DegreeProgram::SECURITY;
 }
 
 //overloading constructor for requirement 2.d
 Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram){
 this->studentID = studentID;
 this->firstName = firstName;
 this->lastName = lastName;
 this->emailAddress = emailAddress;
 this->age = age;
 for(int i = 0; i < daysArray; i++){
 this->daysInCourse[i] = daysInCourse[i];
 }
 this->degreeProgram = degreeProgram;
 }
 
 //deconstructor requirement 5
 Student::~Student(){}
 
 //accessor for each instance variable requirement 2.a
 string Student::GetStudentID(){
 return this->studentID;
 }
 
 string Student::GetFirstName(){
 return this->firstName;
 }
 
 string Student::GetLastName(){
 return this->lastName;
 }
 
 string Student::GetEmailAddress(){
 return this->emailAddress;
 }
 
 int Student::GetAge(){
 return this->age;
 }
 
 const int* Student::GetDaysInCourse(){
 return this->daysInCourse;
 }
 
DegreeProgram Student::GetDegreeProgram(){
 return this->degreeProgram;
 }
 
 
 //mutators for each instance variable requirement 2.b
 void Student::SetStudentID(string studentID){
 this->studentID = studentID;
 }
 
 void Student::SetFirstName(string firstName){
 this->firstName = firstName;
 }
 
 void Student::SetLastName(string lastName){
 this->lastName = lastName;
 }
 
 void Student::SetEmailAddress(string emailAddress){
 this->emailAddress = emailAddress;
 }
 
 void Student::SetAge(int age){
 this->age = age;
 }
 
 void Student::SetDaysInCourse(const int daysInCourse[]){
     for (int i = 0; i <daysArray; i++){
         this->daysInCourse[i] = daysInCourse[i];
     }
 }
 
 void Student::SetDegreeProgram(DegreeProgram degreeProgram){
     this->degreeProgram = degreeProgram;
 }
 
 
 //print specific student data requirement 2.e
 void Student::printHeader(){
 cout << "Student ID \t";
 cout << "First Name \t";
 cout << "Last Name \t";
 cout << "Email Address \t";
 cout << "Age \t";
 cout << "Days in Course \t";
 cout << "Degree Program \t";
 cout << endl;
 }
 
 void Student::print(){
 cout << this->studentID << " \t";
 cout << this->firstName << " \t";
 cout << this->lastName << " \t";
 cout << this->emailAddress << " \t";
 cout << this->age << " \t";
 cout << this->daysInCourse[0] << " \t";
 cout << this->daysInCourse[1] << " \t";
 cout << this->daysInCourse[2] << " \t";
     cout << (int) this->degreeProgram;
 cout << degreeProgramString[(int) this->degreeProgram] << " \t";
 cout << endl;
 }
 

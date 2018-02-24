#ifndef STUDENTLIST_H
#define STUDENTLIST_H
// Header file - studentList.h

#include<iostream>
#include<string>
#include<iomanip>
#include <windows.h>
#define NUM_STUDENT 2

using namespace std;

//Structure to store student data
struct StudentList
{
	int studentID;
	string firstName;
	string lastName;
	string password;
	float midTermGrade;
	float projectGrade;
	float finalExamGrade;
	float finalGrade;
};
//Structure to store course information
struct Course
{
	StudentList studentsEnrolled[NUM_STUDENT];
	string courseNumber;
	string courseTitle;
	int courseGroup;
	int studentTotal;
};
// Functions used in the program
void inputStudentData(Course[], int, int);
void sortStudentData(Course[], int, int);
void searchStudentId(Course[], int, int);
void searchStudentFirst(Course[], int, int);
void searchStudentLast(Course[], int, int);
void searchStudentName(Course[], int, int);
void listCourses(Course[], int);
void listAllstudentGrades(Course[], int, int);
void displayresult(Course[], int, int);
void displayheader(Course[], int);
void gotoXY(int, int);
float entergrade(Course[], int, int);
//int existingstudent(Course[], int, string, int, int); Not being used in this version of the program
int studentLogin(Course[], int, int);
int studentMenu();
int teacherMenu();
int teacher(Course[], int, int);
int student(Course[], int, int, int);
int studentLogin(Course[], int, int);
int coursechoicefunction(int);
bool validIdlenght(string, int);
bool validIddigit(string);
bool validUniqueId(Course[], int, string, int);
bool functionexit();
bool teacherLogin();
bool checkEmptycourse(Course[], int);


#endif // !STUDENTLIST_H

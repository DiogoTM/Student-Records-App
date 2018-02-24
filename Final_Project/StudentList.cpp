#ifndef STUDENTLIST_H
#define STUDENTLIST_H


#include<iostream>
#include<string>
#include<iomanip>
#include <windows.h>
#define NUM_STUDENT 2

using namespace std;

struct StudentList
{
	int studentID;
	string firstName;
	string lastName;
	string username;
	string password;

};

int getMainMenuChoice();
void inputStudentData(StudentList[], int);
void displayStudentData(StudentList[], int);
void sortStudentData(StudentList[], int);
void searchStudentId(StudentList[], int);

#endif // !STUDENTLIST_H

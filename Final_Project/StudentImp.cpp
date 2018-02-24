#include "studentList.h"
//Student user functions
//This Implementation file contains functions that are used mainly by the student program

//=====================================
//Function to check the student login, if login is succesful the function returns the studentID, if not succesful it returns 0
int studentLogin(Course arrCourse[], int howmanystudents, int howmanycourses)
{
	system("cls");
	int login = 0;
	string pass;
	bool foundStudent = false;
	int loginSuccess = 0;
	system("cls");
	cout << "\n\n\tHello student, please enter your login: ";
	cin >> login;

	for (int i = 0; i < howmanycourses; i++)
	{
		for (int j = 0; j < howmanystudents; j++)
		{
			if (login == arrCourse[i].studentsEnrolled[j].studentID)
			{
				foundStudent = true;
				cout << "\n\n\tHello " << arrCourse[i].studentsEnrolled[j].firstName << ", please enter your password: ";
				cin.ignore();
				getline(cin, pass);
				if (pass == arrCourse[i].studentsEnrolled[j].password)
				{
					loginSuccess = login;
				}
			}
		}
	}
	if (!foundStudent)
	{
		cout << "\n\n\tStudent not found.";
	}
	return loginSuccess;
}
//=====================================
//Function to display the student menu, returns the user choice
int studentMenu()
{
	system("cls");
	int menuChoice;
	cout << "\n\n\tSTUDENT MENU" << endl;
	cout << "\n\n\t1. List your currently courses.";
	cout << "\n\n\t2. View a specific grade.";
	cout << "\n\n\t3 List all your grades .";
	cout << "\n\n\t4 Quit the application.";
	cout << "\n\n\tHello Student, please select one of the options: ";
	return (coursechoicefunction(4)+1);
}

//=====================================
//Function to check if the student Id is already entered in another course, it is not being used in this program
//int existingstudent(Course arrCourses[], int howmany, string tempId, int courseChoice, int howmanycourses)
//{
//	int tempIdint = atoi(tempId.c_str());
//
//	for (int j = 0; j < howmany; j++)
//	{
//		if (tempIdint == arrCourses[courseChoice].studentsEnrolled[j].studentID)
//		{
//			return j;
//		}
//		else
//		{
//			return -1;
//		}
//	}
//}

//=====================================

void displayStudentCourses(Course arrCourse[], int howmanystudents, int studentId, int howmanycourses)
//Function to display the courses the student is enrolled
{
	system("cls");
	cout << "\n\n\tYou are currently enrolled in the following courses: ";
	for (int i = 0; i < howmanycourses; i++)
	{
		for (int j = 0; j < howmanystudents; j++)
		{
			if (studentId == arrCourse[i].studentsEnrolled[j].studentID)
			{
				cout << "\n\n\t" << setw(15) << "Course Number" << setw(25) << "Course Title" << setw(15) << "Group " << endl;
				cout << "\t" << setw(15) << "==============" << setw(25) << "=============" << setw(15) << "======";
				cout << "\n\n\t" << setw(15) << arrCourse[i].courseNumber << setw(25) << arrCourse[i].courseTitle << setw(15) << arrCourse[i].courseGroup << endl;
			}
		}
	}
}

//=====================================
//Function to display the grades for a specific course
void displayStudentGradeSpecific(Course arrCourses[], int howmanystudents, int studentId, int howmanycourses)
{
	int coursechoice = 0;
	bool found = false;
	listCourses(arrCourses, howmanycourses);
	cout << "\n\n\tFor what course do you want to see your grades? (1, 2 or 3): ";
	coursechoice = coursechoicefunction(howmanycourses);
	system("cls");
	for (int j = 0; j < howmanystudents; j++)
	{
		if (studentId == arrCourses[coursechoice].studentsEnrolled[j].studentID)
		{
			found = true;
			displayheader(arrCourses, coursechoice);
			displayresult(arrCourses, coursechoice, j);
			break;
		}
	}
	if (!found)
	{
		cout << "\n\n\tStudent not found in the selected course.";
	}
}

//=====================================
//Function to display all the student grades
void displayStudentGrades(Course arrCourses[], int howmanystudents, int studentId, int howmanycourses)
{
	bool found = false;
	system("cls");
	for (int i = 0; i < howmanycourses; i++)
	{
		for (int j = 0; j < howmanystudents; j++)
		{
			if (studentId == arrCourses[i].studentsEnrolled[j].studentID)
			{
				found = true;
				displayheader(arrCourses, i);
				displayresult(arrCourses, i, j);
			}
		}
	}
}

//=====================================
//Function that performs the student program, returns a value to exit the program or no.

int student(Course arrCourse[], int howmanystudents, int howmanycourses, int login)
{
	int studentreturn = -1;

	switch (studentMenu()) //Calls the function to display the menu and get a valid choice
	{
	case 1:
		cout << "\n\n\t1. List your currently courses.";
		displayStudentCourses(arrCourse, howmanystudents, login, howmanycourses);
		break;
	case 2:
		cout << "\n\n\t2. View a specific grade.";
		displayStudentGradeSpecific(arrCourse, howmanystudents, login, howmanycourses);
		break;
	case 3:
		cout << "\n\n\t3 List all your grades .";
		displayStudentGrades(arrCourse, howmanystudents, login, howmanycourses);
		break;
	case 4:
		cout << "\n\n\t4 Quit the application.";
		system("cls");
		if (functionexit())
		{
			studentreturn = 0;
		}
	}
	cout << "\n\n\tPress any key to return to the main menu.";
	system("pause>>null");
	return studentreturn;
}
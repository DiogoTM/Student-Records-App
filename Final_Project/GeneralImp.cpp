#include "studentList.h"
//General use functions
//This Implementation file contains functions that are used by different parts of the program

//=====================================
//Check if the Id has the determined lenght 
bool validIdlenght(string tempId, int lenght)
{
	bool validLenght = false;
	if (tempId.length() != lenght)
	{
		validLenght = false;
	}
	else
	{
		validLenght = true;
	}
	return validLenght;
}

//=====================================
//Check if the Id is a number
bool validIddigit(string tempId)
{
	bool validDigit = false;
	int lenghtId = tempId.length();
	for (int i = 0; i < lenghtId; i++)
	{
		if (!isdigit(tempId[i]))
		{
			validDigit = false;
		}
		else
		{
			validDigit = true;
		}
	}
	return validDigit;
}

//=====================================
//Function to check if the Id entered is unique
bool validUniqueId(Course arrCourses[], int howmany, string tempId, int courseChoice)
{
	int tempIdint = atoi(tempId.c_str());

	for (int j = 0; j < howmany; j++)
	{
		if (tempIdint == arrCourses[courseChoice].studentsEnrolled[j].studentID)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

//=====================================
//Function to exit 
bool functionexit()
{
	char exit;
	cout << "\n\n\tAre you sure you want to EXIT the program (Y/N)? ";
	cin >> exit;
	if (toupper(exit) == 'Y')
	{
		return true;
	}
	else if (toupper(exit) == 'N')
	{
		return false;
	}
	else
	{
		cout << "\n\n\tPlease enter a valid choice.";
		return functionexit();
	}
}

//=====================================
//Function to enter a grade, it checks if it is between the range 0.00 ->100.00, returns the value if valid
float entergrade(Course arrCourses[], int coursechoice, int howmanystudents)
{
	string grade;
	bool gradeok = false;
	do
	{
		cin >> grade;
		if ((validIddigit(grade)) && (stof(grade) >= 0.0f) && (stof(grade) <= 100.0f))
		{
			gradeok = true;
			return stof(grade);
		}
		else
		{
			gradeok = false;
			cout << "\n\n\tInvalid entry, please retry (value between 0.0 and 100.0): ";
		}
	} while (!gradeok);
}

//=====================================
//Function to check if the choice entered is valid, returns the choice if valid
int coursechoicefunction(int howmanycourses)
{
	string tempcourse;
	bool choiceok = false;


	do
	{
		cin >> tempcourse;
		if (validIddigit(tempcourse) && (atoi(tempcourse.c_str()) <= howmanycourses))
		{
			choiceok = true;
			return (atoi(tempcourse.c_str()) - 1);
		}
		else
		{
			choiceok = false;
			cout << "\n\n\tInvalid course choice, please retry: ";
		}

	} while (!choiceok);
}

//=====================================
//Function to check if the course is empty
bool checkEmptycourse(Course arrCourses[], int howmanycourses)
{
	if (arrCourses[howmanycourses].studentTotal == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

//=====================================
//Function go to XY
void gotoXY(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD cursorLocation;
	cursorLocation.X = x;
	cursorLocation.Y = y;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, cursorLocation);
}

//=====================================
//Function to display the header of informations for determined course
void displayheader(Course arrCourses[], int coursechoice)
{
	
	system("cls");
	gotoXY(20, 4); cout << "Course Number :" << arrCourses[coursechoice].courseNumber << endl;
	gotoXY(20, 5); cout <<  "Course Title : " << arrCourses[coursechoice].courseTitle << endl;
	gotoXY(20, 6); cout <<  "Teacher : Quang Hoang Cao" << endl;
	gotoXY(20, 7); cout <<  "Session : Autumn 2016" << endl;
	gotoXY(20, 8); cout <<  "Group :" << arrCourses[coursechoice].courseGroup << endl;
	gotoXY(20, 9); cout <<  "ASSESSMENT SUMMARY" << endl;

	gotoXY(0, 11); cout << "Student ID";
	gotoXY(15, 11); cout << "Student Name";
	gotoXY(40, 11); cout << "Project";
	gotoXY(50, 11); cout << "Midterm";
	gotoXY(60, 11); cout << "Final";
	gotoXY(70, 11); cout << "Result";

	gotoXY(0, 12); cout << "==========";
	gotoXY(15, 12); cout << "========================";
	gotoXY(40, 12); cout << "========";
	gotoXY(50, 12); cout << "========";
	gotoXY(60, 12); cout << "=======";
	gotoXY(70, 12); cout << "========" << endl;
		
}

//=====================================
//Function to display the result of student search
void displayresult(Course arrCourses[], int coursechoice, int studentindex)
{
		cout << setw(10) << arrCourses[coursechoice].studentsEnrolled[studentindex].studentID;
		cout << setw(25) << arrCourses[coursechoice].studentsEnrolled[studentindex].firstName + " " + arrCourses[coursechoice].studentsEnrolled[studentindex].lastName;;
		cout << setw(10) << arrCourses[coursechoice].studentsEnrolled[studentindex].projectGrade;
		cout << setw(10) << arrCourses[coursechoice].studentsEnrolled[studentindex].midTermGrade;
		cout << setw(10) << arrCourses[coursechoice].studentsEnrolled[studentindex].finalExamGrade;
		cout << setw(10) << arrCourses[coursechoice].studentsEnrolled[studentindex].finalGrade << endl;
}

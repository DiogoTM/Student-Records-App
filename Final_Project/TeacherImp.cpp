#include "studentList.h"

//Teacher user functions
//This Implementation file contains functions that are used mainly by the teacher program

//=====================================
//Check if the teacher login was succesful
bool teacherLogin()
{
	system("cls");
	int login;
	string pass;
	bool loginSuccess = false;
	system("cls");
	cout << "\n\n\tHello teacher, please enter your login: ";
	cin >> login;
	
	//This function checks if the username and password entered are valid
	if (login == 5257)
	{
		do
		{
			cout << "\n\n\tHello Mr. Cao, please enter your password: ";
			cin >> pass;
		} while (pass != "quanghoang");
		loginSuccess = true;
		cout << "\n\n\tLogin successfull!";
	}
	else
	{
			cout << "\n\n\tTeacher not found.";
			loginSuccess = false;
	}
	return loginSuccess;
}

//=====================================
//Displays the teacher menu and returns the choice if valid
int teacherMenu()
{
	system("cls");
	int menuChoice;
	cout << "\n\n\tTEACHER MENU" << endl;
	cout << "\n\n\t1. List your currently courses.";
	cout << "\n\n\t2. Enter a student's grades.";
	cout << "\n\n\t3. Search student's grades.";
	cout << "\n\n\t4. Sort the student list by Student ID";
	cout << "\n\n\t5. List all student's grades.";
	cout << "\n\n\t6. Quit the application.";

	cout << "\n\n\tHello Teacher, please select one of the options: " ;
	return (coursechoicefunction(6) +1);

}
//=====================================
//Display the list of courses available using pointer
void listCourses(Course arrCourses[], int howmanycourses)
{
	int i = 1;

	system("cls");
	gotoXY(3, 3); cout << "Course Number";
	gotoXY(35, 3); cout << "Course Title";
	gotoXY(57, 3); cout << "Group ";
	gotoXY(65, 3); cout << "Students Total";
	gotoXY(0, 4); cout << "===============================================================================" << endl;

	for (Course *ptrArrCourses = arrCourses; ptrArrCourses <= &arrCourses[howmanycourses - 1]; ptrArrCourses++)
	{
		cout << setw(15) << ptrArrCourses->courseNumber << "|" << setw(30) << ptrArrCourses->courseTitle << "|" << setw(11) << ptrArrCourses->courseGroup << "|" << setw(10) << ptrArrCourses->studentTotal << endl;
	}
}


//=====================================
// Function to input student data for determined course
void inputStudentData(Course arrCourses[], int howmanystudents, int howmanycourses)
{
	string tempId[10] = { "" };
	bool isValidId = false;
	int studentID[10] = { 0 };
	int coursechoice;
	float tempmidterm;
	float tempproject;
	float tempfinal;

	// Asks for wich course the student data will be entered
	system("cls");	
	listCourses(arrCourses, howmanycourses);
	cout << "\n\n\tFor what course do you want to enter student's data? (1, 2 or 3): ";
	coursechoice = coursechoicefunction(howmanycourses);

	
	system("cls");
	for (int i = 0; i < howmanystudents; i++)
	{
		do
		{
			cout << "\n\n\tPlease enter the student " << i + 1 << " ID: ";
			cin >> tempId[i];
			//Tests the tempId entered
			if (validIdlenght(tempId[i], 7) && validIddigit(tempId[i]) && validUniqueId(arrCourses, howmanystudents, tempId[i], coursechoice))
			{
				isValidId = true;
			//If is valid, assign the value to the student ID
				arrCourses[coursechoice].studentsEnrolled[i].studentID = atoi(tempId[i].c_str());
				arrCourses[coursechoice].studentTotal = ++arrCourses[coursechoice].studentTotal;
			}
			else if (!validIdlenght(tempId[i], 7) || !validIddigit(tempId[i]) || !validUniqueId(arrCourses, howmanystudents, tempId[i], coursechoice))
			{
				isValidId = false;
				cout << "\n\tInvalid student ID!";
			}
		} while (!isValidId);
		cin.ignore();
		//Enter student name & password
		cout << "\n\n\tPlease enter the student " << i + 1 << " first name: ";
		getline(cin, arrCourses[coursechoice].studentsEnrolled[i].firstName);
		cout << "\n\n\tPlease enter the student " << i + 1 << " last name: ";
		getline(cin, arrCourses[coursechoice].studentsEnrolled[i].lastName);
		cout << "\n\n\tPlease enter the student " << i + 1 << " password: ";
		getline(cin, arrCourses[coursechoice].studentsEnrolled[i].password);

		//Enter student grades
		cout << "\n\n\tPlease enter the student " << i + 1 << " Mid Term Grade: ";
		arrCourses[coursechoice].studentsEnrolled[i].midTermGrade = entergrade(arrCourses, coursechoice, i);
		cout << "\n\n\tPlease enter the student " << i + 1 << " Project Grade: ";
		arrCourses[coursechoice].studentsEnrolled[i].projectGrade = entergrade(arrCourses, coursechoice, i);
		cout << "\n\n\tPlease enter the student " << i + 1 << " Final Exam Grade: ";
		arrCourses[coursechoice].studentsEnrolled[i].finalExamGrade = entergrade(arrCourses, coursechoice, i);
	
		//Calculates final grade
		arrCourses[coursechoice].studentsEnrolled[i].finalGrade = floor(((arrCourses[coursechoice].studentsEnrolled[i].finalExamGrade*0.4f) + (arrCourses[coursechoice].studentsEnrolled[i].projectGrade*0.3f) + (arrCourses[coursechoice].studentsEnrolled[i].midTermGrade*0.3f)) + 0.5f);
	}
}

//=====================================
//Sorts the student data of determined course by ascending order of student ID 
void sortStudentData(Course arrCourses[], int howmanystudents, int howmanycourses)
{
	system("cls");
	StudentList tempstudent;
	string tempfirst;
	string templast;
	string tempcourse;
	int coursechoice;

	system("cls");
	listCourses(arrCourses, howmanycourses);
	cout << "\n\n\tFor what course do you want to sort student's data? (1, 2 or 3): ";
	coursechoice = coursechoicefunction(howmanycourses);
	
	bool swap = true;
	while (swap)
	{
		swap = false;
		for (int i = 0; i < howmanystudents - 1; i++)
		{
			if (arrCourses[coursechoice].studentsEnrolled[i].studentID > arrCourses[coursechoice].studentsEnrolled[i + 1].studentID)
			{
				tempstudent = arrCourses[coursechoice].studentsEnrolled[i];
				arrCourses[coursechoice].studentsEnrolled[i] = arrCourses[coursechoice].studentsEnrolled[i + 1];
				arrCourses[coursechoice].studentsEnrolled[i + 1] = tempstudent;
				swap = true;
			}
		}
	}
	cout << "\n\n\t================================" << endl;
	cout << "\tStudent list sorted succesfuly!" << endl;
	cout << "\t================================" << endl;
}

//=====================================
//Search student by student ID
void searchStudentId(Course arrCourses[], int howmanystudents, int howmanycourses)
{
	system("cls");
	int searchID;
	bool found = false;

	cout << "\n\n\tPlease enter the student ID to be searched: ";
	cin >> searchID;

	for (int i = 0; i < howmanycourses; i++)
	{
		for (int j = 0; j < howmanystudents; j++)
		{
			if (searchID == arrCourses[i].studentsEnrolled[j].studentID)
			{
				found = true;
				displayheader(arrCourses, i);
				displayresult(arrCourses, i, j);
			}

		}
		if (!found)
		{
			cout << "\n\n\tStudent not found in the course:" << arrCourses[i].courseTitle << " - " << arrCourses[i].courseGroup << endl;
		}
	}
}

//=====================================
//Search student by first name
void searchStudentFirst(Course arrCourses[], int howmanystudents, int howmanycourses)
{
	system("cls");
	string searchFirst;
	bool found = false;

	cout << "\n\n\tPlease enter the student first name to be searched: ";
	cin.ignore();
	getline(cin, searchFirst);


	for (int i = 0; i < howmanycourses; i++)
	{
		for (int j = 0; j < howmanystudents; j++)
		{
			if (searchFirst == arrCourses[i].studentsEnrolled[j].firstName)
			{
				found = true;
				displayheader(arrCourses, i);
				displayresult(arrCourses, i, j);
			}		
		}			
		if (!found)
		{
			cout << "\n\n\tStudent not found in the course:" << arrCourses[i].courseTitle << " - " << arrCourses[i].courseGroup << endl;
		}
	}

}

//=====================================
//Search student by last name
void searchStudentLast(Course arrCourses[], int howmanystudents, int howmanycourses)
{
	system("cls");
	string searchLast;
	bool found = false;

	cout << "\n\n\tPlease enter the student last name to be searched: ";
	cin.ignore();
	getline(cin, searchLast);


	for (int i = 0; i < howmanycourses; i++)
	{
		for (int j = 0; j < howmanystudents; j++)
		{
			if (searchLast == arrCourses[i].studentsEnrolled[j].lastName)
			{
				found = true;
				displayheader(arrCourses, i);
				displayresult(arrCourses, i, j);
			}
		}
		if (!found)
		{
			cout << "\n\n\tStudent not found in the course:" << arrCourses[i].courseTitle << " - " << arrCourses[i].courseGroup << endl;
		}
	}
}

//=====================================
//Search student by full name
void searchStudentName(Course arrCourses[], int howmanystudents, int howmanycourses)
{
	system("cls");
	string searchName;
	bool found = false;

	cout << "\n\n\tPlease enter the student name to be searched: ";
	cin.ignore();
	getline(cin, searchName);


	for (int i = 0; i < howmanycourses; i++)
	{
		for (int j = 0; j < howmanystudents; j++)
		{
			if (searchName == arrCourses[i].studentsEnrolled[j].firstName + " " + arrCourses[i].studentsEnrolled[j].lastName)
			{
				found = true;
				displayheader(arrCourses, i);
				displayresult(arrCourses, i, j);
			}
		}
		if (!found)
		{
			cout << "\n\n\tStudent not found in the course:" << arrCourses[i].courseTitle << " - " << arrCourses[i].courseGroup << endl;
		}
	}
}

//=====================================
// List all the student's grades for determined course
void listAllstudentGrades(Course arrCourses[], int howmanystudents, int howmanycourses)
{
	int coursechoice;
	int passed = 0;
	int failed = 0;

	system("cls");
	listCourses(arrCourses, howmanycourses);
	cout << "\n\n\tFor what course do you want to see student's grades? (1, 2 or 3)";
	coursechoice = coursechoicefunction(howmanycourses);

	if (checkEmptycourse(arrCourses,coursechoice))
	{
		system("cls");
		displayheader(arrCourses, coursechoice);
		for (int i = 0; i < howmanystudents; i++)
		{
			displayresult(arrCourses, coursechoice, i);

			if (arrCourses[coursechoice].studentsEnrolled[i].finalGrade >= 60)
			{
				++passed;
			}
			else
			{
				++failed;
			}
		}
		cout << "..............................................................................." << endl;
		cout << "..............................................................................." << endl;

		cout << "\n\n\tNumber of students who passed the course: " << passed;
		cout << "\n\n\tNumber of students who failed the course: " << failed;
	}
	else
	{
		cout << "\n\n\tCourse empty.";
	}
}
//=====================================
//Function that performs the teacher program, returns a value to exit the program or no.
int teacher(Course arrCourses[], int howmanystudents, int howmanycourses)
{
	int searchchoice;
	int teacherreturn = -1;

	switch (teacherMenu())//Calls the function to display the menu and get a valid choice
	{
	case 1:
		cout << "\n\n\t1. List your currently courses.";
		listCourses(arrCourses, howmanycourses);
		break;
	case 2:
		cout << "\n\n\t2. Enter student's grades.";
		inputStudentData(arrCourses, howmanystudents, howmanycourses);
		break;
	case 3://Asks for what kind of search will be performed
		system("cls");
		cout << "\n\n\t3. Search student's grades.";
		cout << "\n\n\tDo you want to search by: ";
		cout << "\n\n\t1. ID";
		cout << "\n\n\t2. First Name";
		cout << "\n\n\t3. Last Name";
		cout << "\n\n\t4. Full Name";
		cout << "\n\n\tPlease enter your choice(1 - 4) : ";
		cin >> searchchoice;
		switch (searchchoice)
		{
		case 1:
			searchStudentId(arrCourses, howmanystudents, howmanycourses);
			break;
		case 2:
			searchStudentFirst(arrCourses, howmanystudents, howmanycourses);
			break;
		case 3:
			searchStudentLast(arrCourses, howmanystudents, howmanycourses);
			break;
		case 4:
			searchStudentName(arrCourses, howmanystudents, howmanycourses);
			break;
		}
		break;
	case 4:
		cout << "\n\n\t4. Sort the student list by Student ID";
		sortStudentData(arrCourses, howmanystudents, howmanycourses);
		break;
	case 5:
		cout << "\n\n\t5 List all student's grades.";
		listAllstudentGrades(arrCourses, howmanystudents, howmanycourses);
		break;
	case 6:
		if (functionexit())
		{
			teacherreturn = 0;
		}
		break;
	}
	cout << "\n\n\tPress any key to continue.";
	system("pause>>null");
	return teacherreturn;
}



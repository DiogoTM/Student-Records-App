#include "studentList.h"
#define NUM_STUDENT 2
#define NUM_COURSES 3

//Main Application file

//=========================================================
int main()
{
	int choicemenu1;
	int login;
	bool exit = false;

	//Declaration of the array arrCourses, it cointains the information about the courses being given. This information is not entered in run time.
	Course arrCourses[NUM_COURSES];

	arrCourses[0].courseNumber = "1. 420-P16-AS";
	arrCourses[0].courseTitle = "Structured Programming";
	arrCourses[0].courseGroup = 7150;
	arrCourses[0].studentTotal = 0;

	arrCourses[1].courseNumber = "2. 420-P16-AS";
	arrCourses[1].courseTitle = "Structured Programming";
	arrCourses[1].courseGroup = 7160;
	arrCourses[1].studentTotal = 0;

	arrCourses[2].courseNumber = "3. 420-P34-AS";
	arrCourses[2].courseTitle = "Advanced Object Programming";
	arrCourses[2].courseGroup = 7256;
	arrCourses[2].studentTotal = 0;

	//First screen displayed, cointains information about the course, the student and the program
	cout << "\n\n\tFINAL PROJECT - ASSESSEMENT SUMMARY";
	cout << "\n\n\t===================================" << endl;
	cout << "\tStudent: Diogo Teixeira Machado" << endl;
	cout << "\tCourse Number 420-P16-AS" << endl;
	cout << "\tStructured Programming" << endl;
	cout << "\tTeacher: Quang Hoang Cao" << endl;
	cout << "\tAutumn 2016" << endl;
	cout << "\tGroup 7150" << endl;
	cout << "\t===================================" << endl;
	cout << "\n\n\tThis program was developed to be used by a teacher or a student,";
	cout << "\there you will be capable of enter and/or see information about your classes.";
	cout << "\tIn the next step please choose the option that best suits yourself." << endl;
	cout << "\n\n\tPress any key to continue.";
	system("pause>>null");

	//Displays the main menu and call the functions for the teacher and the student programs
	do
	{
		system("cls");
		cout << "\n\n\tHello, welcome! Which kind of user are you? ";
		cout << "\n\n\t1. Teacher Program";
		cout << "\n\n\t2. Student Program";
		cout << "\n\n\t3. Exit the Program" << endl;
		cout << "\n\n\tPlease enter your choice: ";
		cin >> choicemenu1;

		switch (choicemenu1)

		{
		case 1://Teacher program

			if (teacherLogin()) //If teacher login is successfull, calls the function teacher
			{
				do
				{
					teacher(arrCourses, NUM_STUDENT, NUM_COURSES);
				} while (teacher(arrCourses, NUM_STUDENT, NUM_COURSES) != 0);// Run the program until the function teacher returns the value 0
			} 
			else
			{
				cout << "\n\n\tPress any key to return to the main menu.";
				system("pause>>null");
			}
			break;
		
		case 2://Student program
			login = studentLogin(arrCourses, NUM_STUDENT, NUM_COURSES); //If login is succesful the function studentlogin returns the studentID, if not succesful it returns 0
			
			if (login != 0)
			{
				do
				{
					student(arrCourses, NUM_STUDENT, NUM_COURSES, login);
				} while (student(arrCourses, NUM_STUDENT, NUM_COURSES, login) != 0);// Run the program until the function student returns the value 0
			}
			else
			{
				cout << "\n\n\tPress any key to return to the main menu.";
				system("pause>>null");				
			}
			break;
		case 3://Calls the function to exit
			exit = functionexit();
			if (exit == true)
			{
				return EXIT_SUCCESS;
			}
		}
	} while (!exit);
}
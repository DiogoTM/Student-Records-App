{
string tempId[10] = { "" };
bool isValidId = false;
int studentID[10] = { 0 };
int max = 0;
string a = "";
bool wannaAnotherStudent = true;


do
{
	wannaAnotherStudent = true;
	max++;
	isValidId = false;
	do
	{
		cin.clear();
		cout << "\n\t" << max << ". Please enter Student ID (7 digits) : ";
		cin >> tempId[max];
		if (tempId[max].length() != 7)
		{
			isValidId = false;


		}
		else
		{
			isValidId = true;
			for (int i = 0; i < tempId[max].length(); i++)
			{
				if (!isdigit(tempId[max][i]))
				{
					isValidId = false;
					break;
				}
				else
				{
					isValidId = true;
				}
			}
			for (int j = 0; j < max; j++)
			{
				if (tempId[max] == tempId[j])
				{
					isValidId = false;
					cout << "\n\n\tDuplicated ID";
					system("pause>>null");
					break;
					break;

				}
				else
				{
					isValidId = true;
				}
			}
		}
	} while (!isValidId);
	if (isValidId)
	{
		studentID[max] = atoi(tempId[max].c_str());
		cout << "\n\n\t" << studentID[max];
	}
	else
	{
		cout << "\n\tInvalid student ID!";
	}


	cout << "\n\n\tAnother Student? y/n ";
	cin >> a;
	cin.clear();


	if (a != "y"&&a == "Y")
	{
		wannaAnotherStudent = false;
	}
} while (wannaAnotherStudent == true);
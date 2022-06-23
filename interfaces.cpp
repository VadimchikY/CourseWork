#include "interfaces.h"

int getCountOfStructuresInFile(string file_path)
// ����������� ���������� �������� � �����
{
	ifstream file(file_path, ios::in); // ������� ��������� ���� ��� ������
	int number_of_strings = 0;
	if (file.is_open())
	{
		if (file.peek() == EOF)
			return 0;
		while (file.ignore(numeric_limits<streamsize>::max(), '\n'))
			number_of_strings++;
	}
	file.close();
	return number_of_strings;
}
char outputMainMenu()
//����� �������� ������� � ����� 
{
	cout << "1| �����\n";
	cout << "2| �����������\n";
	cout << "0| �����\n";
	return choiceAction('0', '2');
}
void inputInfoAboutProgram()
//�������� ,������ ����
{
	cout << "\n\n\n\n";
	cout << "                     ����������� ��������������� �����������\n";
	cout << "                         ����������� � ����������������\n\n\n\n";
	cout << "                         ������ ��������������� ��������\n\n\n";
	cout << "                                 �������� ������\n";
	cout << "                                     �� ����\n";
	cout << "                 ���������� ��������� ������������ ������� �������\n\n\n";
	cout << "�������� ������� ������: 010101 ������� ����� ���������\n\n";
	cout << "�������������: �������� ������ ����������\n";
	cout << "\n\n\n\n\n\n                                   ����� 2021";
	_getch();
}



void System(vector <Accounts>& vector_of_accs, vector <Workers>& vector_of_workers)
//�������� ���������
{
	bool mainMenuFlag = 1;
	do
	{
		string signedAccount;
		int role;
		switch (outputMainMenu())
		{
		case '1':
			role = -1;
			signedAccount = loginAccount(vector_of_accs, role);
			_getch();
			system("cls");
			if (role == 1)
				adminInterface(vector_of_accs,vector_of_workers, signedAccount);
			if (role == 0)
				userInterface(vector_of_accs, vector_of_workers, signedAccount);
			break;
		case '2':
			registeringAccount(vector_of_accs);
			break;
		case '0':
			if (confirmAction("�����"))
			{
				inputInfoAboutProgram();
				mainMenuFlag = 0;
			}
			break;
		}
	} while (mainMenuFlag);
}

void adminInterface(vector <Accounts>& vector_of_accs, vector <Workers>& vector_of_workers, string login)
//��������� ���������
{
	bool adminMenuFlag = 1;
	do
	{
		switch (outputAdminMenu(login))
		{
		case '1':
			workingWithAccounts(vector_of_accs, login);
			break;
		case '2':
			workingWithWorkersAdmin(vector_of_workers);
			break;
		case '3':
			login =changeLogin(vector_of_accs, login);
			break;
		case '4':
			changePassword(vector_of_accs, login);
			break;
		case '0':
			if (confirmAction("����� �� ��������"))
				adminMenuFlag = 0;
			break;
		}
		system("cls");
	} while (adminMenuFlag);
}


char outputAdminMenu(string login)
//����� � ���������� ����������
{
	cout << "------" << login << "(admin)------\n";
	cout << "1| ������ � �������� ��������\n";
	cout << "2| ������ � �������\n\n";
	cout << "3| ����� ������ ������� ������\n";
	cout << "4| ����� ������ ������� ������\n";
	cout << "0| �����\n";
	return choiceAction('0', '4');
}
void workingWithAccounts(vector <Accounts>& vector_of_accs, string login)
//�������� ������ � ���������� ��� ������
{
	bool menuFlag = 1;
	do
	{
		outputAllAccounts(vector_of_accs);
		switch (outputWorkingWithAccountsMenu())
		{

		case '1':
			verificationAccount(vector_of_accs);
			break;
		case '2':
			deleteUserAccount(vector_of_accs,login);
			break;
		case '3':
			changeRoleAccount(vector_of_accs, login);
			break;
		case '0':
			menuFlag = 0;
			break;
		}
		system("cls");
	} while (menuFlag);
}
char outputWorkingWithAccountsMenu()
//���� ��� ���� ��� ������
{
	cout << "1| ����������� ������� �������\n";
	cout << "2| ��������� ������� �������\n";
	cout << "3| ��������� ���� ������� �������\n";
	cout << "0| �����\n";
	return choiceAction('0', '3');
}


void workingWithWorkersAdmin(vector <Workers>& vector_of_workers)
//��������� ������ � ������� ������� ��� �������
{
	bool menuFlag = 1;
	do
	{
		outputAllWorkers(vector_of_workers);
		switch (outputWorkingWithWorkersMenu())
		{
		case '1':
			addWorker(vector_of_workers);
			break;
		case '2':
			editWorker(vector_of_workers);
			break;
		case '3':
			deleteWorker(vector_of_workers);			
			break;
		case '4':
			individualTask(vector_of_workers);
			break;
		case '5':
			sortByCompany(vector_of_workers);
			break;
		case '6':
			sortByWork(vector_of_workers);
			break;
		case '7':
			sortByHours(vector_of_workers);
			break;
		case '8':
			sortByMoney(vector_of_workers);
			break;
		case '0':
			menuFlag = 0;
			break;
		}
		system("cls");
	} while (menuFlag);
}
char outputWorkingWithWorkersMenu()
//���� � ���� ��� ������
{
	cout << "1| �������� ������\n";
	cout << "2| ������������ ������\n";
	cout << "3| ������� ������\n";
	cout << "4| �������������� �������\n";
	cout << "5| ������������ �� �������� �������\n";
	cout << "6| ������������ �� ���� ������\n";
	cout << "7| ������������ �� ���������� �����\n";
	cout << "8| ������������ �� ���������� �����\n";
	cout << "0| �����\n";

	return choiceAction('0', '8');
}


void userInterface(vector <Accounts>& vector_of_accs, vector <Workers>& vector_of_workers, string login)
//��������� ������������
{
	bool userMenuFlag = 1;
	do
	{
		switch (outputUserMenu(login))
		{
		case '1':
			workingWithWorkersUser(vector_of_workers);
			break;
		case '2':
			if (workingWithAccountByUser(vector_of_accs, login))
				userMenuFlag = 0;
			break;
		case '0':
			if (confirmAction("����� �� ��������"))
				userMenuFlag = 0;
			break;
		}
		system("cls");
	} while (userMenuFlag);
}

char outputUserMenu(string login)
//���� � ���� ��� ������
{
	cout << "--------" << login << "--------\n";
	cout << "1| ������ � �������\n";
	cout << "2| ������ �� ����� ������� �������\n";
	cout << "0| �����\n";
	return choiceAction('0', '2');
}
bool workingWithAccountByUser(vector <Accounts>& vector_of_accs, string login)
//��������� ����� ��� ������ � ����������� ������ ����
//������ 0-���� ��� ������ 1-���� ������� ������ � ��������� ����� � ��������� ����
{
	bool menuFlag = 1;
	do
	{
		switch (outputWorkingWithUserAccountMenu())
		{
		case '1':
			login = changeLogin(vector_of_accs, login);
			break;
		case '2':
			changePassword(vector_of_accs, login);
			break;
		case '3':
			if(deleteYourselfAccount(vector_of_accs, login))
				return 1;
			break;
		case '0':
			menuFlag = 0;
			break;
		}
		system("cls");
	} while (menuFlag);
	return 0;
}
char outputWorkingWithUserAccountMenu()
{
	cout << "1| ����� ������ ������� ������\n";
	cout << "2| ����� ������ ������� ������\n";
	cout << "3| �������� ����� �������� ������\n";
	cout << "0| �����\n";
	return choiceAction('0', '3');
}

void workingWithWorkersUser(vector <Workers>& vector_of_workers)
//��������� ��� ������ � ������� ������� ��� �����
{
	bool menuFlag = 1;
	do
	{
		outputAllWorkers(vector_of_workers);
		switch (outputWorkingWithWorkersMenuUser())
		{
		case '1':
			individualTask(vector_of_workers);
			break;
		case '2':
			sortByCompany(vector_of_workers);
			break;
		case '3':
			sortByWork(vector_of_workers);
			break;
		case '4':
			sortByHours(vector_of_workers);
			break;
		case '5':
			sortByMoney(vector_of_workers);
			break;
		case '0':
			menuFlag = 0;
			break;
		}
		system("cls");
	} while (menuFlag);
}
char outputWorkingWithWorkersMenuUser()
{
	cout << "1| �������������� �������\n";
	cout << "2| ������������ �� �������� �������\n";
	cout << "3| ������������ �� ���� ������\n";
	cout << "4| ������������ �� ���������� �����\n";
	cout << "5| ������������ �� ���������� �����\n";
	cout << "0| �����\n";
	return choiceAction('0', '5');
}
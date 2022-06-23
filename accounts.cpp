#include "accounts.h"


void readFileAccounts(vector <Accounts>& vector_of_accs)
//������� �� ����� ������ �� ���������(���� ��� ��� - ��������)
{
	ifstream fin(FILE_OF_ACCOUNTS, ios::in); // ������� ���� ��� ������
	if ((!fin.is_open()) || vector_of_accs.empty())
	{
		ofstream fout(FILE_OF_ACCOUNTS);
		fout.close();
		string salt = generateSalt(SALT_SIZE);
		string salted_hash_password = sha256("adminus" + salt);
		Accounts temp;
		temp.login = "adminus";
		temp.salt = salt;
		temp.salted_hash_password = salted_hash_password;
		temp.role = 1;
		temp.access = 1;
		vector_of_accs.push_back(temp);
	}
	else
	{
		int i = 0;
		while (!fin.eof())
		{
			fin >> vector_of_accs[i].login
				>> vector_of_accs[i].salt
				>> vector_of_accs[i].salted_hash_password
				>> vector_of_accs[i].role
				>> vector_of_accs[i].access;
			i++;
		}
	}
	fin.close(); //������� ����
}
void writeFileAccounts(const vector <Accounts>& vector_of_accs)
//������� � ���� ������ �� ���������
{
	ofstream fout(FILE_OF_ACCOUNTS, ios::out); // ������� ���� ��� ������

	for (int i = 0; i < vector_of_accs.size(); i++)
	{
		fout << vector_of_accs[i].login << " "
			<< vector_of_accs[i].salt << " "
			<< vector_of_accs[i].salted_hash_password << " "
			<< vector_of_accs[i].role << " "
			<< vector_of_accs[i].access;

		if (i < vector_of_accs.size() - 1)
			fout << endl;
	}
	fout.close();
}

string inputPass() // �-� ����� ������
//���� ������ �� *
{
	string pass;
	int symbol;
	while (true)
	{
		symbol = _getch();// �������� ������ � ������� � �� �������
		if (symbol == 13) // ���� ��� ������� enter �� ��������� ������ � ������� �� �����
		{
			cout << endl;
			break;
		}
		else
		{
			if (symbol == 8) // ���� ��� ������� backspace ��:1 ���� ������ ����� ������ �� ������
			{
				if (!pass.empty()) //2 ���� ����� ����:������� ��������� ������ � ������ � ����������� ������ �����, ������� * �������� � ����� �������
				{
					pass.erase(pass.length() - 1);
					cout << (char)8 << ' ' << (char)8;
				}
			}
			else
			{
				cout << '*';
				pass += (char)symbol;
			}
		}
	}
	return pass;
}

void registeringAccount(vector <Accounts>& vector_of_accs)
//����������� ���� � ��������
{
	string login, password, password2;
	bool flagLogin = 1, flagTotalPass = 1;

	cout << "����������� ��������:\n";
	while (flagLogin)
	{
		cout << "���������� �����:\n-> ";
		cin >> login;
		flagLogin = checkString(login);
		for (int i = 0; i < vector_of_accs.size(); i++)
		{
			if (vector_of_accs[i].login == login)
			{
				cout << "������� � ����� ������� ��� ����������,��������� ������� � ������ �������.\n";
				flagLogin = 1;
			}
		}
	}
	while (flagTotalPass)
	{
		bool flagPass = 1;
		while (flagPass)
		{
			cout << "���������� ������:\n-> ";
			password = inputPass();
			flagPass = checkString(password);
		}
		flagPass = 1;
		while (flagPass)
		{
			cout << "��������� ������:\n-> ";
			password2 = inputPass();
			flagPass = checkString(password);
		}
		if (password == password2)
		{
			flagTotalPass = 0;
		}
		else
		{
			cout << "������:������ �� ���������.���������� ���.\n";
		}
	}
	cout << "������� ���������������! �������� ������������� ���������������.\n";

	string salt = generateSalt(SALT_SIZE);
	string salted_hash_password = sha256(password + salt);

	Accounts temp;
	temp.login = login;
	temp.salt = salt;
	temp.salted_hash_password = salted_hash_password;
	temp.role = 0;
	temp.access = 0;
	vector_of_accs.push_back(temp);
	_getch();
	system("cls");
}
string loginAccount(const vector <Accounts>& vector_of_accs, int& role)
//�-� ��������� � ������� 1-���� ��� ����� 0-���� ��� ���� (-1)-���� �� ��������
{
	string login, password;
	cout << "������� �����:\n-> ";
	cin >> login;
	cout << "������� ������\n-> ";
	password = inputPass();

	for (int i = 0; i < vector_of_accs.size(); i++)
		if (vector_of_accs[i].login == login)
		{
			if (vector_of_accs[i].salted_hash_password == sha256(password + vector_of_accs[i].salt))
			{
				if (vector_of_accs[i].access == 0)
				{
					cout << "������� ������� ����������� ��� �� �������.\n";
					_getch();
					return "";
				}
				else
				{
					cout << "�� ����� ��� " + login;
					if (vector_of_accs[i].role == 1)
					{
						cout << "(admin)\n";
						role = 1;
					}
					else
					{
						cout << endl;
						role = 0;
					}
					return login;
					;
				}
			}
			else
				break;

		}
	cout << "�� ������� �����.\n����������, ��������� ������������ ��������� ������.\n";
	return  "";
}

string changeLogin(vector <Accounts>& vector_of_accs, string login)
//����� ������
{
	cout << "----������� ����� ������----\n";
	cout << "��� ������� �����:\n" << login << endl;
	string new_login;
	do
	{
		cout << "������� ��� ����� �����:\n-> ";
		cin >> new_login;
	} while (checkString(new_login));
	for (int i = 0; i < vector_of_accs.size(); i++)
		if (vector_of_accs[i].login == login)
		{
			vector_of_accs[i].login = new_login;
			break;
		}
	cout << "����� ������� ������ �� " + new_login << endl;
	_getch();
	return new_login;

}
void changePassword(vector <Accounts>& vector_of_accs, string login)
//����� ������
{
	cout << "----������� ����� ������----\n";
	cout << "������� ��� ������� ������:\n-> ";
	string password = inputPass();

	int cell_number;
	for (cell_number = 0; cell_number < vector_of_accs.size(); cell_number++) //������� ����� ������ ��� ��������� ������ ����� ����
	{
		if (vector_of_accs[cell_number].login == login)
			break;
	}
	if (sha256(password + vector_of_accs[cell_number].salt) == vector_of_accs[cell_number].salted_hash_password)
	{
		bool flagTotalPass = 1;
		string password2;
		while (flagTotalPass)
		{
			bool flagPass = 1;
			while (flagPass)
			{
				cout << "���������� ����� ������:\n-> ";
				password = inputPass();
				flagPass = checkString(password);
			}
			flagPass = 1;
			while (flagPass)
			{
				cout << "��������� ����� ������:\n-> ";
				password2 = inputPass();
				flagPass = checkString(password);
			}
			if (password == password2)
				flagTotalPass = 0;
			else
				cout << "������:������ �� ���������.���������� ���.\n";
		}
		string new_salt = generateSalt(SALT_SIZE);
		string new_salted_hash_password = sha256(password + new_salt);
		vector_of_accs[cell_number].salt = new_salt;
		vector_of_accs[cell_number].salted_hash_password = new_salted_hash_password;
		cout << "������ ������� ������.\n";

	}
	else
	{
		cout << "������ �������!\n";
		
	}
	_getch();

}

void verificationAccount(vector <Accounts>& vector_of_accs)
//�-� ����������/������� �������
{
	while (true)
	{
		cout << left << setw(4) << "�" << left << setw(18) << "user login" << left << setw(6) << "access" << endl;
		cout << "----------------------------\n";

		vector <string> temp_vector;
		int number_user_accs = 0;

		for (int i = 0; i < vector_of_accs.size(); i++)
		{
			if (vector_of_accs[i].role == 0)
			{
				temp_vector.push_back(vector_of_accs[i].login);
				number_user_accs++;
				cout << left << setw(4) << number_user_accs << left << setw(18) << vector_of_accs[i].login;
				if (vector_of_accs[i].access == 1)
					cout << left << setw(6) << "admit";
				else
					cout << left << setw(6) << "not";
				cout << endl;
			}
		}
		if (number_user_accs == 0)
		{
			cout << "������ ������������� ����!\n";
			_getch();
			system("cls");
			return;
		}
		cout << "\n\n\n";
		cout << "�������� ���� �� ������ �������� ������(0-�����):\n-> ";
		int choice = getInt(0, number_user_accs);
		if (choice == 0)
			return;
		string changing_access_login = temp_vector[choice - 1];
		for (int i = 0; i < vector_of_accs.size(); i++)
		{
			if (vector_of_accs[i].login == changing_access_login)
			{
				if (vector_of_accs[i].access == 1)
					vector_of_accs[i].access = 0;
				else
					vector_of_accs[i].access = 1;
				break;
			}
		}
		system("cls");
	}

}
void outputAllAccounts(vector <Accounts>& vector_of_accs)
//����� ���� �����
{
	cout << left << setw(4) << "�" << left << setw(18) << "login" << left << setw(7) << "role" << left << setw(6) << "access" << endl;
	cout << "-----------------------------------\n";
	for (int i = 0; i < vector_of_accs.size(); i++)
	{
		cout << left << setw(4) << i + 1 << left << setw(18) << vector_of_accs[i].login;
		if (vector_of_accs[i].role == 1)
			cout << left << setw(7) << "admin";
		else
			cout << left << setw(7) << "user";
		if (vector_of_accs[i].access == 1)
			cout << left << setw(6) << "admit";
		else
			cout << left << setw(6) << "not";
		cout << endl;
	}
	cout << "\n\n\n";
}
void deleteUserAccount(vector <Accounts>& vector_of_accs, string your_login)
//�������� ���� �����
{
	outputAllAccounts(vector_of_accs);
	cout << "��������, ����� ���������� ������������(0-�����):\n-> ";
	int choice = getInt(0, vector_of_accs.size());
	if (choice == 0)
		return;
	choice--;
	if (vector_of_accs[choice].login == your_login)
	{
		cout << "������ ������� ������ ����(((\n";
		_getch();
		return;
	}
	if (vector_of_accs[choice].role == 1)
	{
		cout << "������ ������� �������.\n";
		_getch();
		return;
	}
	if (confirmAction("������� ������������ " + vector_of_accs[choice].login))
	{
		cout << "������������ " << vector_of_accs[choice].login << " ������� ������.\n";
		_getch();
		vector_of_accs.erase(vector_of_accs.cbegin() + choice);
	}
}
void changeRoleAccount(vector <Accounts>& vector_of_accs, string your_login)
//��������� ������
{
	while (true)
	{
		cout << left << setw(4) << "�" << left << setw(18) << "login" << left << setw(6) << "role" << endl;
		cout << "----------------------------\n";

		vector <string> temp_vector;
		int number_admit_accs = 0;

		for (int i = 0; i < vector_of_accs.size(); i++)
		{
			if (vector_of_accs[i].access == 1)
			{
				temp_vector.push_back(vector_of_accs[i].login);
				number_admit_accs++;
				cout << left << setw(4) << number_admit_accs << left << setw(18) << vector_of_accs[i].login;
				if (vector_of_accs[i].role == 1)
					cout << left << setw(6) << "admin";
				else
					cout << left << setw(6) << "user";
				cout << endl;
			}
		}
		cout << "\n\n\n";
		cout << "�������� ���� �� ������ �������� ����(0-�����):\n-> ";
		int choice = getInt(0, number_admit_accs);
		if (choice == 0)
			return;
		if (temp_vector[choice - 1] == your_login)
		{
			cout << "�� �� ������ �������� ���� ����!\n";
			_getch();
			continue;
		}
		string changing_role_login = temp_vector[choice - 1];
		for (int i = 0; i < vector_of_accs.size(); i++)
		{
			if (vector_of_accs[i].login == changing_role_login)
			{
				if (vector_of_accs[i].role == 1)
					vector_of_accs[i].role = 0;
				else
					vector_of_accs[i].role = 1;
				break;
			}
		}
		system("cls");
	}

}

bool deleteYourselfAccount(vector <Accounts>& vector_of_accs, string your_login)
//�-� �������� ������ ���� ��� �����
{
	//������ 0-���� ��� ������ 1-���� ������� ������ � ��������� ����� � ��������� ����
	cout << "----��������� �������� ������ ��������----\n";
	if (confirmAction("��������� ������� ���� �������"))
	{
		int i;
		for (i = 0; i < vector_of_accs.size(); i++)
			if (vector_of_accs[i].login == your_login)
				break;
		vector_of_accs.erase(vector_of_accs.cbegin() + i);
		return 1;
	}
	return 0;
}



string generateSalt(int salt_size)
//��������� ����
{
	string symbols = getSymbolsForSalt();
	srand(time(0));
	string salt;
	salt.reserve(salt_size);

	for (int i = 0; i < salt_size; i++)
		salt.push_back(symbols[rand() % SYMBOLS_SIZE]);
	return salt;

}
string getSymbolsForSalt()
{
	string symbols;
	symbols.reserve(SYMBOLS_SIZE);
	char little_latter = 'a';
	char big_latter = 'A';
	char number = '0';
	int i;
	for (int j = 0; j < 26; j++)
	{
		symbols.push_back(little_latter++);
		symbols.push_back(big_latter++);
		if (j < 10)symbols.push_back(number++);
	}
	return symbols;
}
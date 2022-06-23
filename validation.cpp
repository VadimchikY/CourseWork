#include "validation.h"

bool checkString(string str)
//�������� ������ �� �������� ������� 1-������ � ������� 0-������ �����
{
	int size = str.length();
	for (int i = 0; i < size; i++)
	{
		if (!((str[i] >= 'a' && str[i] <= 'z') ||
			(str[i] >= 'A' && str[i] <= 'Z') ||
			(str[i] >= '0' && str[i] <= '9') ||
			str[i] == '_' || str[i] == '.'
			))//���� ������������ �������
		{
			cout << "������:������������ �������.(����������� �������:[a-z][A-Z][0-9]� '_' � '.')\n";
			return 1;
		}
		if (!(size > 3 && size < 17))
		{
			cout << "������:���������� ������ 4-16 ��������\n";
			return 1;
		}
	}
	return 0;//���� ������ ��������
}
//������ ������ ����� �� ��������� 
int getInt(int begin, int end)
//�-� ��� ����� ������ ������ �������� �� ���������(�����������) ��������� 
{
	int input;

	while (true)
	{
		cin >> input;
		if (cin.get() != '\n') // ���� ������ �����������
		{
			cout << "������������ ����,������� ���������� ��������!\n-> ";

			cin.clear(); // ��������������� �����
			cin.ignore(32767, '\n'); // ���������� �� �� \n
		}
		else
		{
			if (!(input >= begin && input <= end))
			{
				cout << "������������ ����!(���������� �������� [" << begin << ";" << end << "] ������� ���������� ��������!\n-> ";
				continue; // ������������ � ����� ��� ���
			}
			break; // ���� ������ ���������, ������������� ����
		}
	}

	return input;
}
//����� �������� 
char choiceAction(char begin, char end)
//�-� ��� ���������� � ���������� ������ �������� � �������� ��������
{
	char choice;
	do
	{
		choice = _getch();
	} while (!(choice >= begin && choice <= end));
	system("cls");
	return choice;
}
//������������� ������������ ��������
bool confirmAction(string str)
//1-���������� 0-������
//�-� ��� ������������� ������������ ��������
{
	cout << "�� ������������� ������ " + str + "?\n";
	cout << "1| ��\n";
	cout << "2| ���\n";
	char choice;
	do
	{
		choice = _getch();
	} while (!(choice == '1' || choice == '2'));
	system("cls");
	if (choice == '1')
		return 1;
	else
		return 0;

}
//���� ����� � ���������
string inputName()
//�-� ��� ����� �������� �������� ��� ����� ����� � ���������
{
	bool flag;
	string work;
	do
	{
		flag = 0;
		cin >> work;
		for (int i = 0; i < work.size(); i++)
		{
			if (!((work[i] >= 'a' && work[i] <= 'z') ||
				(work[i] >= 'A' && work[i] <= 'Z') ||
				(work[i] >= '�' && work[i] <= '�') ||
				(work[i] >= '�' && work[i] <= '�') ||
				work[i] == '(' || work[i] == ')' ||
				work[i] == '_'))
			{
				cout << "������:������������ ������.��������� ����.\n-> ";
				flag = 1;
				break;
			}
		}

	} while (flag);
	return work;
}
//���� �������� ������
string inputCompany()
//�-� ��� ����� ����� �������� �������� ������

{
	bool flag;
	string company;
	do
	{
		flag = 0;
		cin >> company;
		for (int i = 0; i < company.size(); i++)
		{
			if (company[i]==' ')
			{
				cout << "������:������������ ������(������).��������� ����.\n-> ";
				flag = 1;
				break;
			}
		}

	} while (flag);
	return company;
}


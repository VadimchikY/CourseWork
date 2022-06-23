#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#include "sha256.h"
#include "validation.h"

using namespace std;

struct Accounts
{
	string login;//����� ��������
	string salt;//���� ��� �����������
	string salted_hash_password;//�������������� ������ � �����
	int role;//����,1-����� 0-����
	int access;//������,1-�������� 0-���
};

const string FILE_OF_ACCOUNTS = "AccData.txt";

const int SALT_SIZE= 12;
const int SYMBOLS_SIZE = 62;
//������� ���� �� �����
void readFileAccounts(vector <Accounts>& vector_of_accs);
//�������� ���� � ����
void writeFileAccounts(const vector <Accounts>& vector_of_accs);
//���� ������
string inputPass();
//����������� �������� 
void registeringAccount(vector <Accounts>& vector_of_accs);
//���� � �������
string loginAccount(const vector <Accounts>& vector_of_accs, int& role);
//����� ������
string changeLogin( vector <Accounts>& vector_of_accs,string login);
//����� ������
void changePassword(vector <Accounts>& vector_of_accs, string login);
//����� ���� ���������
void outputAllAccounts(vector <Accounts>& vector_of_accs);
//����������� ��������(����� ����)
void verificationAccount(vector <Accounts>& vector_of_accs);
//�������� �������� �����
void deleteUserAccount(vector <Accounts>& vector_of_accs,string your_login);
//����� ���� ��������
void changeRoleAccount(vector <Accounts>& vector_of_accs,string your_login);
//�������� ���� ������
bool deleteYourselfAccount(vector <Accounts>& vector_of_accs, string your_login);



string generateSalt(int salt_size);
string getSymbolsForSalt();

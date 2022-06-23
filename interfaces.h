#pragma once

#include <string>
#include <vector>
#include <iomanip>


#include "validation.h"
#include "accounts.h"
#include "workers.h"




//��������� ���������� ��������
int getCountOfStructuresInFile(string file_path);
//����� ���������� � �����
void inputInfoAboutProgram();
//����� ��������� ����
char outputMainMenu();
//�������� ���������
void System(vector <Accounts>& vector_of_accs, vector <Workers>& vec_of_workers);
//����� ������
void adminInterface(vector <Accounts>& vector_of_accs, vector <Workers>& vector_of_workers,string login);
//������� ����� ����
char outputAdminMenu(string login);
//������ � ���������� ��� ������
void workingWithAccounts(vector <Accounts>& vector_of_accs,string login);
//����� ����
char outputWorkingWithAccountsMenu();
//������ � ������ ��� ������
void workingWithWorkersAdmin(vector <Workers>& vector_of_workers);
//����� ����
char outputWorkingWithWorkersMenu();
//���� ������
void userInterface(vector <Accounts>& vector_of_accs, vector <Workers>& vector_of_workers, string login);
//����� ����
char outputUserMenu(string login);
//������ � ������� ��� �����
bool workingWithAccountByUser(vector <Accounts>& vector_of_accs, string login);
//����� ���.
char outputWorkingWithUserAccountMenu();

//������ �� ����� �� ������ ��� �����
void workingWithWorkersUser(vector <Workers>& vector_of_workers);
//����� ����
char outputWorkingWithWorkersMenuUser();


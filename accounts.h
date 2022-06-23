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
	string login;//логин аккаунта
	string salt;//соль для хеширование
	string salted_hash_password;//захешированный пароль с солью
	int role;//роль,1-админ 0-юзер
	int access;//доступ,1-разрешен 0-нет
};

const string FILE_OF_ACCOUNTS = "AccData.txt";

const int SALT_SIZE= 12;
const int SYMBOLS_SIZE = 62;
//считать инфу из файла
void readFileAccounts(vector <Accounts>& vector_of_accs);
//записать инфу в файл
void writeFileAccounts(const vector <Accounts>& vector_of_accs);
//ввод пароль
string inputPass();
//регистрация аккаунта 
void registeringAccount(vector <Accounts>& vector_of_accs);
//вход в аккаунт
string loginAccount(const vector <Accounts>& vector_of_accs, int& role);
//смена логина
string changeLogin( vector <Accounts>& vector_of_accs,string login);
//смена пароля
void changePassword(vector <Accounts>& vector_of_accs, string login);
//вывод всех аккаунтов
void outputAllAccounts(vector <Accounts>& vector_of_accs);
//верификация аккаунта(смена роль)
void verificationAccount(vector <Accounts>& vector_of_accs);
//удаления аккаунта юзера
void deleteUserAccount(vector <Accounts>& vector_of_accs,string your_login);
//смена роли аккаунту
void changeRoleAccount(vector <Accounts>& vector_of_accs,string your_login);
//удаление себя юзером
bool deleteYourselfAccount(vector <Accounts>& vector_of_accs, string your_login);



string generateSalt(int salt_size);
string getSymbolsForSalt();

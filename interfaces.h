#pragma once

#include <string>
#include <vector>
#include <iomanip>


#include "validation.h"
#include "accounts.h"
#include "workers.h"




//получение количества структур
int getCountOfStructuresInFile(string file_path);
//вывод информации в конце
void inputInfoAboutProgram();
//вывод основного меню
char outputMainMenu();
//основной интерфейс
void System(vector <Accounts>& vector_of_accs, vector <Workers>& vec_of_workers);
//админ панель
void adminInterface(vector <Accounts>& vector_of_accs, vector <Workers>& vector_of_workers,string login);
//вывести админ меню
char outputAdminMenu(string login);
//работа с аккаунтами для админа
void workingWithAccounts(vector <Accounts>& vector_of_accs,string login);
//вывод меню
char outputWorkingWithAccountsMenu();
//работа с даными для админа
void workingWithWorkersAdmin(vector <Workers>& vector_of_workers);
//вывод меню
char outputWorkingWithWorkersMenu();
//юзер панель
void userInterface(vector <Accounts>& vector_of_accs, vector <Workers>& vector_of_workers, string login);
//вывод меню
char outputUserMenu(string login);
//работа с данными для юзера
bool workingWithAccountByUser(vector <Accounts>& vector_of_accs, string login);
//вывод мен.
char outputWorkingWithUserAccountMenu();

//работа со своей уч аписью для юзера
void workingWithWorkersUser(vector <Workers>& vector_of_workers);
//вывод меню
char outputWorkingWithWorkersMenuUser();


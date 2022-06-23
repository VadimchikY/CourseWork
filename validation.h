#pragma once

#include <iostream>
#include <string>
#include <conio.h>

using namespace std;
//проверка строки на валидность
bool checkString(string str);
//запрос на ввод целого числа из диапазона 
int getInt(int bein, int end);
//выбор действия 
char choiceAction(char begin, char end);
//подтверждения необратимого действия
bool confirmAction(string str);
//ввод имени и должности
string inputName();
//ввод названия проека
string inputCompany();
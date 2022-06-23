#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <algorithm>
#include "validation.h"

using namespace std;

struct Workers
{
	string company;//проект
	string work;//должность
	string name;//имя
	int hours;//рабочие часы
	int money;//зарплата в час
};

const string FILE_OF_WORKERS = "Data.txt";

//считать из файла
void readFileWorkers(vector <Workers>& vector_of_workers);
//записать в файл
void writeFileWorkers(const vector <Workers>& vector_of_workers);

//вывод всех данных
void outputAllWorkers(const vector <Workers>& vector_of_workers);
//добавить сотрудника
void addWorker(vector <Workers>& vector_of_workers);
//редактировать
void editWorker(vector <Workers>& vector_of_workers);
//удалить
void deleteWorker(vector <Workers>& vector_of_workers);
//сортировки
void sortByCompany(vector <Workers>& vector_of_workers);
void sortByWork(vector <Workers>& vector_of_workers);
void sortByHours(vector <Workers>& vector_of_workers);
void sortByMoney(vector <Workers>& vector_of_workers);
//компораторы к сортировкам
bool mySortByCompany(Workers a, Workers b);
bool mySortByWork(Workers a, Workers b);
bool mySortByHours(Workers a, Workers b);
bool mySortByMoney(Workers a, Workers b);
//индивидуальное задание
void individualTask(vector <Workers>& main_vector);
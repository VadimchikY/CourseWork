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
	string company;//������
	string work;//���������
	string name;//���
	int hours;//������� ����
	int money;//�������� � ���
};

const string FILE_OF_WORKERS = "Data.txt";

//������� �� �����
void readFileWorkers(vector <Workers>& vector_of_workers);
//�������� � ����
void writeFileWorkers(const vector <Workers>& vector_of_workers);

//����� ���� ������
void outputAllWorkers(const vector <Workers>& vector_of_workers);
//�������� ����������
void addWorker(vector <Workers>& vector_of_workers);
//�������������
void editWorker(vector <Workers>& vector_of_workers);
//�������
void deleteWorker(vector <Workers>& vector_of_workers);
//����������
void sortByCompany(vector <Workers>& vector_of_workers);
void sortByWork(vector <Workers>& vector_of_workers);
void sortByHours(vector <Workers>& vector_of_workers);
void sortByMoney(vector <Workers>& vector_of_workers);
//����������� � �����������
bool mySortByCompany(Workers a, Workers b);
bool mySortByWork(Workers a, Workers b);
bool mySortByHours(Workers a, Workers b);
bool mySortByMoney(Workers a, Workers b);
//�������������� �������
void individualTask(vector <Workers>& main_vector);
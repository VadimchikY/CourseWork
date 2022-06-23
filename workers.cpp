#include "workers.h"

void readFileWorkers(vector <Workers>& vector_of_workers)
//ф-я считывания данных из файла(при необходимости его создание)
{
	ifstream fin(FILE_OF_WORKERS, ios::in); // Открыли файл для чтения
	if ((!fin.is_open()) || vector_of_workers.empty())
	{
		ofstream fout(FILE_OF_WORKERS);
		fout.close();
	}
	else
	{
		int i = 0;
		while (!fin.eof())
		{
			fin >> vector_of_workers[i].company
				>> vector_of_workers[i].work
				>> vector_of_workers[i].name
				>> vector_of_workers[i].hours
				>> vector_of_workers[i].money;
			i++;
		}
	}
	fin.close(); //Закрыли файл
}
void writeFileWorkers(const vector <Workers>& vector_of_workers)
//ф-я для записи данных в файл
{
	ofstream fout(FILE_OF_WORKERS, ios::out); // Открыли файл для записи
	for (unsigned int i = 0; i < vector_of_workers.size(); i++)
	{
		fout << vector_of_workers[i].company << " "
			<< vector_of_workers[i].work << " "
			<< vector_of_workers[i].name << " "
			<< vector_of_workers[i].hours << " "
			<< vector_of_workers[i].money;

		if (i < vector_of_workers.size() - 1)
			fout << endl;
	}
	fout.close();
}



void outputAllWorkers(const vector <Workers>& vector_of_workers)
//ф-я вывода таблицы с информацией о работниках
{
	cout << " №|   ПРОЕКТ   |   ВИД РАБОТ   |   ИМЯ   |КОЛ-ВО| $ В |\n";
	cout << "  |            |               |         | ЧАСОВ| ЧАС |\n";
	cout << "  |------------+---------------+---------+------+-----|\n";
	int size = vector_of_workers.size();
	if (size == 0)
	{
		cout << "Список записей пуст!\n";
		cout << "\n\n\n";
		return;
	}
	for (int i = 0; i < size; i++)
	{
		cout << setw(2) << i + 1 <<
			"| " << left << setw(11) << vector_of_workers[i].company
			<< "| " << left << setw(14) << vector_of_workers[i].work
			<< "|  " << left << setw(7) << vector_of_workers[i].name
			<< "|  " << right << setw(3) << vector_of_workers[i].hours
			<< " | " << right << setw(3) << vector_of_workers[i].money
			<< " |\n";

	}
	cout << "\n\n\n";
}

void addWorker(vector <Workers>& vector_of_workers)
//ф-я добавления работника в вектор
{
	string company, work, name;
	int hours, money;
	cout << "----Добавление записи----\n";
	cout << "Введите название проекта:\n-> ";
	company = inputCompany();
	cout << "Введите должность работника:\n-> ";
	work = inputName();
	cout << "Введите имя работника:\n-> ";
	name = inputName();
	cout << "Введите количество часов работника:\n-> ";
	hours = getInt(0, 350);
	cout << "Введите почасовую оплату в $:\n-> ";
	money = getInt(0, 500);
	cout << "Вы успешно добавили запись!\n";
	Workers temp;
	temp.company = company;
	temp.work = work;
	temp.name = name;
	temp.hours = hours;
	temp.money = money;
	vector_of_workers.push_back(temp);
	_getch();
}
void editWorker(vector <Workers>& vector_of_workers)
//ф-я редактирования работника
{
	outputAllWorkers(vector_of_workers);
	cout << "Выберите, номер редактируемого работника(0-Назад):\n-> ";
	int choice = getInt(0, vector_of_workers.size());
	if (choice == 0)
		return;
	choice--;
	cout << "--Что редактируем?--\n";
	cout << "1| Проект\n";
	cout << "2| Должность\n";
	cout << "3| Имя\n";
	cout << "4| Количество рабочих  часов\n";
	cout << "5| Оплата за рабочий час\n";
	cout << "0| Отмена\n";
	switch (choiceAction('0', '5'))
	{
	case '0':
		return;

	case '1':
	{
		cout << "Введите новое название проекта:\n-> ";
		string company = inputCompany();
		vector_of_workers[choice].company = company;
		break;
	}
	case '2':
	{
		cout << "Введите новую должность работника:\n-> ";
		string  work = inputName();
		vector_of_workers[choice].work = work;
		break;
	}
	case '3':
	{
		cout << "Введите имя нового работника:\n-> ";
		string  name = inputName();
		vector_of_workers[choice].name = name;
		break;
	}
	case '4':
	{
		cout << "Введите новое количество рабочих часов работника:\n-> ";
		int hours = getInt(0, 350);
		vector_of_workers[choice].hours = hours;
		break;
	}
	case '5':
	{
		cout << "Введите новую заработную плату в час в $:\n-> ";
		int money = getInt(0, 500);
		vector_of_workers[choice].money = money;
		break;
	}
	}
	cout << "Успешно изменено.\n";
	_getch();
}
void deleteWorker(vector <Workers>& vector_of_workers)
{
	//функция удаления работника из вектора
	outputAllWorkers(vector_of_workers);
	cout << "Выберите, номер удаляемого работника(0-Назад):\n-> ";
	int choice = getInt(0, vector_of_workers.size());
	if (choice == 0)
		return;
	choice--;
	if (confirmAction("удалить пользователя " + vector_of_workers[choice].name))
	{
		cout << "Запись " << vector_of_workers[choice].name << " успешно удален.\n";
		_getch();
		vector_of_workers.erase(vector_of_workers.cbegin() + choice);
	}
}

void sortByCompany(vector <Workers>& vector_of_workers)
//сортировка по названию компании
{
	sort(vector_of_workers.begin(), vector_of_workers.end(), mySortByCompany);
}
void sortByWork(vector <Workers>& vector_of_workers)
//сортировка по названию должности
{
	sort(vector_of_workers.begin(), vector_of_workers.end(), mySortByWork);
}
void sortByHours(vector <Workers>& vector_of_workers)
//сортировка по рабочим часам
{
	sort(vector_of_workers.begin(), vector_of_workers.end(), mySortByHours);
}
void sortByMoney(vector <Workers>& vector_of_workers)
//сортировка по зарплате
{
	sort(vector_of_workers.begin(), vector_of_workers.end(), mySortByMoney);
}
bool mySortByCompany(Workers a, Workers b)
{
	return a.company < b.company;
}
bool mySortByWork(Workers a, Workers b)
{
	return a.work < b.work;
}
bool mySortByHours(Workers a, Workers b)
{
	return a.hours > b.hours;
}
bool mySortByMoney(Workers a, Workers b)
{
	return a.money > b.money;
}


void individualTask(vector <Workers>& main_vector)
//ф-я выполнения индивидуального задания
{
	if (main_vector.empty())
		return;
	sortByWork(main_vector);
	sortByCompany(main_vector);
	int vec_size = main_vector.size();
	int iterator = 0;

	while (iterator < vec_size)
	{
		string i_company = main_vector[iterator].company;
		int total_cost = 0, i = iterator;
		while (i_company == main_vector[i].company) //подсчет общего бюджета
		{
			total_cost += main_vector[i].hours * main_vector[i].money;
			i++;
			if (i == vec_size)//если последний элемент
				break;
		}

		cout << endl << i_company << endl << endl;
		cout << "Общая стоимость проекта: " << total_cost << "$\n";
		cout << "|   ВИД РАБОТ   | КОЛИЧЕСТВО | СТОИМОСТЬ |\n";
		cout << "|               |СПЕЦИАЛИСТОВ|           |\n";
		while (iterator < i)
		{
			string i_work = main_vector[iterator].work;
			int stage_cost = 0, num_of_employees = 0;
			while (i_work == main_vector[iterator].work)// подсчет бюджета на отрасль
			{
				int hours = main_vector[iterator].hours, money = main_vector[iterator].money;
				stage_cost +=hours* money;
				num_of_employees++;
				iterator++;
				if (iterator == vec_size)
					break;
			}
			cout << "| " << left << setw(14) << i_work << "|     " << right << setw(2) << num_of_employees << "     |   " << right << setw(5)<<stage_cost << "   |\n";
		}
		cout << "\n------------------------------------------------------------\n";
	}
	cout << "Нажмите, чтобы вернуться обратно.\n";
	_getch();
}
#include "validation.h"

bool checkString(string str)
//проверка строки на валидные символы 1-строка с ошибкой 0-строка верна
{
	int size = str.length();
	for (int i = 0; i < size; i++)
	{
		if (!((str[i] >= 'a' && str[i] <= 'z') ||
			(str[i] >= 'A' && str[i] <= 'Z') ||
			(str[i] >= '0' && str[i] <= '9') ||
			str[i] == '_' || str[i] == '.'
			))//если недопустимые символы
		{
			cout << "Ошибка:недопустимые символы.(Разрешенные символы:[a-z][A-Z][0-9]и '_' и '.')\n";
			return 1;
		}
		if (!(size > 3 && size < 17))
		{
			cout << "Ошибка:допустимый размер 4-16 символов\n";
			return 1;
		}
	}
	return 0;//если прошло проверку
}
//запрос целого числа из диапазона 
int getInt(int begin, int end)
//ф-я для ввода только целого значения из заданного(переданного) диапазона 
{
	int input;

	while (true)
	{
		cin >> input;
		if (cin.get() != '\n') // если данные некорректны
		{
			cout << "Некорректный ввод,введите корректное значение!\n-> ";

			cin.clear(); // восстанавливаем поток
			cin.ignore(32767, '\n'); // пропускаем всё до \n
		}
		else
		{
			if (!(input >= begin && input <= end))
			{
				cout << "Некорректный ввод!(допустимые значения [" << begin << ";" << end << "] Введите корректное значение!\n-> ";
				continue; // возвращаемся к вводу ещё раз
			}
			break; // если данные корректны, останавливаем цикл
		}
	}

	return input;
}
//выбор действия 
char choiceAction(char begin, char end)
//ф-я для считывания с клавиатуры только входящих в диапазон символов
{
	char choice;
	do
	{
		choice = _getch();
	} while (!(choice >= begin && choice <= end));
	system("cls");
	return choice;
}
//подтверждения необратимого действия
bool confirmAction(string str)
//1-подвержден 0-отмена
//ф-я для подтверждения необратимого действия
{
	cout << "Вы действительно хотите " + str + "?\n";
	cout << "1| Да\n";
	cout << "2| Нет\n";
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
//ввод имени и должности
string inputName()
//ф-я для ввода валидных символов для ячеек имени и должности
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
				(work[i] >= 'а' && work[i] <= 'я') ||
				(work[i] >= 'А' && work[i] <= 'Я') ||
				work[i] == '(' || work[i] == ')' ||
				work[i] == '_'))
			{
				cout << "Ошибка:недопустимый символ.Повторите ввод.\n-> ";
				flag = 1;
				break;
			}
		}

	} while (flag);
	return work;
}
//ввод названия проека
string inputCompany()
//ф-я для ввода любых символов исключая пробел

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
				cout << "Ошибка:недопустимый символ(ПРОБЕЛ).Повторите ввод.\n-> ";
				flag = 1;
				break;
			}
		}

	} while (flag);
	return company;
}


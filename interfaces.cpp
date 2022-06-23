#include "interfaces.h"

int getCountOfStructuresInFile(string file_path)
// Определение количества структур в файле
{
	ifstream file(file_path, ios::in); // Открыли текстовый файл для чтения
	int number_of_strings = 0;
	if (file.is_open())
	{
		if (file.peek() == EOF)
			return 0;
		while (file.ignore(numeric_limits<streamsize>::max(), '\n'))
			number_of_strings++;
	}
	file.close();
	return number_of_strings;
}
char outputMainMenu()
//вывод основной менюшки и выбор 
{
	cout << "1| Войти\n";
	cout << "2| Регистрация\n";
	cout << "0| Выход\n";
	return choiceAction('0', '2');
}
void inputInfoAboutProgram()
//конечная ,просто инфа
{
	cout << "\n\n\n\n";
	cout << "                     БЕЛОРУССКИЙ ГОСУДАРСТВЕННЫЙ УНИВЕРСИТЕТ\n";
	cout << "                         ИНФОРМАТИКИ И РАДИОЭЛЕКТРОНИКИ\n\n\n\n";
	cout << "                         ОСНОВЫ КОНСТРУИРОВАНИЯ ПРОГРАММ\n\n\n";
	cout << "                                 КУРСОВАЯ РАБОТА\n";
	cout << "                                     на тему\n";
	cout << "                 РАЗРАБОТКА ПРОГРАММЫ ПЛАНИРОВАНИЯ БЮДЖЕТА ПРОЕКТА\n\n\n";
	cout << "Выполнил студент группы: 010101 ЮХНЕВИЧ ВАДИМ СЕРГЕЕВИЧ\n\n";
	cout << "Преподаватель: МЕЖЕННАЯ МАРИНА МИХАЙЛОВНА\n";
	cout << "\n\n\n\n\n\n                                   МИНСК 2021";
	_getch();
}



void System(vector <Accounts>& vector_of_accs, vector <Workers>& vector_of_workers)
//основной интерфейс
{
	bool mainMenuFlag = 1;
	do
	{
		string signedAccount;
		int role;
		switch (outputMainMenu())
		{
		case '1':
			role = -1;
			signedAccount = loginAccount(vector_of_accs, role);
			_getch();
			system("cls");
			if (role == 1)
				adminInterface(vector_of_accs,vector_of_workers, signedAccount);
			if (role == 0)
				userInterface(vector_of_accs, vector_of_workers, signedAccount);
			break;
		case '2':
			registeringAccount(vector_of_accs);
			break;
		case '0':
			if (confirmAction("выйти"))
			{
				inputInfoAboutProgram();
				mainMenuFlag = 0;
			}
			break;
		}
	} while (mainMenuFlag);
}

void adminInterface(vector <Accounts>& vector_of_accs, vector <Workers>& vector_of_workers, string login)
//админский интерфейс
{
	bool adminMenuFlag = 1;
	do
	{
		switch (outputAdminMenu(login))
		{
		case '1':
			workingWithAccounts(vector_of_accs, login);
			break;
		case '2':
			workingWithWorkersAdmin(vector_of_workers);
			break;
		case '3':
			login =changeLogin(vector_of_accs, login);
			break;
		case '4':
			changePassword(vector_of_accs, login);
			break;
		case '0':
			if (confirmAction("выйти из аккаунта"))
				adminMenuFlag = 0;
			break;
		}
		system("cls");
	} while (adminMenuFlag);
}


char outputAdminMenu(string login)
//вывод к админскому интерфейсу
{
	cout << "------" << login << "(admin)------\n";
	cout << "1| Работа с учетными записями\n";
	cout << "2| Работа с данными\n\n";
	cout << "3| Смена логина учетной записи\n";
	cout << "4| Смена пароля учетной записи\n";
	cout << "0| Выход\n";
	return choiceAction('0', '4');
}
void workingWithAccounts(vector <Accounts>& vector_of_accs, string login)
//интерфей работы с аккаунтами для админа
{
	bool menuFlag = 1;
	do
	{
		outputAllAccounts(vector_of_accs);
		switch (outputWorkingWithAccountsMenu())
		{

		case '1':
			verificationAccount(vector_of_accs);
			break;
		case '2':
			deleteUserAccount(vector_of_accs,login);
			break;
		case '3':
			changeRoleAccount(vector_of_accs, login);
			break;
		case '0':
			menuFlag = 0;
			break;
		}
		system("cls");
	} while (menuFlag);
}
char outputWorkingWithAccountsMenu()
//меню для того что сверху
{
	cout << "1| Верификация учетных записей\n";
	cout << "2| Удалениие учетных записей\n";
	cout << "3| Изменение роли учетных записей\n";
	cout << "0| Назад\n";
	return choiceAction('0', '3');
}


void workingWithWorkersAdmin(vector <Workers>& vector_of_workers)
//интерфейс работы с данными работяг для админов
{
	bool menuFlag = 1;
	do
	{
		outputAllWorkers(vector_of_workers);
		switch (outputWorkingWithWorkersMenu())
		{
		case '1':
			addWorker(vector_of_workers);
			break;
		case '2':
			editWorker(vector_of_workers);
			break;
		case '3':
			deleteWorker(vector_of_workers);			
			break;
		case '4':
			individualTask(vector_of_workers);
			break;
		case '5':
			sortByCompany(vector_of_workers);
			break;
		case '6':
			sortByWork(vector_of_workers);
			break;
		case '7':
			sortByHours(vector_of_workers);
			break;
		case '8':
			sortByMoney(vector_of_workers);
			break;
		case '0':
			menuFlag = 0;
			break;
		}
		system("cls");
	} while (menuFlag);
}
char outputWorkingWithWorkersMenu()
//меню к тому что сверху
{
	cout << "1| Добавить запись\n";
	cout << "2| Редактиовать запись\n";
	cout << "3| Удалить запись\n";
	cout << "4| Индивидуальное задание\n";
	cout << "5| Отсортировть по названию проекта\n";
	cout << "6| Отсортировть по типу работы\n";
	cout << "7| Отсортировть по количеству часов\n";
	cout << "8| Отсортировть по заработной плате\n";
	cout << "0| Назад\n";

	return choiceAction('0', '8');
}


void userInterface(vector <Accounts>& vector_of_accs, vector <Workers>& vector_of_workers, string login)
//интерфейс пользователя
{
	bool userMenuFlag = 1;
	do
	{
		switch (outputUserMenu(login))
		{
		case '1':
			workingWithWorkersUser(vector_of_workers);
			break;
		case '2':
			if (workingWithAccountByUser(vector_of_accs, login))
				userMenuFlag = 0;
			break;
		case '0':
			if (confirmAction("выйти из аккаунта"))
				userMenuFlag = 0;
			break;
		}
		system("cls");
	} while (userMenuFlag);
}

char outputUserMenu(string login)
//меню к тому что сверху
{
	cout << "--------" << login << "--------\n";
	cout << "1| Работа с данными\n";
	cout << "2| Работа со своей учетной записью\n";
	cout << "0| Выход\n";
	return choiceAction('0', '2');
}
bool workingWithAccountByUser(vector <Accounts>& vector_of_accs, string login)
//интерфейс юзера для работы с изменениями своего акка
//вернет 0-если все хорошо 1-если аккаунт удален и требуется выйти к основному меню
{
	bool menuFlag = 1;
	do
	{
		switch (outputWorkingWithUserAccountMenu())
		{
		case '1':
			login = changeLogin(vector_of_accs, login);
			break;
		case '2':
			changePassword(vector_of_accs, login);
			break;
		case '3':
			if(deleteYourselfAccount(vector_of_accs, login))
				return 1;
			break;
		case '0':
			menuFlag = 0;
			break;
		}
		system("cls");
	} while (menuFlag);
	return 0;
}
char outputWorkingWithUserAccountMenu()
{
	cout << "1| Смена логина учетной записи\n";
	cout << "2| Смена пароля учетной записи\n";
	cout << "3| Удаление своей учентной записи\n";
	cout << "0| Назад\n";
	return choiceAction('0', '3');
}

void workingWithWorkersUser(vector <Workers>& vector_of_workers)
//интерфейс для работы с данными работяг для юзера
{
	bool menuFlag = 1;
	do
	{
		outputAllWorkers(vector_of_workers);
		switch (outputWorkingWithWorkersMenuUser())
		{
		case '1':
			individualTask(vector_of_workers);
			break;
		case '2':
			sortByCompany(vector_of_workers);
			break;
		case '3':
			sortByWork(vector_of_workers);
			break;
		case '4':
			sortByHours(vector_of_workers);
			break;
		case '5':
			sortByMoney(vector_of_workers);
			break;
		case '0':
			menuFlag = 0;
			break;
		}
		system("cls");
	} while (menuFlag);
}
char outputWorkingWithWorkersMenuUser()
{
	cout << "1| Индивидуальное задание\n";
	cout << "2| Отсортировть по названию проекта\n";
	cout << "3| Отсортировть по типу работы\n";
	cout << "4| Отсортировть по количеству часов\n";
	cout << "5| Отсортировть по заработной плате\n";
	cout << "0| Назад\n";
	return choiceAction('0', '5');
}
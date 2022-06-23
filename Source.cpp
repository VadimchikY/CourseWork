#include <vector>
#include <windows.h>

#include "accounts.h"
#include "workers.h"
#include "interfaces.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	vector <Accounts> vec_of_accounts(getCountOfStructuresInFile(FILE_OF_ACCOUNTS));
	vector <Workers> vec_of_workers(getCountOfStructuresInFile(FILE_OF_WORKERS));

	readFileAccounts(vec_of_accounts);
	readFileWorkers(vec_of_workers);
	
	System(vec_of_accounts, vec_of_workers);

	writeFileAccounts(vec_of_accounts);
	writeFileWorkers(vec_of_workers);
	return 0;
}
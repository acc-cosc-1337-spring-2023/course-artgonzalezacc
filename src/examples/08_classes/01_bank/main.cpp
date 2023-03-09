#include<iostream>
#include<time.h>
#include<vector>
#include "checking_account.h"
#include "atm.h"
#include "savings_account.h"

using std::cout; using std::cin; using std::vector;

int main()
{
	srand(time(NULL));//generate true randoms on each main run execution
	vector<BankAccount*> accounts;
	SavingsAccount savings;
	CheckingAccount checking;
	accounts.push_back(&checking);
	accounts.push_back(&savings);

	run_menu(accounts);

	return 0;
}
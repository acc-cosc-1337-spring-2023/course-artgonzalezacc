#include<time.h>
#include<vector>
#include "atm.h"
#include "customer.h"

using std::vector;

int main()
{
	srand(time(NULL));

	std::vector<Customer> customers;
	customers.push_back(Customer());
    customers.push_back(Customer());
    customers.push_back(Customer());
	customers.push_back(Customer());
    customers.push_back(Customer());

	run_menu(customers);

	return 0;
}
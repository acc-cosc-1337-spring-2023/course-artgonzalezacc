#include<time.h>
#include<vector>
#include "atm.h"
#include "customer.h"
#include "atm_data.h"
#include<iostream>

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

	ATMData data;
	data.save_customers(customers);
	std::vector<Customer>& cus = data.get_customers();

	for(auto& c: cus)
	{
		std::cout<<c.get_account(0)->get_balance()<<" ";
		std::cout<<c.get_account(1)->get_balance()<<"\n";
	}

	//run_menu(customers);

	return 0;
}
//atm.h
#include<iostream>
#include<memory>
#include<stdlib.h>
#include<vector>
#include "atm_data.h"
#include "bank_account.h"
#include "customer.h"

void display_menu();
void run_menu(ATMData& atm_data);
void handle_menu_option(int option, std::unique_ptr<BankAccount> &account);
int scan_card(int max_value);


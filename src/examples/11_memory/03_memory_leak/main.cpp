#include "memory_leak.h"
#include<iostream>

using std::cout;

int main() 
{
	int* num_ptr = new int(5);

	cout<<*num_ptr<<"\n";
	
	return 0;
}
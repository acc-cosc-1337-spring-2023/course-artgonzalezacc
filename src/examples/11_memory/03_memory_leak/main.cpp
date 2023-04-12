#include "memory_leak.h"
#include<iostream>

using std::cout;

int main() 
{
	int* nums = new int[3]{};
	cout<<nums[0]<<"\n";
	nums[0] = 5;
	cout<<nums[0]<<"\n";

	delete nums;

	return 0;
}
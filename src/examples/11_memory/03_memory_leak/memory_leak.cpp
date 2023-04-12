#include "memory_leak.h"

using std::cout;

void memory_leak()
{
    int* ptr_num = new int(5);
}

void use_dynamic_memory_array(const int num)
{
    int* nums = new int[num]{};//create memory
    nums[0]= 5;
    //use memory
    cout<<nums[0]<<"\n";
    cout<<nums[1]<<"\n";
    cout<<nums[2]<<"\n";
    cout<<*nums<<"\n";//displays the first element

    //delete memory
    delete nums;
}

int* get_dynamic_memory(const int num)
{
    return new int[num];
}

void limit_dynamic_memory_scope(const int num)
{
    int* nums = get_dynamic_memory(num);//get created memory
    //use memory
    for(int i=0; i < num; i++)   
    {
        cout<<nums[i]<<"\n";
    }
    //delete memory
    delete nums;
}

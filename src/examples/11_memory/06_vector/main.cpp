//
#include "my_vector.h"

int main()
{
    //use_vector();    
    //use_vector();
    int num = 5;
    int& num_ref = num;//num-ref gets the address of num
    //we cant do int& num_ref = 5;
    //thus num is an Lvalue or addressable by a reference variable

    std::cout<<num_ref<<"\n";

    return 0;
}


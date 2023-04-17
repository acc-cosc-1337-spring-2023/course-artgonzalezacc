#include "my_vector.h"

using std::cout;
//
Vector::Vector(int s)
    : size{s}, capacity{s}, elements{new int[s]}
{
    cout<<"new memory created at "<<elements<<"\n";
}

Vector::~Vector()
{
    cout<<"delete memory at"<<elements<<"\n";
    delete[] elements;
}

//NOT A CLASS FUNCTION; FREE FUNCTIONS
void use_vector()
{
    Vector v(3);
}


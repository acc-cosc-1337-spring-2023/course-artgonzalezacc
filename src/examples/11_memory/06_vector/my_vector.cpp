#include "my_vector.h"

using std::cout;
//
Vector::Vector(int s)
    : capacity{s}, elements{new int[s]}
{
    cout<<"new memory created at "<<elements<<"\n";
}

Vector::Vector(const Vector& v)
  : size{v.size}, capacity{v.capacity}, elements{new int[v.size]}
{
    cout<<"Copy constructor - created memory at "<<elements<<"\n";
    for(auto i=0; i < v.size; i++)
    {
        elements[i] = v.elements[i];
    }
}

/*
1-Create temporary memory for v1
2-Copy values from v into v1 temporary memory
3-Delete v1 elements memory
4-Point v1 elements to temporary memory
5-Set v1 size to v.size
6-Return a reference to vector using (this)
*/
Vector& Vector::operator=(const Vector& v){
    int* temp = new int[v.size];

    for(auto i=0; i < v.size; i++)
    {
        temp[i] = v.elements[i];
    }

    cout<<"copy assignmment delete memory at "<<elements<<"\n";
    delete[] elements;

    elements = temp;
    temp = nullptr;

    cout<<"copy assignment - create memory at "<<elements<<"\n";
    size = v.size;

    return *this;//returns a reference to itself
}

/*
1-Get v.elements memory(steal the pointer/guts)
2-Get size frm v
3-point v.elements to nothing(nullptr)
4-set v size to 0
*/
Vector::Vector(Vector&& v)
 : size{v.size}, elements{v.elements}
{
    cout<<"Move constructor switched pointer "<<elements<<"\n";
    v.elements = nullptr;
    v.size = 0;
}

/*
1-clear/delete original dynamic memory from v
2-point elements(v1) to v.elements
3-get size from v
4-point v.elements to nullptr
5-set v.size to 0
6-return a self reference
*/
Vector& Vector::operator=(Vector&& v)
{
    cout<<"Move assignment delete memory "<<elements<<"\n";
    delete[] elements;

    elements = v.elements;

    cout<<"Move assignment switch pointers "<<elements<<"\n";

    size = v.size;
    v.elements = nullptr;
    v.size = 0;

    return *this;
}

/*
1-make sure new size is greater than capacity
2-create temp memory of size allocation
3-copy values from old memory to temp memory
4-delete the old memory
5-set elements to temp memory
6-set capacity to new allocation size
*/
void Vector::Reserve(int new_size)
{   
    if(new_size <= capacity)
    {
        return;
    }

    int* temp = new int[new_size];
    cout<<"Reserve new memory "<<temp<<"\n";

    for(auto i=0; i < size; i++)
    {
        temp[i] = elements[i];
    }

    cout<<"Delete old memory "<<elements<<"\n";
    delete[] elements;

    elements = temp;
    
    capacity = new_size;
}

/*
1-if capacity is 0 call reserve w reserve_default size
2-else if size is equal to capacity Reserve w capacity * reserve_default_multiplier
3-current elements at size (index) ex: elements[size] =  value--- to value
4-increment the size
*/
void Vector::PushBack(int value)
{

    if(capacity == 0)
    {
        Reserve(RESERVE_DEFAULT_SIZE);
    }
    else if(capacity == size)
    {
        Reserve(capacity * RESERVE_DEFAULT_MULTIPLIER);
    }

    elements[size] = value;

    size++;
}

Vector::~Vector()
{
    cout<<"delete memory at"<<elements<<"\n";
    delete[] elements;
}

//NOT A CLASS FUNCTION; FREE FUNCTIONS
void use_vector()
{
    Vector v(3);//calls constructor with int parameter
    Vector v1 = v;//calls copy constructor
}

Vector get_vector()
{
    Vector v1(3); 
    return v1;
}

#include "my_vector.h"

using std::cout;
//
template<typename T>
Vector<T>::Vector(int s)
    : capacity{s}, elements{new T[s]}
{
    cout<<"new memory created at "<<elements<<"\n";
}

template<typename T>
Vector<T>::Vector(const Vector& v)
  : size{v.size}, capacity{v.capacity}, elements{new T[v.size]}
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
template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v){
    T* temp = new T[v.size];

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
template<typename T>
Vector<T>::Vector(Vector<T>&& v)
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
template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& v)
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
template<typename T>
void Vector<T>::Reserve(int new_size)
{   
    if(new_size < capacity)
    {
        return;
    }

    T* temp = new T[new_size];
    cout<<"Reserve - new memory "<<temp<<"\n";

    for(auto i=0; i < size; i++)
    {
        temp[i] = elements[i];
    }

    cout<<"Reserve - Delete old memory "<<elements<<"\n";
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
template<typename T>
void Vector<T>::PushBack(T value)
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

template<typename T>
Vector<T>::~Vector()
{
    cout<<"delete memory at"<<elements<<"\n";
    delete[] elements;
}

//NOT A CLASS FUNCTION; FREE FUNCTIONS
void use_vector()
{
    Vector<int> v(3);//calls constructor with int parameter
    Vector<int> v1 = v;//calls copy constructor
}

Vector<int> get_vector()
{
    Vector<int> v1(3); 
    return v1;
}

//Tell C++ what data type this template will support
template class Vector<int>;
template class Vector<double>;
template class Vector<char>;

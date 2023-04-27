//
#include<iostream>

#ifndef VECTOR_H
#define VECTOR_H

template<typename T>
class Vector
{
public:
    Vector() = default;
    Vector(int size);
    Vector(const Vector<T>& v);//copy constructor Rule 1 Rule of 3(legacy C++)
    Vector<T>& operator=(const Vector<T>& v);//copy assignment Rule 2 of 3
    Vector(Vector<T>&& v);//move constructor Rule 4 of 5 in modern C++ programming
    Vector<T>& operator=(Vector<T>&& v);//move assignment Rule 5 of 5 in modern C++
    int Size(){return size;}
    int Capacity(){return capacity;}
    void PushBack(T value);
    T& operator[](int index){return  elements[index];}
    T& operator[](int index)const{return elements[index];}
    ~Vector();//destructor Rule 3 of 3 in legacy C++
private:
    int size{0};
    int capacity{0};
    T* elements{0};
    const int RESERVE_DEFAULT_SIZE{8};
    const int RESERVE_DEFAULT_MULTIPLIER{2};
    void Reserve(int new_size);

};

#endif

void use_vector();
Vector<int> get_vector();
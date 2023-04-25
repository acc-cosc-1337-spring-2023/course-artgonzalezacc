//
#include<iostream>

#ifndef VECTOR_H
#define VECTOR_H

class Vector
{
public:
    Vector(int size);
    Vector(const Vector& v);//copy constructor Rule 1 Rule of 3(legacy C++)
    Vector& operator=(const Vector& v);//copy assignment Rule 2 of 3
    Vector(Vector&& v);//move constructor Rule 4 of 5 in modern C++ programming
    Vector& operator=(Vector&& v);//move assignment Rule 5 of 5 in modern C++
    int Size(){return size;}
    int Capacity(){return capacity;}
    void PushBack(int value);
    int& operator[](int index){return  elements[index];}
    int& operator[](int index)const{return elements[index];}
    ~Vector();//destructor Rule 3 of 3 in legacy C++
private:
    int size{0};
    int capacity;
    int* elements;
    const int RESERVE_DEFAULT_SIZE{8};
    const int RESERVE_DEFAULT_MULTIPLIER{2};
    void Reserve(int new_size);

};

#endif

void use_vector();
Vector get_vector();
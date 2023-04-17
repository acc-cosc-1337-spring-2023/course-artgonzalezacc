//
#include<iostream>

#ifndef VECTOR_H
#define VECTOR_H

class Vector
{
public:
    Vector(int size);
    int Size(){return size;}
    int& operator[](int index){return  elements[index];}
    int& operator[](int index)const{return elements[index];}
    ~Vector();
private:
    int* elements;
    int size;
    int capacity;
};

#endif

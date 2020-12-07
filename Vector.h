//
// Created by raspberry on 07.12.2020.
//
#pragma once
#ifndef UDIN7_VECTOR_H
#define UDIN7_VECTOR_H

#include "Film.h"

class Vector {
private:
    Film *films;
    int length;
    void expand();
public:
    Vector();
    Vector(Film *films , int length);
    Vector(const Vector &vector);
    void push(Film film);
    Film pop();
    Film& operator[](int index);
    Vector& operator=(Vector another);
    int size();
    ~Vector();
};


#endif //UDIN7_VECTOR_H

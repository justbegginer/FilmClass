//
// Created by raspberry on 07.12.2020.
//
#pragma once
#ifndef FilmClass_VECTOR_H
#define FilmClass_VECTOR_H

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
    void push(Film& films);
    Film pop();
    Film& operator[](int index);
    int size();
    ~Vector();
};


#endif //UDIN7_VECTOR_H

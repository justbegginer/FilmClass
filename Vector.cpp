//
// Created by raspberry on 07.12.2020.
//

#include "Vector.h"


Vector::Vector() {
    length = 0;
    films = new Film[0];
}

Vector::Vector(Film *films, int length) {
    this->length = length;
    this->films = new Film[length];
    for (int i = 0; i < length; i++) {
        *(this->films + i) = *(films + i);
    }
}

Vector::Vector(const Vector &vector) {
    length = vector.length;
    films = new Film[length];
    for (int i = 0; i < length; ++i) {
        *(films + i) = *(vector.films + i);
    }
}

void Vector::push(Film film) {
    expand();
    *(films + length - 1) = film;
}

Film Vector::pop() {
    Film last = Film(*(films + length - 1));
    length--;
    return last;
}

Film &Vector::operator[](int index) {
    if (index >= length || index < 0)
        throw std::out_of_range("index of Vector out of range");
    return *(films + index);
}

Vector::~Vector() {
    delete[] films;
}

int Vector::size() {
    return length;
}

void Vector::expand() {
    Film *new_films = new Film[length + 1];
    for (int i = 0; i < length; ++i) {
        *(new_films + i) = *(films + i);
    }
    length ++;
    delete [] films;
    films = new_films;
}

Vector &Vector::operator=(Vector another) {
    for(int i = 0 ; i < another.size() ; i++){
        if (i < this->size()-1){
           (*this)[i] = another[i];
        }
        else{
            this->push(another[i]);
        }
    }
    this->length = another.length;
    return *this;
}

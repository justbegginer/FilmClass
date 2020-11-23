#include <iostream>
#include "Film.h"

void insert_Film(Film *film, int length, int index, const Film &inserting);

int main() {

    return 0;
}

Film &sort_Films_by_date(Film *films, int length) {
    Film *new_films = new Film[length];
    insert_Film(new_films, length, 0, *(films));
    if (*(new_films) > *(films + 1)) {
        insert_Film(new_films, length, 0, *(films + 1));
    } else {
        insert_Film(new_films, length, 1, *(films + 1));
    }
    for (int i = 2; i < length; ++i) {
        for (int j = 0; j < i; ++j) {
            if (*(new_films + j) > *(films + i)) {
                insert_Film(new_films, length, j, *(films + i));
            }
        }
    }
    return *new_films;
}

void insert_Film(Film *film, int length, int index, const Film &inserting) {
    Film last(*(film + index));
    *(film + index) = inserting;
    for (int i = index + 1; i < length - 1; ++i) {
        Film temp(*(film + i));
        *(film + i) = last;
        last = temp;
    }
}
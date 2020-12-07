#include <iostream>
#include "Film.h"
#include "Vector.h"
#include "vector"
#include "map"

void insert_Film(Vector &films, int index, const Film &inserting);

int main() {

    return 0;
}

void sort_Films_by_date(Vector &films, int length) {
    Vector *new_films = new Vector();
    insert_Film(*new_films, 0, films[0]);
    if ((*new_films)[0] > films[1]) {
        insert_Film(*new_films, 0, films[1]);
    } else {
        insert_Film(*new_films, 1, films[1]);
    }
    for (int i = 2; i < length; ++i) {
        for (int j = 0; j < i; ++j) {
            if ((*new_films)[j] > films[i]) {
                insert_Film(*new_films, j, films[i]);
            }
        }
    }
    films = *new_films;
}

void insert_Film(Vector &films, int index, const Film &inserting) {
    Film last(films[index]);
    films[index] = inserting;
    for (int i = index + 1; i < films.size() - 1; ++i) {
        Film temp(films[i]);
        films[i] = last;
        last = temp;
    }
    films.push(last);
}

void is_correct_mans_name(std::string str) {

}
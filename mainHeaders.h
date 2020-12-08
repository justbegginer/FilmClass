//
// Created by raspberry on 08.12.2020.
//

#ifndef UDIN7_MAINHEADERS_H
#define UDIN7_MAINHEADERS_H
#include "string"
#include "Vector.h"

void sort_Films_by_date(Vector &films);

void insert_Film(Vector &films, int index, const Film &inserting);

void make_Film_from_file_data(std::ifstream &file, Vector films);

void table(Vector &vector);

void is_correct_mans_name(std::string str);

void is_correct_date(std::string date);

void is_correct_genre(std::string genre);

void is_correct_film_name(std::string name);

#endif //UDIN7_MAINHEADERS_H

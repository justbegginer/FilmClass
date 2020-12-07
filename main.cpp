#include <iostream>
#include "Film.h"
#include "Vector.h"
#include "vector"
#include "map"
#include <fstream>

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

void table(Vector &vector) {
    std::map<std::string, std::string> map;
    std::vector<std::string> keys;
    int max_first_colon_size = 5, max_second_colon_size = 5;
    for (int i = 0; i < vector.size(); ++i) {
        if (map.cend() == map.find(vector[i].getGenre())) {
            map[vector[i].getGenre()] = vector[i].getName();
            keys.push_back(vector[i].getGenre());
        } else {
            map[vector[i].getGenre()] +="," + vector[i].getName();
        }
    }
    for (int i = 0; i < keys.size(); ++i) {
        if (keys[i].size() > max_first_colon_size) {
            max_first_colon_size = keys[i].size();
        }
        if (map[keys[i]].size() > max_second_colon_size) {
            max_second_colon_size = map[keys[i]].size();
        }
    }
    std::fstream table_writer("genresTable");
    std::string headers = "";
    for (int i = 0; i < max_second_colon_size+max_first_colon_size+7; ++i) {
        headers += "-";
    }
    table_writer << headers<< "\n";
    headers = "| genre";
    for (int i = 0; i < max_first_colon_size - 5 + 1; ++i) {
        headers +=  " ";
    }
    headers += "| films";
    for (int i = 0; i < max_second_colon_size - 5 + 1; ++i) {
        headers += " ";
    }
    headers += "|";
    table_writer << headers << "\n";
    for (int i = 0; i < keys.size(); ++i) {
        std::string output_string = "";
        for (int j = 0; j < max_second_colon_size + max_first_colon_size + 7; ++j) {
            output_string += "-";
        }
        table_writer << output_string << "\n";
        output_string = "| " + keys[i];
        for (int j = 0; j < max_first_colon_size - keys[i].size() + 1; ++j) {
            output_string += " ";
        }
        output_string += "| " + map[keys[i]];
        for (int j = 0; j < max_second_colon_size - map[keys[i]].size() + 1; ++j) {
            output_string += " ";
        }
        output_string += "|";
        table_writer << output_string << "\n";
    }
    std::string end_line = "";
    for (int i = 0; i < max_second_colon_size + max_first_colon_size + 7; ++i) {
        end_line+="-";
    }
    table_writer << end_line <<"\n";
}

void is_correct_mans_name(std::string str) {

}
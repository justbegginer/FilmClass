#include <iostream>
#include "Film.h"
#include "Vector.h"
#include "vector"
#include "map"
#include <fstream>
#include "mainHeaders.h"

typedef std::invalid_argument invalid;

int main() {
    auto films = Vector();
    std::ifstream input("/home/raspberry/CLionProjects/FilmClass/input");
    make_Film_from_file_data(input, films);
    sort_Films_by_date(films);
    table(films);
    return 0;
}

void sort_Films_by_date(Vector &films) {
    Vector *new_films = new Vector();
    insert_Film(*new_films, 0, films[0]);
    if ((*new_films)[0] > films[1]) {
        insert_Film(*new_films, 0, films[1]);
    } else {
        insert_Film(*new_films, 1, films[1]);
    }
    for (int i = 2; i < films.size(); ++i) {
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

void make_Film_from_file_data(std::ifstream &file, Vector films) {
    std::string temp;
    for (int i = 0;; i++) {
        films.push(Film());
        std::getline(file, temp);
        if (temp == "")
            break;
        std::string date = "";
        std::string film_name = "";
        std::string genre = "";
        std::string dir_name = "";
        std::string sc_name = "";
        try {
            for (int j = 0; j < temp.size();) {
                for (; !(temp[j] >= '0' && temp[j] <= '9'); j++) {
                    film_name += temp[j];
                }
                for (; temp[j] != ' '; j++) {
                    date += temp[j];
                }
                j++;
                for (; temp[j] != ' '; j++) {
                    genre += temp[j];
                }
                bool was_whitespase = false;
                while (true) {
                    j++;
                    if (temp[j] == ' ') {
                        if (was_whitespase)
                            break;
                        else
                            was_whitespase = true;
                    }
                    dir_name += temp[j];
                }
                for (; j != temp.size(); ++j) {
                    sc_name += temp[j];
                }
            }
        }
        catch (...) {
            throw invalid("lost parameter or part of people name");
        }
        is_correct_date(date);
        is_correct_film_name(film_name);
        is_correct_genre(genre);
        is_correct_mans_name(dir_name);
        is_correct_mans_name(sc_name);
        films[i].setName(film_name);
        films[i].setGenre(genre);
        films[i].setRealiseYear(std::stoi(date));
        films[i].setDirName(dir_name);
        films[i].setScName(sc_name);
    }
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
            map[vector[i].getGenre()] += "," + vector[i].getName();
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
    for (int i = 0; i < max_second_colon_size + max_first_colon_size + 7; ++i) {
        headers += "-";
    }
    table_writer << headers << "\n";
    headers = "| genre";
    for (int i = 0; i < max_first_colon_size - 5 + 1; ++i) {
        headers += " ";
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
        end_line += "-";
    }
    table_writer << end_line << "\n";
}

typedef std::invalid_argument invalid;

void is_correct_mans_name(std::string str) {
    int i = 0;
    if (str.size() < 7)
        throw invalid("invalid man's name");
    for (; str[i] != ' '; ++i) {
        if (i > 3)
            throw std::invalid_argument("invalid man's name");
        if (i % 2 == 0) {
            if (!(str[i] >= 'A' && str[i] <= 'Z'))
                throw invalid("invalid man's name");
        } else {
            if (str[i] != '.')
                throw invalid("invalid man's name");
        }
    }
    i++;
    for (; i < str.size(); ++i) {
        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')))
            throw invalid ("invalid man's name");
    }
}

void is_correct_date(std::string date){
    int int_date;
    try {
        int_date = std::stoi(date);
    }
    catch (invalid) {
        throw invalid ("date is not a number");
    }
    if (int_date < 1895 || int_date > 2020)
        throw invalid("absurd film date");
}

void is_correct_genre(std::string genre){
    for (char i : genre) {
        if (!((i >='a' && i<='z')||(i >='A' && i <= 'Z')))
            throw invalid("wrong genre name");
    }
}

void is_correct_film_name(std::string name){
    for(char i : name){
        if (!((i >='a' && i<='z')||(i >='A' && i <= 'Z') || i != '-' | i != ' '))
            throw invalid ("invalid film name");
    }
}
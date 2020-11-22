//
// Created by user.v2.0 on 21.11.2020.
//

#include "Film.h"

Film::Film(const std::string &name, const std::string &dirName, const std::string &scName, int realiseYear,
           const std::string &genre) : name(name), dir_name(dirName), sc_name(scName), realise_year(realiseYear),
                                       genre(genre) {}

const std::string &Film::getName() const {
    return name;
}

void Film::setName(const std::string &name) {
    Film::name = name;
}

const std::string &Film::getDirName() const {
    return dir_name;
}

void Film::setDirName(const std::string &dirName) {
    Film::dir_name = dirName;
}

const std::string &Film::getScName() const {
    return sc_name;
}

void Film::setScName(const std::string &scName) {
    Film::sc_name = scName;
}

int Film::getRealiseYear() const {
    return realise_year;
}

void Film::setRealiseYear(int realiseYear) {
    Film::realise_year = realiseYear;
}

const std::string &Film::getGenre() const {
    return genre;
}

void Film::setGenre(const std::string &genre) {
    Film::genre = genre;
}

bool Film::operator<(const Film &rhs) const {
    return realise_year < rhs.realise_year;
}

bool Film::operator>(const Film &rhs) const {
    return realise_year > rhs.realise_year;
}

bool Film::operator<=(const Film &rhs) const {
    return !(*this > rhs);
}

bool Film::operator>=(const Film &rhs) const {
    return !(*this < rhs);
}

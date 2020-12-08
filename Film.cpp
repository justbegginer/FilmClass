//
// Created by user.v2.0 on 21.11.2020.
//

#include "Film.h"

Film::Film(const Film &film) {
    name = film.name;
    realise_year = film.realise_year;
    dir_name = film.dir_name;
    sc_name = film.sc_name;
    genre = film.genre;
}

Film::Film() {
    name = "Fight club";
    realise_year = 1999;
    sc_name = "Chuck Palanic";
    dir_name = "David Fincher";
    genre = "drama,thriller";
}

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

bool Film::operator==(const Film &rhs) const {
    return rhs.sc_name == sc_name && rhs.dir_name == dir_name && rhs.name == name && rhs.realise_year == realise_year && rhs.genre == genre;
}

bool Film::operator!=(const Film &rhs) const {
    return !(rhs == *this);
}

Film &Film::operator=(Film rhs) {
    realise_year = rhs.realise_year;
    dir_name = rhs.dir_name;
    sc_name = rhs.sc_name;
    name = rhs.name;
    genre = rhs.genre;
    return  *(this);
}

std::ostream &operator<<(std::ostream &os, const Film &film) {
    os << "name: " << film.name << " dir_name: " << film.dir_name << " sc_name: " << film.sc_name << " realise_year: "
       << film.realise_year << " genre: " << film.genre;
    return os;
}

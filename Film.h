//
// Created by user.v2.0 on 21.11.2020.
//
#include <iostream>
#include <string>
#pragma once
#ifndef UDIN7_FILM_H
#define UDIN7_FILM_H


class Film {
private:
    std::string name;
    std::string dir_name;
    std::string sc_name;
    int realise_year;
    std::string genre;
public:
    Film(const std::string &name, const std::string &dirName, const std::string &scName, int realiseYear,
         const std::string &genre);

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getDirName() const;

    void setDirName(const std::string &dirName);

    const std::string &getScName() const;

    void setScName(const std::string &scName);

    int getRealiseYear() const;

    void setRealiseYear(int realiseYear);

    const std::string &getGenre() const;

    void setGenre(const std::string &genre);

};


#endif //UDIN7_FILM_H
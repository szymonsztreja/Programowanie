#ifndef S1234_STUDENT_H
#define S1234_STUDENT_H

#include <sstream>
#include <string>

namespace s1234 {

    struct Student
    {
        std::string const imie;
        std::string nazwisko;
        std::string nr_indeks ;
        unsigned int semestr = 1;
        double srednia;
        
        Student(std::string, std::string, std::string, unsigned int, double);

        auto to_string() const -> std::string;

    };
}  

#endif


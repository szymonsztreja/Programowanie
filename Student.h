#include "Student.h"

struct Student
{
    std::string const imie;
    std::string nazwisko;
    int const nr_indeks ;
    int semestr;
    float srednia;
    
    Student() = default;
    auto to_string(std::string n) const -> std::string;

};

auto Student::to_string(std::string n) const -> std::string;
{
    Student.imie = "Student";
    Student.nazwisko = "Studencki";
    Student.nr_indeks = 12345;
    Studnet.semestr = 1;
    Student.srednia = 4.268;
  
} 



#include <iostream> 
#include <string>
#include "Student.h"
//
//struct Student
//{
//    std::string const imie;
//    std::string nazwisko;
//    int const nr_indeks ;
//    int semestr;
//    float srednia;
//    
//    Student() = default;
//    auto to_string(std::string n) const -> std::string;
//};
//
auto Student::to_string() const -> std::string;
//{ 
//    Student.imie = "Student";
//    Student.nazwisko = "Studencki";
//    Student.nr_indeks = 12345;
//    Studnet.semestr = 1;
//    Student.srednia = 4.268;
//  
//    "Student", "Studencki", 12345, 1, 4.268;
//}
auto main() -> int
{
    Student ja = {"Szymon", "Sztreja", "s26048", 3, 4.5};
    std::cout << to_string.ja;
    return 0;

}



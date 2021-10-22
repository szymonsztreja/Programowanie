#include <string>


struct Student
{
    std::string const imie;
    std::string nazwisko;
    std::string nr_indeks ;
    int semestr;
    double srednia;
    
    Student(std::string, std::string, std::string, int, double);
    auto to_string() const -> std::string;

};

auto Student::to_string() const -> std::string
{
   std::string i;
   std::string n;
   std::string ni;
   int s;
   double sr;
} 



#include <s1234/Student.h>
#include <iostream> 
#include <string>


s1234::Student::Student(std::string i, std::string n, std::string nr, unsigned int s, double sr)
    : imie{std::move(i)}, nazwisko{std::move(n)}, nr_indeks{std::move(nr)}, semestr{s}, srednia{sr}
{}

auto s1234::Student::to_string() const -> std::string
{
    auto out = std::ostringstream{};
    out << imie << " "
        << nazwisko << ' '
        << "(" << nr_indeks << "),"
        << "semestr:" << semestr << " "
        << "srednia:" << srednia;
    return out.str();
}
auto main() -> int
{
    auto ja = s1234::Student("Szymon", "Sztreja", "s26048", 3, 4.5);
    std::cout << ja.to_string() << '\n';
    return 0;

}



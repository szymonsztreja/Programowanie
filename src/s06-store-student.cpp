#include <iostream>
#include <fstream>
#include <fcntl.h>    /* For O_RDWR */
#include <unistd.h>

struct Student  {
        std::string const imie;
        std::string nazwisko;
        std::string nr_indeks ;
        unsigned int semestr = 1;
        double srednia;
    };

auto main() -> int
{
    Student STUDnet = { "Szymon", "Sztreja", "s26048", 3, 4.5};

    auto name = std::string {"./student.txt"};
    auto fd = open( name.c_str() , O_CREAT | O_RDWR , S_IRUSR | S_IWUSR );
// c_str
    auto buf = STUDnet;
    char bufferRead[sizeof(Student)];
    write(fd, bufferRead, sizeof(bufferRead) );
    
    close(fd);
    return 0;
}

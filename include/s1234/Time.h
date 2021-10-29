#ifndef S1234_STUDENT_H
#define S1234_STUDENT_H

#include <sstream>
#include <string>

namespace s1234 {

    struct czas
    {
        unsigned int godzina;
        unsigned int minuta;
        unsigned int sekunda;
    
    czas(unsigned int, unsigned int, unsigned int);

    auto to_string() const -> std::string;
    auto next_hour() -> void;
    auto next_minute() -> void;
    auto next_second() -> void;
    auto time_of_day() const -> enum class;
    };
    
}  

#endif

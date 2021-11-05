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
        enum class Pora{
        rano,
        dzien,
        wieczor,
        noc};
    
    czas(unsigned int, unsigned int, unsigned int);

    auto to_string() const -> std::string;
    auto next_hour() -> void;
    auto next_minute() -> void;
    auto next_second() -> void;
    auto time_of_day() const -> Pora;
    auto to_string(Pora a) -> std::string;

    auto operator+ ( czas const& T) const -> czas ;
    auto operator- ( czas const& T) const -> czas ;
    auto operator< ( czas const& T) const -> bool ;
    auto operator> ( czas const& T) const -> bool ;
    auto operator== ( czas const& T) const -> bool ;
    auto operator!= ( czas const& T) const -> bool ;

    auto count_seconds() const -> uint64_t;
    auto count_minutes() const -> uint64_t;
    auto time_to_midnight() const -> czas;
    };
    
}  

#endif

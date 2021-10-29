#include <iostream>
#include <s1234/Time.h>

s1234::czas::czas(unsigned int g, unsigned int m , unsigned int s)
    : godzina{g}, minuta{m}, sekunda{s} {}

auto s1234::czas::to_string() const -> std::string
{
    auto godz_out = std::ostringstream{};
    
    if(godzina < 10)
    godz_out << "0" << godzina;
    else
    godz_out << godzina;
        godz_out << ':';
    if(minuta < 10)
    godz_out << "0" << minuta;
    else
    godz_out << minuta;
        godz_out << ':';
    if(sekunda < 10)
    godz_out << "0" << sekunda;
    else
    godz_out << sekunda;
    
    return godz_out.str();
}
auto s1234::czas::next_hour() -> void
{
    if( godzina == 23 )
        godzina = 0;
    else
        godzina++;
}
auto s1234::czas::next_minute() -> void
{
    if( godzina == 23 && minuta == 59 )
        godzina = 0, minuta = 0;
    else
        minuta++;
}
auto s1234::czas::next_second() -> void
{
    if( godzina == 23 && minuta == 59 && sekunda == 59 )
        godzina = 0, minuta =0, sekunda=0;
    else
        sekunda++;
}      

auto s1234::czas::time_of_day() -> enum
{
    enum class Pora
    {
        rano,
        dzien,
        wieczor,
        noc
    }
    if(godzina >= 21 &&  godzina <= 6)
        return noc;
    else if(godzina > 6 && godzina <10)
        return rano;
    else if(godzina >= 10 && godzina <18)
        return dzien;
    else return wieczor;
}
        

auto main() -> int
{
    auto hour = s1234::czas{22,59,58};
    std::cout << hour.to_string() << '\n';

    hour.next_second();    
    std::cout << hour.to_string() << '\n';

    return 0;
}

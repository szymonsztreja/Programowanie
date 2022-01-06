#include <iostream>
#include <s1234/Time.h>
#include <cstdint> 

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
    if(minuta == 59 )
        next_hour(), minuta = 0 ;
    else
        minuta++;
}
auto s1234::czas::next_second() -> void
{
    if(sekunda == 59 )
        next_minute(), sekunda=0;
    else
        sekunda++;
}      

auto s1234::czas::time_of_day() const -> Pora
{
    if(godzina >= 6 && godzina <10)
        return Pora::rano;
    else if(godzina >= 10 && godzina <18)
        return Pora::dzien;
    else if(godzina >= 18 && godzina <21)
        return Pora::wieczor;
    else 
        return Pora::noc;
}

auto s1234::czas::to_string(Pora pora_dnia) -> std::string
{
    switch (pora_dnia)
    {
        case Pora::rano:
            return "rano";
            break;
        case Pora::dzien:
            return "dzien";
            break;
        case Pora::wieczor:
            return "wieczór";
            break;
        case Pora::noc:
            return "noc";
            break;
        default:
            return "blad";
            break;

    }
}

auto s1234::czas::operator+ ( czas const &dod) const -> czas     //dod - dodawanie
{
    unsigned int s = sekunda;
    unsigned int m = minuta;
    unsigned int g = godzina;
    
    s = s + dod.sekunda;
    m = m + dod.minuta;
    g += dod.godzina; 
    if( s > 59)
    {   
        s = s -60;
        m++;
    }
    if( m > 59)
    {   
        m -= 60;
        g++;
    }     
    if( g > 23)
    {   
        g -= 23;
    }
    
    return czas(g, m, s);
}

auto s1234::czas::operator- ( czas const &odejm) const -> czas     //dod - dodawanie
{
    int s = sekunda;
    int m = minuta;
    int g = godzina;
    
    s -= odejm.sekunda;   
    m -= odejm.minuta;
    g -= odejm.godzina;

    if( s < 0)
    {   
        s += 60;
        m--;
    }
    if( m < 0)
    {   
        m += 60;
        g--;
    }     
    if( g < 0)
    {   
        g += 23;
    }
    
    return czas(g, m, s);
}

auto s1234::czas::operator< ( czas const &Time) const -> bool
{
    if( sekunda < Time.sekunda)
        return true;
    if( sekunda >= Time.sekunda)
        return false;
    if( minuta < Time.minuta)
        return true;
    if( minuta >= Time.minuta)
        return false;
    if( godzina < Time.godzina)
        return true;
    if(sekunda >= Time.godzina)
        return false;
    return false;
}

auto s1234::czas::operator> ( czas const &Time) const -> bool
{
    if( sekunda > Time.sekunda)
        return true;
    if( sekunda <= Time.sekunda)
        return false;
    if( minuta > Time.minuta)
        return true;
    if( minuta <= Time.minuta)
        return false;
    if( godzina > Time.godzina)
        return true;
    if(sekunda <= Time.godzina)
        return false;
    return false;
}

auto s1234::czas::operator== ( czas const &Time) const -> bool
{
    if(sekunda == Time.sekunda
        && minuta == Time.minuta
        && godzina == Time.godzina)
    return true;
    
    return false;
}

auto s1234::czas::operator!= ( czas const &Time) const -> bool
{
    if(sekunda != Time.sekunda
        && minuta != Time.minuta
        && godzina != Time.godzina)
    return true;
    
    return false;
}    

auto s1234::czas::count_seconds() const -> uint64_t
{
    unsigned int c_seconds;
    c_seconds = sekunda;

    return c_seconds;
}

auto s1234::czas::count_minutes() const -> uint64_t
{
    unsigned int c_minutes;
    c_minutes = 60*minuta;
    
    return c_minutes;
}      

auto s1234::czas::time_to_midnight() const -> czas
{
    auto h_t_mn = 23-godzina; 
    auto m_t_mn = 60-minuta;
    auto s_t_mn = 60-sekunda;
    
    return czas(h_t_mn, m_t_mn, s_t_mn);
}

auto main() -> int
{
    auto hour = s1234::czas{23,59,59};
    std::cout << hour.to_string() << '\n';
    auto ttm = hour.time_to_midnight();
    std::cout << ttm.to_string() << '\n';

    hour.next_second();  
    std::cout << hour.to_string() << '\n';
    std::cout << hour.to_string(hour.time_of_day()) << '\n';

    auto hour1 = s1234::czas{14,59,59};
    std::cout << hour1.to_string() << '\n';
    std::cout << hour1.to_string(hour1.time_of_day()) << '\n';

    auto a = hour1 + s1234::czas{2,4,5};                        // dodawanie
    std::cout << a.to_string() << '\n';

    auto b = hour1 - a;                                         // odjemowanie
    std::cout << b.to_string() << '\n';
    
    auto t = s1234::czas(20,55,55);     
    
    bool d = a<b;                                               // mniejszość
    std::cout << d << '\n';                                     

    bool g = t==b;                                              // równoważność
    std::cout << g << '\n';
        
    bool u = a!=b;                                              // różnica
    std::cout << u << '\n';
//    
//    auto ttm = hour.time_to_midnight();
//    std::cout << ttm.to_string() << '\n';
    return 0;
}

#include <iostream>

auto szacowanie_znaku(int jaki_znak) -> int
{
    if(jaki_znak > 0)
        {
            jaki_znak = 1;
        }

    else if( jaki_znak == 0)
        {
            jaki_znak = 0;
        }

    else
        {
            jaki_znak = 2;
        }
    return jaki_znak;
}

auto odliczanie_w_gore(int Odliczana) -> void
{
    for( int i = 0; i >= Odliczana; Odliczana++)
    {
    std::cout << Odliczana-i << "... \n";
    } 
}

auto odliczanie_w_dol(int Odliczana) -> void
{
    for( int i = 0; i <= Odliczana; Odliczana--)
    {
    std::cout << Odliczana-i << "...\n";
    }
}

auto main(int argc, char* argv[]) -> int
{
    if (argc == 0) {
        return 1;
    }

    auto const liczba_string = std::string{argv[1]};
    int odliczana_liczba = stoi(liczba_string);
    switch ( szacowanie_znaku(odliczana_liczba) )
    {
        case 1:
        {
            odliczanie_w_dol(odliczana_liczba);
            break;
        }
//        case 0:
//        {
//            std::cout << "Podałeś 0, nie ma potrzeby odliczania do zera \n";
//            break;
//        } 
        case 2:
        {
            odliczanie_w_gore(odliczana_liczba);
            break;
        }
        default:
            std::cout << "Podałeś 0, nie ma potrzeby odliczania do zera \n";
    }
    
    return 0;
}

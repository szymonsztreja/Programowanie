#include <iostream> // for std :: cout , std :: cerr , and std :: cin
#include <string> 
#include <algorithm>
#include <iterator>
#include <vector>

//auto reverse(std::vector<std::string> v, int l_arg) -> void
//{
//    for ( int i = 0; i <= l_arg; l_arg--)
//    {
//        std::cout << v[l_arg] << ' ';
//    }
//}
//
auto main(int argc, char* argv[]) -> int
{
    if( argc <= 1)
    {
    std::cout << "Nie podano argumentów" << "\n";
    return 1;
    }

    auto vektor_arg = std::vector<std::string>{};               //tworzenie vectora z tablicy argumentów przekazanych w wierszu poleceń
    std::copy_n( argv, argc, std::back_inserter(vektor_arg));    //kopiowane argc (ilosc arg) argumenow z tablicy argv do vectora
    
    vektor_arg.erase(vektor_arg.begin());                       //usuwa z vektora pierwszy argument                        
    
    if( vektor_arg[0] == "-n")
    {   
      for( auto const& each : vektor_arg ) 
        {
            std::cout << each << "\t";
        }
    }
    else if( vektor_arg[0] == "-l")
    {
        for( auto const& each : vektor_arg ) 
        {
            std::cout << each << "\n";
        }
    }
    else if( vektor_arg[0] == "-r")
    {
        if(vektor_arg[1] == "-l")
        {
            for ( int i = 0; i <= argc; argc--)           
            {
                std::cout << vektor_arg[argc] << "\n";
            }
        }
        else if(vektor_arg[1] == "-n")
        {
            for ( int i = 0; i <= argc; argc--)           
            {
                std::cout << vektor_arg[argc] << ' ';
            }
        }
        else
        {
            for ( int i = 0; i <= argc; argc--)           
            {
                std::cout << vektor_arg[argc] << "  ";
            }
         std::cout << "\n";
        }
    }
    else 
    {
        for( auto const& each : vektor_arg ) 
        {
            std::cout << each << ' ';
        }
        std::cout << "\n";
    }
 
return 0;
}

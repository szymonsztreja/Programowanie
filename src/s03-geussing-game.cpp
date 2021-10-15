#include <iostream>
#include <cstdlib>

auto main() -> int
{
    srand (time(NULL));

     int losowa = rand() % 100;
     int LosIn;
    
    while( losowa != LosIn)
   {
        std::cout << "guess:\t";
        std::cin >> LosIn;
        if( losowa > LosIn )
            std::cout << "number too small! \n";
        else
            std::cout << "number too big!\n";
    }
    std::cout << "just right!\n";
    return 0;
}

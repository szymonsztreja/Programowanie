#include <iostream>
#include <string>

auto fizzbuzz( int N) -> void
{
    if( (N % 5) == 0 && (N % 3) == 0 )
        std::cout << "FizzBuzz\t";
    else if( (N % 5) == 0)
        std::cout << "Buzz\t";
    else if( (N % 3) == 0)
        std::cout << "Fizz\t";
}

auto main(int argc, char* argv[]) -> int
{
    if (argc != 2) {
    std::cout << "Podano złe dane!\n";
        return 1;
    }
    auto const liczba_n = std::stoi(argv[1]);
    while (!liczba_n)
    std::cout << "Podaj poprawna liczbe!\n";  
//    if(liczba_n > 0)
//    {
        for( int n = 1; n <= liczba_n; n++)
            {
                std::cout << n << "\t";
                fizzbuzz(n);
                std::cout << "\n";
            } 
//    }
//    else if(liczba_n < 0)
//    {
//        for( int n = 1; n >= liczba_n; n++)
//            {
//                std::cout << n << "\t";
//                fizzbuzz(n);
//                std::cout << "\n";
//            }
//    }
//    else std::cout << "Zero jest podzielne przed kazda liczbę oprócz zera!\n";

    return 0;
}

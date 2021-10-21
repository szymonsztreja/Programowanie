#include <iostream> 
#include <string> 
#include <cctype>

auto odliczanie(int bottles) -> void
{
    for(auto i = bottles; i > 1; --i) {
        std::cout << i << " bottles of beer on the wall,"   << i << " bottles of beer.\n"
            "Take one down, pass it around, " << i << "bottles of beer on the wall...\n";
    }
        std::cout << "1 bottle of beer on the wall,"" 1 bottle of beer.\n"
            "Take one down, pass it around, 1 bottle of beer on the wall...\n";

    if(bottles == 1) {
        std::cout << "No more bottles of beer on the wall, no more bottles of beer.\n"
            "Go to the store and buy some more, 1 bottle of beer on the wall...\n";
    } else {
        std::cout << "No more bottles of beer on the wall, no more bottles of beer.\n"
            "Go to the store and buy some more, 99 bottles of beer on the wall...\n";
    }
}    
auto is_digit(std::string s) -> bool
{
    for( std::string::size_type i = 0; i < s.length(); i++)
        if(isdigit(s[i]) == false)
            return false;
    return true;
}


auto main(int argc, char* argv[]) -> int
{
    if( argc > 2)
    {
    std::cout << "Błędne dane podaj liczbę!" << "\n";
    return 1;
    }
    
    auto base_num = 99;

    if(argc == 1)
    odliczanie(base_num);
    else{

    auto const input_digit = std::string{argv[1]};
    is_digit( input_digit );
    auto input_d = std::stoi(input_digit);

    while(input_d > base_num)
    {
        std::cout << "Podaj liczbe mniejsza lub rowna 99!";
        auto n = std::string{};
        std::getline ( std::cin, n );
        is_digit( n );
        input_d = std::stoi(n);
        std::cout << input_d << "\n";
    }
    
    odliczanie( input_d);
    } 
return 0;
}

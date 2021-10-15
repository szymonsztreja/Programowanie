#include <iostream>
#include <string>

auto main(int argc, char* argv[]) -> int
{
    if (argc == 0) {
        return 1;
    }
    auto const haslo = std::string{argv[1]};
    auto cracked_password = std::string{};

    do{
    std::cout << "password: ";
    std::getline(std::cin, cracked_password);
    }while (cracked_password.compare(haslo));

    std::cout << "ok!" << "\n";

    return 0;
}


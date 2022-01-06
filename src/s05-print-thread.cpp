#include <iostream>
#include <thread>
#include <cstdlib>
#include <ctime>
#include <vector>

//auto random_number(int a) -> int
//{
//    std::srand(std::time(NULL));
//    return rand() % a;
//}

auto Hello(int a) -> void
{
    std::cout << "Hello, " << a << "\n";
}

auto main () -> int
{   
    std::thread Threads[42];

    for( auto i = 0; i < 42; i++)
        {
            Threads[i] = std::thread(Hello, i);
        }
    
    for( auto &thread : Threads)
    {
        thread.detach();
    }

         
    return 0;
}

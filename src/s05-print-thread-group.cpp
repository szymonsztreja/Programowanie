#include <iostream>
#include <thread>
#include <vector>

auto Hello(int a) -> void
{
    std::cout << "Hello, " << a << "\n";
}

auto main () -> int
{   
    std::vector<std::thread> threads;
    int threads_group = 6;
    int threads_size = 42; 

    for( auto j = 1; j <= threads_size; j++)
    {
        threads.push_back(std::thread(Hello, j));
        if( j % threads_group == 0)
        {
            for( auto i=j-6; i < j; i++)
                threads[i].join();
        }

    }
    return 0;
}

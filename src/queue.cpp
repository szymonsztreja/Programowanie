#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <mutex>
#include <functional> //std::ref

std::mutex thread_lck;

auto queue_to_thread(std::queue<int>& ints,int ID) -> void
{
    std::lock_guard<std::mutex> lock(thread_lck);
    if( !ints.empty() )
    {
        std::cout << "THREAD - " << ID << ": " << ints.front() << '\n';
        ints.pop();
    }
}
    
auto main () -> int
{
    srand(time(0));

    auto ints = std::queue<int>{};
    std::vector<std::thread> threads;
    threads.resize(4);

    for( auto i = 0; i < 16; i++)
        ints.push(rand() % 100);
   
        
    while( !ints.empty() )
    {
        for( long unsigned i = 0; i < threads.size(); i++)     //thread.size type is long unsigned
        {
            threads[i] = std::thread(queue_to_thread, std::ref(ints), (int)i);
            // std::thread can't accept a reference
            // it must be able to copy the objects into the function it calls.
        }
        for( auto &thread : threads)
            thread.join();
    }

        
    return 0;
}

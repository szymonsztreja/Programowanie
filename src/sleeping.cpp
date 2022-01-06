#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <string>
#include <mutex>
#include <functional> //std::ref
#include <chrono>

std::mutex thread_lck;
std::vector<std::thread> threads(4);
auto ThreadsAlive = threads.size();

auto GetString(std::queue<std::string>& strings,int ID) -> void
{   
    while(true){
    thread_lck.lock();
   if( !strings.empty() && strings.front() != "")
    {
        std::cout << "thread: " << ID << ": " << strings.front() << '\n';
        strings.pop();
        thread_lck.unlock();
    }
    else if( strings.empty() )
    {
        thread_lck.unlock();
        int rndm = 10 + rand() % 90;
        std::this_thread::sleep_for(std::chrono::milliseconds(rndm));
    }
    else
    {
        strings.pop();
        std::cout << "thread: " << ID << ": exiting" << '\n';
        ThreadsAlive--;
        thread_lck.unlock();
    }

    }       
}
    
auto main () -> int
{
    srand(time(0));

    auto msg = std::queue<std::string>{};
    std::string String_to_queue;        

    for( long unsigned i = 0; i < ThreadsAlive; i++)
        {
            threads[i] = std::thread(GetString, std::ref(msg), int(i));
            threads[i].detach();
        }
 
    do{
        std::getline(std::cin, String_to_queue);
        msg.push(String_to_queue);
    }while(!(ThreadsAlive==0) );

    return 0;
}

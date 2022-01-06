#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <string>
#include <mutex>
#include <functional> //std::ref
#include <chrono>
#include <condition_variable>

std::mutex thread_lck;
std::condition_variable cv;
std::vector<std::thread> threads(4);
auto ThreadsAlive = threads.size();

auto GetString(std::queue<std::string>& strings,int ID) -> void
{  
    while(true)
    {  
   std::unique_lock<std::mutex> u_lck(thread_lck);
   std::cerr << "Waiting...\n";
   cv.wait(u_lck); 
   if( !strings.empty() && strings.front() != "")
        {
            std::cout << "thread: " << ID << ": " << strings.front() << '\n';
            strings.pop();
            u_lck.unlock();
        }
    else if( strings.empty() )
        {
            u_lck.unlock();
            int rndm = 10 + rand() % 90;
            std::this_thread::sleep_for(std::chrono::milliseconds(rndm));
        }
    else
        {
            strings.pop();
            std::cout << "thread: " << ID << ": exiting" << '\n';
            ThreadsAlive--;
            u_lck.unlock();
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
            cv.notify_all();
        }while(!(ThreadsAlive==0) );
    return 0;
}

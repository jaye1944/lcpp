#include <iostream>
#include <map>
#include <string>
#include <chrono>
#include <thread>
#include <mutex>
#define NO_THREAD 10
/*
One thread write to map and other 10 threads read from map

Thread - 7 8 => fake content
Thread - 7 9 => fake content
terminate called without an active exception
./run.sh: line 8:  7468 Aborted                 ./$FILE

*/
 
std::map<std::string, std::string> g_pages;
std::mutex g_pages_mutex;
 
void save_page(const std::string &url)
{
    // simulate a long page fetch
    
    std::string result = "fake content";
   // std::lock_guard<std::mutex> guard(g_pages_mutex);
	for (int k = 0; k < 1000000 ; k++)
	{
		std::string ke = std::to_string(k);
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		g_pages[ke] = result;
	}
}

void get_page(const std::string &url,int tid)
{
    // simulate a long page fetch
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    for (const auto &pair : g_pages) {
        std::cout << "Thread - " << tid << " " << pair.first << " => " << pair.second << '\n';
    }
}
 
 
int main() 
{
    
    std::thread art[NO_THREAD];
    
    //write to map 
    std::thread t1(save_page, "add to map");
    
    //read from map
    for (int i = 0; i < NO_THREAD; ++i) {
		art[i] = std::thread(get_page, "read from map",i);
    }
    
    //join to main
    for (int i = 0; i < NO_THREAD; ++i) {
		art[i].join();
	}
 
}

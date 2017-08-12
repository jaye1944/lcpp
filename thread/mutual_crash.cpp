#include <iostream>
#include <map>
#include <string>
#include <chrono>
#include <thread>
#include <mutex>
#include <memory>
#define NO_THREAD 10
#define ELEMENTS 10000
/*
5 thread write to map and other 5 threads read from map
*/

std::map<std::string, std::string> g_keyResult;
//std::mutex g_keyResult_mutex;

void set_page(const std::string &url,int tid)
{
    // simulate writing
	std::string t_id = std::to_string(tid);
    std::string result = "write to map " + t_id;

	for (int k = 0; k < ELEMENTS ; k++)
	{
		std::string ke = std::to_string(k);
		g_keyResult[ke] = result;
	}
}

void get_page(const std::string &url,int tid)
{
    // simulate reading 
    for (const auto &pair : g_keyResult) {
        std::cout << "Thread - " << tid << " " << pair.first << " => " << pair.second << '\n';
    }
}


int main()
{

    std::thread art[NO_THREAD];

    //read from map
    for (int i = 0; i < NO_THREAD; ++i) {
		if(i%2 != 0)
		{
			std::cout << "read i " << i << std::endl;
			art[i] = std::thread(get_page, "read from map",i);
		}
		else
		{
			std::cout << "Write i " << i << std::endl;
			art[i] = std::thread(set_page, "add to map",i);
		}
    }

    //join to main
    for (int i = 0; i < NO_THREAD; ++i) {
		art[i].join();
	}
	//t1.join();

}

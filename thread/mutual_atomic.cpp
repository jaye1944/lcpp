#include <iostream>
#include <map>
#include <string>
#include <chrono>
#include <thread>
#include <mutex>
#include <memory>
#include <atomic>
#define NO_THREAD 10
#define ELEMENTS 10000
// std::this_thread::sleep_for(std::chrono::milliseconds(10));
/*
5 thread write to map and other 5 threads read from map
*/
typedef std::map<std::string, std::string> MapResult;
//std::map<std::string, std::string> g_keyResult;
std::atomic<MapResult*> g_keyResult;
std::mutex g_keyResult_mutex;

void set_page(const std::string &url,int tid)
{
	// simulate writing
	std::string t_id = std::to_string(tid);
    std::string result = "write to map " + t_id;
	for (int k = 0; k < ELEMENTS ; k++)
	{
		std::string ke = std::to_string(k);
		MapResult* p = (MapResult*)g_keyResult;
		//p->insert(std::make_pair(ke,result));
		(*p)[ke] = result;
	}
}

void get_page(const std::string &url,int tid)
{
    // simulate reading
    MapResult* p = (MapResult*)g_keyResult;
    for (const auto &pair : *p) {
        std::cout << "Thread - " << tid << " " << pair.first << " => " << pair.second << '\n';
    }
}


int main()
{

    std::thread art[NO_THREAD];
    g_keyResult = new MapResult();
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
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
	end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end-start;
	auto mili = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed_seconds);
	std::cout << elapsed_seconds.count() << std::endl;
	std::cout << mili.count() << std::endl;
	
	//t1.join();

}

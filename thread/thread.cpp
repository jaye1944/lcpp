#include <iostream>
#include <thread>
#include <mutex>
 
static const int num_threads = 10;
std::mutex g_std_mutex; 
//This function will be called from a thread
 
void call_from_thread(int tid) 
{
	std::lock_guard<std::mutex> guard(g_std_mutex);
	std::cout << "Launched by thread " << tid << std::endl;
}
 
int main() {
    std::thread t[num_threads];
 
    //Launch a group of threads
	for (int i = 0; i < num_threads; ++i) {
		t[i] = std::thread(call_from_thread, i);
    }
 
    std::cout << "Launched from the main\n";
 
    //Join the threads with the main thread
    for (int i = 0; i < num_threads; ++i) {
		t[i].join();
	}
 
	return 0;
}

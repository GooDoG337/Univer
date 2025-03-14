#include <iostream>
#include <condition_variable>
#include <chrono>
#include <mutex>
#include <string>
#include <thread>
std::mutex m;
std::condition_variable cv;
std::string data;
bool ready = false;
bool proccessed = false;
//supurious? waiter
void worker_thread() {
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << "Worker thread started\n";
	std::unique_lock lk(m);
	cv.wait(lk, [] {return ready;});
	std::cout << "Worker thread process\n";
	data += " after processing";
	proccessed = true;
	std::cout << "Worker thread signals processing complete\n";
	lk.unlock();
	cv.notify_one();
}

void master_thread() {
	std::cout << "Master thread started\n";
	data = "Example data";
	{
		std::lock_guard<std::mutex> lk(m);
		ready = true;
		std::cout << "Maser thread signals data ready for processing\n";
	}
	cv.notify_one();
	{
		std::unique_lock lc(m);
		cv.wait(lc, [] {return proccessed;});
	}
	std::cout << "Master thread is doing something. Data: " << data << '\n';
}
int main() {
	std::thread t0(worker_thread);
	std::thread t1(master_thread);
	t1.join();
	t0.join();
	return 0;
}

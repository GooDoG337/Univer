#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::timed_mutex mtx;
void task(int id) {
	std::cout << "Thread_" << id << " tries to acquire lock?\n";
	std::unique_lock<std::timed_mutex> lock(mtx, std::defer_lock);
	if(lock.try_lock_for(std::chrono::seconds(2))) {
		std::cout << "Thread_ " << id << " acquired em?\n";
		std::this_thread::sleep_for(std::chrono::seconds(3));
		std::cout << "Thread go to sleep " << id << " what lock()?\n";
	} else {
		std::cout << "Thread_ " << id << "failed to acquire lock\n";
	}
}

int main() {
	std::thread t1(task, 1);
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::thread t2(task, 2);
	std::thread t3(task, 3);
	std::thread t4(task, 4);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	return 0;
}
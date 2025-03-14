#include <thread>
#include <iostream>
#include <mutex>
std::mutex mtx;
void task() {
	std::lock_guard<std::mutex> lock(mtx);
	std::cout << "Captured what?\n";
}

void task2() {
	std::unique_lock<std::mutex> lock(mtx);
	std::cout << "Captured resource\n";
	lock.unlock();
}

void task3() {
	std::unique_lock<std::mutex> why(mtx, std::defer_lock);
	//многопоточный код
	why.lock();
	//однопоточный код
	why.unlock();
	//многопоточный код
}

int main() {
	std::thread t1(task2);
	std::thread t2(task2);
	std::thread t3(task2);
	std::thread t4(task2);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
}
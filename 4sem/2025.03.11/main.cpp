#include <iostream>
#include <mutex>
#include <thread>
#include <shared_mutex>
//атомарные операции нельзя разделить
std::shared_mutex mtx;
int shared_data = 11;
auto readData() {
	std::shared_lock lock(mtx);
	sleep(1);
	std::cout << "Thread r_ " << std::this_thread::get_id() << ' ' << shared_data << '\n';
}

void writeData(int n) {
	std::unique_lock lock(mtx);
	shared_data = n;
	std::cout << "Thread w_ " << std::this_thread::get_id() << '\n';
}
int main() {
	std::thread t1(readData);
	std::thread t2(writeData, 42);
	std::thread t3(writeData, 14);
	std::thread t4(readData);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	return 0;
}

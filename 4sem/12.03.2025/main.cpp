#include <iostream>
#include <thread>
#include <semaphore>

std::counting_semaphore<10> semaphore(3);

void worker(int id) {
	semaphore.acquire();
	std::cout << "Thread: " << id << " acquired\n";
	semaphore.release();
	std::cout << "Thread: " << id << " released\n";

}
int main() {
	std::thread t1(worker, 1);
	std::thread t2(worker, 2);
	std::thread t3(worker, 3);
	std::thread t4(worker, 4);
	std::thread t5(worker, 5);
	std::thread t6(worker, 6);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	return 0;
}

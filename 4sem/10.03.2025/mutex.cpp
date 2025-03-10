//
// Created by stud-17 on 3/10/25.
//
#include <iostream>
#include <thread>
#include <mutex>
//MUTual EXclusion
std::mutex mut;
unsigned int counter = 0;
void irrevant() {
	mut.lock();
	for(int i = 0; i != 200000000; i++) {
		counter++;
	}
	mut.unlock();
}
int main() {
	std::thread t1(irrevant);
	std::thread t2(irrevant);
	t1.join();
	t2.join();
	std::cout << "Number after t1 and t2 " << counter << '\n';
}
#include <iostream>
#include <thread>
void printHello() {
	std::cout << "Hello\n";
}

int main() {
	/*std::jthread resultthread(printHello);
	std::this_thread::sleep_for(std::chrono::seconds(3));*/
	std::stop_source s_source;
	std::stop_token s_token;
	std::cout << "Stop posibble: " << s_token.stop_possible() << '\n';
	std::cout << "Stop request: " << s_token.stop_requested() << '\n';
	auto my_thread = std::jthread([](std::stop_token stop_token) {
		int count = 0;
		while(!stop_token.stop_requested()) {
			std::cout << count++ << '\n';
			std:std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
	});
	s_source = my_thread.get_stop_source();
	s_token = my_thread.get_stop_token();
	std::this_thread::sleep_for(std::chrono::seconds(1));
	if(s_source.stop_possible()) {
		s_source.request_stop();
		std::cout << "Stop request sent\n";
	}
	std::cout << "Stop possible " << s_source.stop_possible() << '\n';
	std::cout << "Stop request " << s_source.stop_requested() << '\n';
	return 0;
}

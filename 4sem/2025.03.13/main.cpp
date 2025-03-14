#include <iostream>
#include <mutex>
#include <thread>
#include <shared_mutex>
#include <deque>
#include <map>
#include <stdexcept>
#include <array>
#include <unistd.h>
std::timed_mutex mtx; //Guess, there're time depended operations, not result depended

class TrainStation {
private:
	std::pair<char,char> WhosHere{0,0};
public:
	char timeForward = 3;
	char timeIn = 1;
	char timeBack = 3;
	const std::string name;
	void setForwardHere(int id) {
		if(WhosHere.first != 0 && id != 0 && WhosHere.first != id) {
			throw std::logic_error("МЕТРО ПОДОРВАЛИ!!!!");
		} WhosHere.first = id;
	}
	void setBackHere(int id) {
		if((WhosHere.second != 0 && id != 0) && WhosHere.second != id) {
			throw std::logic_error("МЕТРО ПОДОРВАЛИ!!!!");
		} WhosHere.second = id;
	}
	std::pair<char,char> getIds()
	{
		return WhosHere;
	}
	TrainStation(const std::string& name):name(name){};
};

std::deque stations {
	TrainStation ("Бакмиль"),
	TrainStation ("Ичеришехер"),
	TrainStation ("Сахил"),
	TrainStation ("28 Мая"),
	TrainStation ("Гянджлик"),
	TrainStation ("Нариман Нариманов"),
};
std::map<char, float> Geolocation;

void PrintGeolocation() {
	while(true)
	{
	std::cout << "---------------------------------\n";
	for(auto& i: stations) {
		std::cout << int(i.getIds().first) << ':' << int(i.getIds().second) << '\n';
	}
	std::cout << "--------------------------------\n";
	sleep(0.1);
}
}

void PrintSituation() {
	while(true)
	{
	std::cout << "---------------------------------\n";
	for(auto& i: Geolocation) {
		std::cout << int(i.first) << ':' << i.second << '\n';
	}
	std::cout << "--------------------------------\n";
	sleep(0.1);
	}
}

class Train {
public:
	enum situation{RIDING, STILL};
	situation TrainSituation = STILL;
	char id = 0;
	char location = 0;
	enum direction{FORWARD, BACKWARD};
	direction TrainDirection = FORWARD;
	Train(char id1):id(id1){};
	void TrainMovement(char to) {
		Geolocation[id] = location;
		if(location < to) {
			TrainDirection = FORWARD;
			stations[location].setForwardHere(id);
		} else if(location > to){
			TrainDirection = BACKWARD;
			stations[location].setBackHere(id);
		} else {
			TrainSituation = RIDING;
			if(TrainDirection == FORWARD)
			{
				stations[location].setForwardHere(0);
				Geolocation[id] = location+0.5;
				sleep(stations[location].timeForward);
				Geolocation[id] = location;

				stations[location].setBackHere(id);
			} else {
				stations[location].setBackHere(0);
				Geolocation[id] = location+0.5;
				sleep(stations[location].timeBack);
				Geolocation[id] = location;
				stations[location].setForwardHere(id);
			}
		}
		while(to != location) {
			TrainSituation = STILL;
			sleep(stations[location].timeIn);
			TrainSituation = RIDING;
			if(TrainDirection == FORWARD) {
				stations[location].setForwardHere(0);
				Geolocation[id] = location+0.5;
				sleep(stations[location].timeForward);
				location++;
				Geolocation[id] = location;
				stations[location].setForwardHere(id);
			} else{
				stations[location].setBackHere(0);
				Geolocation[id] = location-0.5;
				sleep(stations[location].timeBack);
				location--;
				Geolocation[id] = location;
				stations[location].setBackHere(id);
			}
		}
		sleep(stations[location].timeIn);
	}
};


std::array<Train,2> trains {1,2};

void CircleRun(Train train) {
	while(true)
	{
		train.TrainMovement(5);
		train.TrainMovement(5);
		train.TrainMovement(0);
		train.TrainMovement(0);
	}
}

void BeautifulRun() {
	std::thread t3(PrintGeolocation);
	std::thread t1(CircleRun, trains[0]);
	sleep(1);
	std::thread t2(CircleRun, trains[1]);
	t1.join();
	t2.join();
	t3.join();
}


int main() {
	std::cout << std::thread::hardware_concurrency() << '\n';
	BeautifulRun();
	return 0;
}

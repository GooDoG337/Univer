#include <iostream>
#include <mutex>
#include <thread>
#include <shared_mutex>
#include <deque>
#include <map>
#include <stdexcept>
#include <array>
#include <unistd.h>
#include <vector>
std::timed_mutex mtx; //Guess, there're time depended operations, not result depended

class TrainStation {
private:
	std::pair<char,char> WhosHere{0,0};
public:
	char timeForward = 0;
	char timeIn = 2;
	char timeBack = 0;
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
enum Way{RED, COMMON};
std::vector stations {
	std::vector<TrainStation>{
		TrainStation ("Бакмиль"),
		TrainStation ("Нариман Нариманов"),
		TrainStation ("Гянджлик"),
		TrainStation ("28 Мая"),
		TrainStation ("Сахил"),
		TrainStation ("Ичеришехер"),
	},
	std::vector<TrainStation>{
		TrainStation ("Ази Асланов"),
		TrainStation ("Ахмедлы"),
		TrainStation ("Халглар Достлугу"),
		TrainStation ("Нефчиляр"),
		TrainStation ("Гара Гараев"),
		TrainStation ("Кероглу"),
		TrainStation ("Ульдуз"),

	}
};

void PrintGeolocation() {
	while(true)
	{
	std::cout << "---------------------------------\n";
	for(auto& i: stations) {
		std::cout << "--------------------------------\n";

		for(auto& q: i)
		{
			std::cout << int(q.getIds().first) << ':' << int(q.getIds().second) << '\n';
		}
		std::cout << "--------------------------------\n";

	}
	std::cout << "--------------------------------\n";
	sleep(1);
	system("reset");
}
}

class Train {
public:
	enum situation{RIDING, STILL};
	situation TrainSituation = STILL;
	char id = 0;
	char location = 0;
	Way WhereRide = RED;
	enum direction{FORWARD, BACKWARD};
	direction TrainDirection = FORWARD;
	Train(char id1):id(id1){};
	void TrainMovement(char to, Way ToRide) {
		if(WhereRide != ToRide)
		{
			if(TrainDirection == BACKWARD){
				stations[WhereRide][location].setBackHere(0);
				location = stations[ToRide].size()-1;
			} else {
				stations[WhereRide][location].setForwardHere(0);
				location = 0;
			}
			WhereRide = ToRide;
		}
		std::unique_lock<std::timed_mutex> lock(mtx, std::defer_lock);
		if(location < to) {
			TrainDirection = FORWARD;
			stations[WhereRide][location].setForwardHere(id);
		} else if(location > to){
			TrainDirection = BACKWARD;
			stations[WhereRide][location].setBackHere(id);
		} else {
			TrainSituation = RIDING;
			if(TrainDirection == FORWARD) {
				stations[WhereRide][location].setForwardHere(0);
				sleep(stations[WhereRide][location].timeForward);
				stations[WhereRide][location].setBackHere(id);
			} else {
				stations[WhereRide][location].setBackHere(0);
				sleep(stations[WhereRide][location].timeBack);
				stations[WhereRide][location].setForwardHere(id);
			}
		}
		while(to != location) {
			TrainSituation = STILL;
			sleep(stations[WhereRide][location].timeIn);
			TrainSituation = RIDING;
			if(TrainDirection == FORWARD) {
				stations[WhereRide][location].setForwardHere(0);
				sleep(stations[WhereRide][location].timeForward);
				location++;
				stations[WhereRide][location].setForwardHere(id);
			} else{
				stations[WhereRide][location].setBackHere(0);
				sleep(stations[WhereRide][location].timeBack);
				location--;
				stations[WhereRide][location].setBackHere(id);
			}
		}
		sleep(stations[WhereRide][location].timeIn);
	}
};

void CircleRun(Train train) {
		train.TrainMovement(5,RED);
		train.TrainMovement(5,RED);
		train.TrainMovement(0,RED);
		train.TrainMovement(0, COMMON);
		train.TrainMovement(0, COMMON);
		train.TrainMovement(6, COMMON);
		train.TrainMovement(0,RED);
		train.TrainMovement(5,RED);
}

int main() {
	std::thread t3(PrintGeolocation);
	std::thread t1(CircleRun, Train(1));
	t3.join();
	t1.join();
}

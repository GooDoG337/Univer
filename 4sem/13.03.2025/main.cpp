#include <iostream>
#include <mutex>
#include <thread>
#include <shared_mutex>
#include <deque>
#include <map>
#include <stdexcept>
#include <array>
//атомарные операции нельзя разделить

class TrainStation {
private:
	char idForward = 0;
	char idBack = 0;
	std::pair<char,char> WhosHere{0,0};
public:
	char timeForward = 3;
	char timeIn = 1;
	char timeBack = 3;
	const std::string name;
	void setForwardId(const char id) {
		if(idForward != 0 && id != 0) {
			throw std::logic_error("МЕТРО ВЗОРВАЛИ ТАЛИБЫ");
		}
		idForward = id;
	}
	void setBackId(const char id) {
		if(idBack != 0 && id != 0) {
			throw std::logic_error("МЕТРО ВЗОРВАЛИ ТАЛИБЫ");
		}
		idBack = id;
	}
	void setForwardHere() {
		if(WhosHere.first != 0) {
			throw std::logic_error("МЕТРО ПОДОРВАЛИ!!!!");
		} WhosHere.first = idForward;
		idForward = 0;
	}
	void setBackHere() {
		if(WhosHere.second != 0) {
			throw std::logic_error("МЕТРО ПОДОРВАЛИ!!!!");
		} WhosHere.second = idBack;
		idBack = 0;
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
	for(const auto& i: Geolocation) {
		std::cout << int(i.first) << ':' << i.second << '\n';
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
		if(location < to) {
			TrainDirection = FORWARD;
		} else if(location > to){
			TrainDirection = BACKWARD;
		} else { //ладно, может быть оно на конечной?
			std::cout << int(id) << " eдет с " << stations[location].name << '\n';
			TrainSituation = RIDING;
			Geolocation[id] = location+0.5;
			sleep(stations[location].timeForward);
			Geolocation[id] = location;
			std::cout << int(id) << " доехал до " << stations[location].name << '\n';
			TrainSituation = STILL;
			std::cout << int(id) << " cобирает народ на " << stations[location].name << '\n';
			sleep(stations[location].timeIn);
		}
		while(to != location) {
			std::cout << int(id) << " eдет с " << stations[location].name << '\n';
			TrainSituation = RIDING;
			if(TrainDirection == FORWARD) {
				Geolocation[id] = location+0.5;
				sleep(stations[location].timeForward);
				location++;
			} else {
				Geolocation[id] = location-0.5;
				sleep(stations[location].timeBack);
				location--;
			}
			Geolocation[id] = location;
			std::cout << int(id) << " доехал до " << stations[location].name << '\n';
			TrainSituation = STILL;
			std::cout << int(id) << " cобирает народ на " << stations[location].name << '\n';
			sleep(stations[location].timeIn);
		}
	}
};

void TrainRiding(int id) {
	char indx = 0;
	std::cout << "GOOOOD MORNING VIETNAM, WE HAVE BEGAN IN " << stations[indx].name << '\n';
	stations[indx].setForwardId(id);
	sleep(stations[indx].timeForward);
	indx++;
	while(true) {
		while(indx != stations.size()-1) {
			std::cout << id << " поезд доехал до " << stations[indx].name << '\n';
			sleep(stations[indx].timeIn);
			std::cout << id << " QAPLAR BAGLANIR NOVBETI STANSIYASI  " << stations[indx+1].name << '\n';
			stations[indx].setForwardId(id);
			sleep(stations[indx].timeForward);
			indx++;

		}
		return;
		for(auto i = stations.crbegin(); i != stations.crend()-1; ++i) {
			//riding[id] = false;
			std::cout << id << " поезд доехал до " << (*i).name << '\n';
			sleep(3);
		}
		std::cout << "WE ARE ON THE HIGGHWAY TO HELL. Next station is " << (*stations.cbegin()).name << '\n';
		sleep(3);
		return;
	}
}
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

std::array<Train,2> trains {1,2};

void CircleRun(Train train) {
	while(true) {
		train.TrainMovement(5);
		train.TrainMovement(5);
		train.TrainMovement(0);
		train.TrainMovement(0);
	}
}

void BeautifulRun() {
	std::thread t1(CircleRun, trains[0]);
	sleep(7);
	std::thread t2(CircleRun, trains[1]);
	t1.join();
	t2.join();
}


int main() {
	BeautifulRun();
	return 0;
}

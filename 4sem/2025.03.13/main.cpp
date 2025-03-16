#include <iostream>
#include <mutex>
#include <thread>
#include <shared_mutex>
#include <stdexcept>
#include <unistd.h>
#include <vector>
#include <mutex>
#include <chrono>
#include <memory>
 //Guess, there're time depended operations, not result depended
class TrainStation {
	private:
	std::pair<char,char> WhosHere{0,0};
	bool isOneWayStation = false;
public:
std::shared_ptr<std::mutex> ForwardMutex = std::make_shared<std::mutex>();
std::shared_ptr<std::mutex> BackwardMutex = std::make_shared<std::mutex>();
	TrainStation(const std::string& name, bool isOneWay):name(name), isOneWayStation(isOneWay){
	};
	TrainStation(const std::string& name):name(name){

	};
	const std::string name;
	char timeForward = 1;
	char timeIn = 3;
	char timeBack = 1;
	void setBackHere(int id) {
		if(WhosHere.second != 0 && id != 0) {
			throw std::logic_error("Какого хрена поезд заехал в поезд по пути НАЗАД?");
		} else if(isOneWayStation) {
			throw std::logic_error("Какого хрена оно пытается во вторую линию-?");
		} if(id == 0)
		{
				WhosHere.second = id;
		} else {
			WhosHere.second = id;
		}
	}
	void setForwardHere(int id) {
		if(WhosHere.first != 0 && id != 0) {
			throw std::logic_error("Какого хрена поезд заехал в поезд по пути ВПЕРЁД?");
		} if(id == 0)
		{
				WhosHere.first = id;
		} else {
			WhosHere.first = id;
		}
	}
	char getBackward()
	{
		if(isOneWayStation)
		{
			throw std::logic_error("Вторую платформу достроят но не сегодня");
		} return WhosHere.second;
	}
	char getForward()
	{
		return WhosHere.first;
	}
	bool isOnePlatform() {
		return isOneWayStation;
	}
};

enum Way{RED, COMMON, LIGHT_GREEN, PURPLE,GREEN};
std::vector<std::vector<TrainStation>> stations {
	std::vector<TrainStation>{
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
	},
	std::vector<TrainStation>{
		TrainStation ("Джафар Джабарлы"),
		TrainStation ("Шах Исмаил Хатаи "),
	},
	std::vector<TrainStation>{
		TrainStation("Ходжасан", true),
		TrainStation ("Автовокзал"),
		TrainStation ("Мемар Эджеми с фиолетовой"),
		 TrainStation ("8 Ноября"),
	},
	std::vector<TrainStation>{
		TrainStation ("Нариман Нариманов"),
		TrainStation ("Гянджлик"),
		TrainStation ("28 Мая"),
		TrainStation ("Низами"),
		TrainStation ("Елмляр академия"),
		TrainStation ("Иншатчылар"),
		TrainStation ("20 Января"),
		TrainStation ("Мемар эджеми с зеленой"),
		TrainStation ("Нязими"),
		TrainStation ("Азадлых проспект"),
		TrainStation ("Дарняг"),
	},
};


void PrintGeolocation() {
	while(true)
	{
	std::cout << "---------------------------------\n";
	for(auto& i: stations) {
		std::cout << "--------------------------------\n";

		for(auto& q: i)
		{
			if(!q.isOnePlatform())
			{
				std::cout << int(q.getForward()) << ':' << int(q.getBackward()) << '\n';
			} else{
				std::cout << '-' << int(q.getForward()) << "-\n";
			}
		}
		std::cout << "--------------------------------\n";

	}
	std::cout << "--------------------------------\n";
	sleep(1);
	system("reset");
}
}

class Train {
private:
	std::shared_ptr<std::unique_lock<std::mutex>> ForwardLock;
    std::shared_ptr<std::unique_lock<std::mutex>> BackwardLock;
	std::shared_ptr<std::mutex> PrintMutex = std::make_shared<std::mutex>();
public:
	char id = 0;
	char location = 0;
	Way WhereRide = RED;
	enum direction{FORWARD, BACKWARD};
	direction TrainDirection = FORWARD;
	Train(char id1, Way ride):id(id1),WhereRide(ride){
		ForwardLock = std::make_shared<std::unique_lock<std::mutex>>(*stations[ride][location].ForwardMutex, std::defer_lock);
	};
	void TrainMovement(char to, Way ToRide) {
		if(TrainDirection == FORWARD)
		{
			ForwardLock = std::make_shared<std::unique_lock<std::mutex>>(*stations[ToRide][location].ForwardMutex, std::defer_lock);
		}
		else {		BackwardLock = std::make_shared<std::unique_lock<std::mutex>>(*stations[ToRide][location].BackwardMutex, std::defer_lock); }
		if(WhereRide != ToRide)
		{
			if(TrainDirection == BACKWARD){
				if(BackwardLock.get()->owns_lock())
				{
					stations[WhereRide][location].setBackHere(0);
					BackwardLock.get()->unlock();
				}
				else { throw std::logic_error("THIS IS KALi LINUX OS \n");}
				location = stations[ToRide].size()-1;
			} else {
				if(ForwardLock.get()->owns_lock()) {
					stations[WhereRide][location].setForwardHere(0);
					ForwardLock.get()->unlock();
				}
				else { throw std::logic_error("THIS IS KALi LINUX OS \n");}
				location = 0;
			}
			WhereRide = ToRide;
		}
		if(location < to) {
			TrainDirection = FORWARD;
			//stations[WhereRide][location].first.setForwardHere(id);
		} else if(location > to){
			TrainDirection = BACKWARD;
			if(stations[WhereRide][location].isOnePlatform())
			{
				ForwardLock.get()->lock();
				stations[WhereRide][location].setForwardHere(id);
			}
			//stations[WhereRide][location].first.setBackHere(id);
		} else {
			if(TrainDirection == FORWARD) {
				if(ForwardLock.get()->owns_lock()) {
					stations[WhereRide][location].setForwardHere(0);
					ForwardLock.get()->unlock();
				}
				else {
					throw std::logic_error("THIS IS KALi LINUX OS \n");}
				{
				std::lock_guard<std::mutex> lock(*PrintMutex.get());
				std::cout << "Поезд \"" << int(id) << "\" свалил с " << stations[WhereRide][location].name << '\n';
				}
				sleep(stations[WhereRide][location].timeForward);
				BackwardLock.get()->lock();
				stations[WhereRide][location].setBackHere(id);
				TrainDirection = BACKWARD;
			} else {
				if(!stations[WhereRide][location].isOnePlatform())
				{
					if(BackwardLock.get()->owns_lock()) {
						stations[WhereRide][location].setBackHere(0);
						BackwardLock.get()->unlock();
					}	else { throw std::logic_error("THIS IS KALi LINUX OS \n");}

				} else {
					if(ForwardLock.get()->owns_lock()) {
						stations[WhereRide][location].setForwardHere(0);
						ForwardLock.get()->unlock();
					} else { throw std::logic_error("THIS IS KALi LINUX OS \n");}
				}
				{
					std::lock_guard<std::mutex> lock(*PrintMutex.get());
				std::cout << "Поезд \"" << int(id) << "\" свалил с " << stations[WhereRide][location].name << '\n';
				}
				if(!stations[WhereRide][location].isOnePlatform())
				{
					sleep(stations[WhereRide][location].timeForward);
				} else {
					sleep(stations[WhereRide][location].timeBack);
				}
				ForwardLock.get()->lock();
				stations[WhereRide][location].setForwardHere(id);
				TrainDirection = BACKWARD;
			}
			{
				std::lock_guard<std::mutex> lock(*PrintMutex.get());
			std::cout << "Поезд \"" << int(id) << "\" доехал и ждёт бомжей на " << stations[WhereRide][location].name << '\n';
			}
			sleep(stations[WhereRide][location].timeIn);
			{
				std::lock_guard<std::mutex> lock(*PrintMutex.get());
			std::cout << "Поезд \"" << int(id) << "\" дождался и свалил с " << stations[WhereRide][location].name << '\n';
			}
		}
		while(to != location) {
			if(TrainDirection == FORWARD) {
				if(ForwardLock.get()->owns_lock()) {
					stations[WhereRide][location].setForwardHere(0);
					ForwardLock.get()->unlock();
				} 				else {" THIS IS KALi LINUX OS \n";}

				if(location != stations[WhereRide].size()-1) {
					std::lock_guard<std::mutex> lock(*PrintMutex.get());
					std::cout << "Поезд \"" << int(id) << "\" свалил на " << stations[WhereRide][location].name << '\n';
				}
				sleep(stations[WhereRide][location].timeForward);
				location++;
				ForwardLock = std::make_shared<std::unique_lock<std::mutex>>(*stations[WhereRide][location].ForwardMutex, std::defer_lock);
				{
					std::lock_guard<std::mutex> lock(*PrintMutex.get());
				std::cout << "Поезд \"" << int(id) << "\" доехал и ждёт бомжей на " << stations[WhereRide][location].name << '\n';
				}
				ForwardLock.get()->lock();			
				stations[WhereRide][location].setForwardHere(id);
			} else{
				if(BackwardLock.get()->owns_lock()) {
					stations[WhereRide][location].setBackHere(0);
					BackwardLock.get()->unlock();
				} else { throw std::logic_error("THIS IS KALi LINUX OS \n");}

				if(location != stations[WhereRide].size()-1) {
						std::lock_guard<std::mutex> lock(*PrintMutex.get());
					std::cout << "Поезд \"" << int(id) << "\" свалил с на " << stations[WhereRide][location].name << '\n';
				} sleep(stations[WhereRide][location].timeBack);
				location--;
				BackwardLock = std::make_shared<std::unique_lock<std::mutex>>(*stations[WhereRide][location].BackwardMutex, std::defer_lock);
				{
					std::lock_guard<std::mutex> lock(*PrintMutex.get());
				std::cout << "Поезд \"" << int(id) << "\" доехал и ждёт бомжей на " << stations[WhereRide][location].name << '\n';
				}
				if(stations[WhereRide][location].isOnePlatform())
				{
					ForwardLock.get()->lock();
					stations[WhereRide][location].setForwardHere(id);
				} else {
					BackwardLock.get()->lock();
					stations[WhereRide][location].setBackHere(id);
				}
			}
			sleep(stations[WhereRide][location].timeIn);
		}
	}
};

void CircleRun(Train train) {
	while(true) {
		train.TrainMovement(stations[RED].size()-1,RED);
		train.TrainMovement(stations[RED].size()-1,RED);
		train.TrainMovement(0,RED);
		train.TrainMovement(0, COMMON);
		train.TrainMovement(0, COMMON);
		train.TrainMovement(stations[COMMON].size()-1, COMMON);
	}
}

void CircleRun2(Train train) {
	while(true) {
		train.TrainMovement(stations[LIGHT_GREEN].size()-1,LIGHT_GREEN);
		train.TrainMovement(stations[LIGHT_GREEN].size()-1,LIGHT_GREEN);
		train.TrainMovement(0, LIGHT_GREEN);
		train.TrainMovement(0, LIGHT_GREEN);
	}
}
void CircleRun3(Train train) {
	while(true) {
		train.TrainMovement(stations[PURPLE].size()-1,PURPLE);
		train.TrainMovement(stations[PURPLE].size()-1,PURPLE);
		train.TrainMovement(0, PURPLE);
	}
}

void CircleRunGreen(Train train) {
	while(true) {
		train.TrainMovement(stations[GREEN].size()-1,GREEN);
		train.TrainMovement(stations[GREEN].size()-1,GREEN);
		train.TrainMovement(0,GREEN);
		train.TrainMovement(0, COMMON);
		train.TrainMovement(0, COMMON);
		train.TrainMovement(stations[COMMON].size()-1, COMMON);
	}
}
int main() {
	//std::thread t1(CircleRun2, Train(1, LIGHT_GREEN));
	//std::thread t2(CircleRun, Train(2, RED));
	std::thread t1(CircleRun3, Train(1, PURPLE));
	sleep(1);
	std::thread t2(CircleRun3, Train(2, PURPLE));
	sleep(1);
	std::thread t3(CircleRun3, Train(3, PURPLE));
	sleep(1);
	std::thread t4(CircleRun3, Train(4, PURPLE));
	//t6.join();
	t1.join();
	t2.join();
	t3.join();
	t4.join();
}

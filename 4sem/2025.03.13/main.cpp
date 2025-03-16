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

 std::mutex printer;
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
public:
	char id = 0;
	char location = 0;
	Way WhereRide = RED;
	enum direction{FORWARD, BACKWARD};
	direction TrainDirection = FORWARD;
	Train(char id1, Way ride):id(id1),WhereRide(ride){
			ForwardLock = std::make_shared<std::unique_lock<std::mutex>>(*stations[ride][location].ForwardMutex, std::defer_lock);
	};
	void ReverseMove()
	{
		if(location != 0)
		{
			location--;
		}
		ForwardLock = NULL;
		BackwardLock = std::make_shared<std::unique_lock<std::mutex>>(*stations[WhereRide][location].BackwardMutex, std::defer_lock);
		if(BackwardLock.get()->try_lock())
		{
			stations[WhereRide][location].setBackHere(id);
			TrainDirection = BACKWARD;
		} else {while(!BackwardLock.get()->try_lock()) { /*std::cout << "Всё будет хорошо\n";*/ std::this_thread::sleep_for(std::chrono::seconds(1));}}
		std::cout << "Поезд \"" << int(id) << "\" сделал круг и ждёт бомжей на " << stations[WhereRide][location].name << '\n';
		std::this_thread::sleep_for(std::chrono::seconds(stations[WhereRide][location].timeIn));
		std::cout << "Поезд \"" << int(id) << "\" дождался и сваливает из " << stations[WhereRide][location].name << '\n';
		if(BackwardLock.get()->owns_lock())
		{			
			stations[WhereRide][location].setBackHere(0);
			BackwardLock.get()->unlock();
		} else { throw std::logic_error("KALI LINUX"); }
		location--;
		std::this_thread::sleep_for(std::chrono::seconds(stations[WhereRide][location].timeBack));
	}
	void TrainMovement(char to, Way ToRide) {
		if(TrainDirection == FORWARD)
		{
			ForwardLock = std::make_shared<std::unique_lock<std::mutex>>(*stations[ToRide][location].ForwardMutex, std::defer_lock);
		}
		
			while(to != location && TrainDirection == FORWARD) {
				if(ForwardLock.get()->try_lock())
				{
					stations[WhereRide][location].setForwardHere(id);
				} else {while(!ForwardLock.get()->try_lock()) 
					{ 
						std::lock_guard<std::mutex> lock(printer);
						/*std::cout << "Всё будет хорошо\n"; */
						std::this_thread::sleep_for(std::chrono::seconds(1));}}
				{
					std::lock_guard<std::mutex> lock(printer);
					std::cout << "Поезд \"" << int(id) << "\" доехал и ждёт бомжей на " << stations[WhereRide][location].name << '\n';
				}
				std::this_thread::sleep_for(std::chrono::seconds(stations[WhereRide][location].timeIn));
				{
					std::lock_guard<std::mutex> lock(printer);
					std::cout << "Поезд \"" << int(id) << "\" дождался и сваливает из " << stations[WhereRide][location].name << '\n';
				}
				if(ForwardLock.get()->owns_lock())
				{			
					stations[WhereRide][location].setForwardHere(0);
					ForwardLock.get()->unlock();
				} else { throw std::logic_error("KALI LINUX"); }
				std::this_thread::sleep_for(std::chrono::seconds(stations[WhereRide][location].timeForward));
				location++;
				ForwardLock = std::make_shared<std::unique_lock<std::mutex>>(*stations[ToRide][location].ForwardMutex, std::defer_lock);
			}

			while(to != location && TrainDirection == BACKWARD) {
				if(location < 0)
				{
					location = 0;
				}
				if(BackwardLock.get()->try_lock())
				{
					stations[WhereRide][location].setBackHere(id);
				} else {while(!BackwardLock.get()->try_lock()) { /*std::cout << "Всё будет хорошо\n";*/ std::this_thread::sleep_for(std::chrono::seconds(1));}}
				std::cout << "Поезд \"" << int(id) << "\" доехал и ждёт бомжей на " << stations[WhereRide][location].name << '\n';
				std::this_thread::sleep_for(std::chrono::seconds(stations[WhereRide][location].timeIn));
				std::cout << "Поезд \"" << int(id) << "\" дождался и сваливает из " << stations[WhereRide][location].name << '\n';
				if(BackwardLock.get()->owns_lock())
				{			
					stations[WhereRide][location].setBackHere(0);
					BackwardLock.get()->unlock();
				} else { throw std::logic_error("KALI LINUX"); }
				std::this_thread::sleep_for(std::chrono::seconds(stations[WhereRide][location].timeBack));
				if(location != 0)
				{
					location--;
				}
				BackwardLock = std::make_shared<std::unique_lock<std::mutex>>(*stations[ToRide][location].BackwardMutex, std::defer_lock);
			}
	}
	void TravelToSinglePlatform() {
		if(BackwardLock.get()->try_lock())
		{
			stations[WhereRide][location].setForwardHere(id);
		} else {while(!BackwardLock.get()->try_lock()) { std::cout << "Всё будет хорошо\n"; std::this_thread::sleep_for(std::chrono::seconds(1));}}
		std::cout << "Поезд \"" << int(id) << "\" доехал и ждёт бомжей на " << stations[WhereRide][location].name << '\n';
		std::this_thread::sleep_for(std::chrono::seconds(stations[WhereRide][location].timeIn));
		std::cout << "Поезд \"" << int(id) << "\" дождался и сваливает из " << stations[WhereRide][location].name << '\n';
		if(BackwardLock.get()->owns_lock())
		{			
			stations[WhereRide][location].setForwardHere(0);
			BackwardLock.get()->unlock();
		} else { throw std::logic_error("KALI LINUX"); }
		std::this_thread::sleep_for(std::chrono::seconds(stations[WhereRide][location].timeForward));
		location++;
		BackwardLock = NULL;
		TrainDirection = FORWARD;
		ForwardLock = std::make_shared<std::unique_lock<std::mutex>>(*stations[WhereRide][location].ForwardMutex, std::defer_lock);
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
	while(true)
	{
		train.TrainMovement(stations[LIGHT_GREEN].size(),LIGHT_GREEN);
		train.ReverseMove();
		train.TrainMovement(0,LIGHT_GREEN);
		train.ReverseMove();
	}
}
void CircleRun3(Train train) {
	while(true)
	{
		train.TrainMovement(stations[PURPLE].size(),PURPLE);
		train.ReverseMove();
		train.TrainMovement(0,PURPLE);
		train.TravelToSinglePlatform();
	}						///ФИОЛЕТОВАЯ ЛИНИЯ, В ПЛАНАХ ДОДЕЛАТЬ ВОКЗАЛ  И СМЕНУ ТОЧКИ НАЗНАЧЕНИЯ С ВОКЗАЛА НА ХОДЖАСАН И ОБРАТНО

/*	while(true)
	{
		train.TrainMovement(stations[PURPLE].size()-1,PURPLE);
		train.TrainMovement(stations[PURPLE].size()-1,PURPLE);
		train.TrainMovement(0,PURPLE);
	}*/
}

void CircleRunGreen(Train train) {
		train.TrainMovement(stations[GREEN].size()-1,GREEN);
		train.TrainMovement(stations[GREEN].size()-1,GREEN);
		train.TrainMovement(0,GREEN);
		train.TrainMovement(0, COMMON);
		train.TrainMovement(0, COMMON);
		train.TrainMovement(stations[COMMON].size()-1, COMMON);
}
int main() {
	//std::thread t1(CircleRun2, Train(1, LIGHT_GREEN));
	std::thread t1(CircleRun3, Train(1, PURPLE));
	//std::thread t1(CircleRun2, Train(1, LIGHT_GREEN));
	t1.join();

	//std::this_thread::sleep_for(std::chrono::seconds(1));
	//std::thread t1(CircleRun3, Train(2, LIGHT_GREEN));
	//std::this_thread::sleep_for(std::chrono::seconds(1));
	//std::thread t1(CircleRun3, Train(3, LIGHT_GREEN));
	//t6.join();
	/*t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();*/
}

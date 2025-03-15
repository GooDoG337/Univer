#include <iostream>
#include <mutex>
#include <thread>
#include <shared_mutex>
#include <stdexcept>
#include <unistd.h>
#include <vector>
 //Guess, there're time depended operations, not result depended

class TrainStation_OnePlatform {
protected:
	std::pair<char,char> WhosHere{0,0};
public:
	const std::string name;
	std::mutex forward(std::defer_lock_t);
	char timeForward = 2;
	char timeIn = 2;
	TrainStation_OnePlatform(const std::string& name):name(name){};
	virtual void setForwardHere(int id) {
		if(WhosHere.first != 0 && id != 0 && WhosHere.first != id) {
			throw std::logic_error("МЕТРО ПОДОРВАЛИ!!!!");
		} WhosHere.first = id;
	}
	virtual void setBackHere(int id) {
		throw std::logic_error("Тут одна платформа");
	}
	virtual bool isUsualStation() {
		return false;
	}
	char getForward()
	{
		return WhosHere.first;
	}
};

class TrainStation: public TrainStation_OnePlatform {
public:
	std::mutex backward(std::defer_lock_t);
	char timeBack = 2;
	TrainStation(const std::string& name):TrainStation_OnePlatform(name){};
	void setBackHere(int id) override {
		if((WhosHere.second != 0 && id != 0) && WhosHere.second != id) {
			throw std::logic_error("МЕТРО ПОДОРВАЛИ!!!!");
		} WhosHere.second = id;
	}
	virtual char getBackward()
	{
		return WhosHere.second;
	}
	bool isUsualStation() override {
		return true;
	}
};
enum Way{RED, COMMON, LIGHT_GREEN, PURPLE};
std::vector stations {
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
		TrainStation ("Ходжасан"),
		TrainStation ("Автовокзал"),
		TrainStation ("Мемар Эджеми с фиолетовой"),
		TrainStation ("8 Ноября"),

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
			std::cout << int(q.getForward()) << ':' << int(q.getBackward()) << '\n';
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
	char id = 0;
	char location = 0;
	Way WhereRide = RED;
	enum direction{FORWARD, BACKWARD};
	direction TrainDirection = FORWARD;
	Train(char id1, Way ride):id(id1),WhereRide(ride){};
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
		if(location < to) {
			TrainDirection = FORWARD;
			stations[WhereRide][location].setForwardHere(id);
		} else if(location > to){
			TrainDirection = BACKWARD;
			stations[WhereRide][location].setBackHere(id);
		} else {
			if(TrainDirection == FORWARD) {
				stations[WhereRide][location].setForwardHere(0);
				std::cout << "Поезд \"" << int(id) << "\" << свалил с " << stations[WhereRide][location].name << '\n';
				sleep(stations[WhereRide][location].timeForward);
				stations[WhereRide][location].setBackHere(id);
			} else {
				stations[WhereRide][location].setBackHere(0);
				std::cout << "Поезд \"" << int(id) << "\" << свалил с " << stations[WhereRide][location].name << '\n';
				sleep(stations[WhereRide][location].timeBack);
				stations[WhereRide][location].setForwardHere(id);
			}
			std::cout << "Поезд \"" << int(id) << "\" доехал и ждёт бомжей на " << stations[WhereRide][location].name << '\n';
			sleep(stations[WhereRide][location].timeIn);
			std::cout << "Поезд \"" << int(id) << "\" дождался и свалил с " << stations[WhereRide][location].name << '\n';
		}
		while(to != location) {
			if(TrainDirection == FORWARD) {
				stations[WhereRide][location].setForwardHere(0);
				if(location != stations[WhereRide].size()-1) {
					std::cout << "Поезд свалил с \"" << int(id) << "\" на "  << stations[WhereRide][location].name << '\n';
				}
				sleep(stations[WhereRide][location].timeForward);
				location++;
				std::cout << "Поезд \"" << int(id) << "\" доехал и ждёт бомжей на " << stations[WhereRide][location].name << '\n';
				stations[WhereRide][location].setForwardHere(id);
			} else{
				stations[WhereRide][location].setBackHere(0);
				if(location != stations[WhereRide].size()-1) {
					std::cout << "Поезд свалил с \"" << int(id) << "\" на "  << stations[WhereRide][location].name << '\n';
				} sleep(stations[WhereRide][location].timeBack);
				location--;
				std::cout << "Поезд \"" << int(id) << "\" доехал и ждёт бомжей на " << stations[WhereRide][location].name << '\n';
				stations[WhereRide][location].setBackHere(id);
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
		train.TrainMovement(0, PURPLE);
	}
}
int main() {
	/*std::thread t1(CircleRun2, Train(1, LIGHT_GREEN));
	std::thread t2(CircleRun, Train(2, RED))*/;
	std::thread t6(PrintGeolocation);
	std::thread t3(CircleRun3, Train(3, PURPLE));
	sleep(5);
	std::thread t5(CircleRun3, Train(1, PURPLE));
	t6.join();
	t3.join();
	t5.join();
	/*t2.join();
	t1.join();
*/}

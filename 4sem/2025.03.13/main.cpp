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

 std::shared_mutex printer;
class TrainStation {
	private:
	std::pair<char,char> WhosHere{0,0};
	bool isOneWayStation = false;
public:
std::shared_ptr<std::mutex> ForwardMutex = std::make_shared<std::mutex>();
std::shared_ptr<std::mutex> BackwardMutex = std::make_shared<std::mutex>();
	TrainStation(const std::string& name, bool isOneWay = false, int forward = 1, int In = 3, int backward = 1):name(name), isOneWayStation(isOneWay), timeForward(forward), timeIn(In), timeBack(backward){};
	const std::string name;
	char timeForward;
	char timeIn;
	char timeBack;
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

enum Way{RED, COMMON, LIGHT_GREEN, PURPLE,GREEN, RedGreen_DEPO, Purple_DEPO};
std::vector<std::vector<TrainStation>> stations {
	std::vector<TrainStation>{
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

		TrainStation ("Нариман Нариманов"),
		TrainStation ("Гянджлик"),
		TrainStation ("28 Мая"),

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
		TrainStation ("Низами"),
		TrainStation ("Елмляр академия"),
		TrainStation ("Иншатчылар"),
		TrainStation ("20 Января"),
		TrainStation ("Мемар эджеми с зеленой"),
		TrainStation ("Нязими"),
		TrainStation ("Азадлых проспект"),
		TrainStation ("Дарняг"),
	},
	std::vector<TrainStation>{
		TrainStation ("Депо?", false, 1, 0, 1),
		TrainStation ("Бакмиль", true),
	},
	std::vector<TrainStation>{
		TrainStation ("Депо2?", false, 1, 0, 1),
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
enum direction{FORWARD, BACKWARD};

class Train {
private:
	std::shared_ptr<std::unique_lock<std::mutex>> ForwardLock;
    std::shared_ptr<std::unique_lock<std::mutex>> BackwardLock;
public:
	char WhenHome = 0;
	char id = 0;
	char location = 0;
	Way WhereRide = RED;
	direction TrainDirection = FORWARD;
	Train(char id1, Way ride):id(id1),WhereRide(ride){
			ForwardLock = std::make_shared<std::unique_lock<std::mutex>>(*stations[ride][location].ForwardMutex, std::defer_lock);
	};
	Train(char id1, Way ride, char loca) //I WILL REGRET THIS
	{
		id = id1;
		WhereRide = ride;
		location = loca;
		ForwardLock = std::make_shared<std::unique_lock<std::mutex>>(*stations[ride][location].ForwardMutex, std::defer_lock);
	}
	void TransferLine(Way TransferTo, char loc = 0) {
		WhereRide = TransferTo;
		if(TrainDirection == FORWARD)
		{
			location = loc;
		}
		else if(loc == 0){
			location = stations[TransferTo].size()-1;
		} else {
			location = loc;
		}
	}
	void ReverseMove()
	{
		if(TrainDirection == BACKWARD)
		{
			BackwardLock = NULL;
			ForwardLock = std::make_shared<std::unique_lock<std::mutex>>(*stations[WhereRide][location].ForwardMutex, std::defer_lock);
			if(ForwardLock.get()->try_lock())
			{
				stations[WhereRide][location].setForwardHere(id);
				TrainDirection = FORWARD;
			} else {
				while(!ForwardLock.get()->try_lock()) {
					/*std::cout << "Всё будет хорошо\n";*/ 
					std::this_thread::sleep_for(std::chrono::seconds(1));
				}
				stations[WhereRide][location].setForwardHere(id);
				TrainDirection = FORWARD;
			}
			{
				std::lock_guard<std::shared_mutex> lock(printer);
				std::cout << "Поезд \"" << int(id) << "\" сделал круг и ждёт бомжей на " << stations[WhereRide][location].name << '\n';
			}
			std::this_thread::sleep_for(std::chrono::seconds(stations[WhereRide][location].timeIn));
			{
				std::lock_guard<std::shared_mutex> lock(printer);
				std::cout << "Поезд \"" << int(id) << "\" дождался и сваливает из " << stations[WhereRide][location].name << '\n';
			}
			if(ForwardLock.get()->owns_lock())
			{			
				stations[WhereRide][location].setForwardHere(0);
				ForwardLock.get()->unlock();
			} else { throw std::logic_error("ARCH LINUX"); }
			location++;
			std::this_thread::sleep_for(std::chrono::seconds(stations[WhereRide][location].timeBack));
		} else {
			ForwardLock = NULL;
			BackwardLock = std::make_shared<std::unique_lock<std::mutex>>(*stations[WhereRide][location].BackwardMutex, std::defer_lock);
			if(BackwardLock.get()->try_lock())
			{
				stations[WhereRide][location].setBackHere(id);
				TrainDirection = BACKWARD;
			} else {
				while(!BackwardLock.get()->try_lock()) {
					/*std::cout << "Всё будет хорошо\n";*/ 
					std::this_thread::sleep_for(std::chrono::seconds(1));
				}
				stations[WhereRide][location].setBackHere(id);
				TrainDirection = BACKWARD;
			}
			{
				std::lock_guard<std::shared_mutex> lock(printer);
				std::cout << "Поезд \"" << int(id) << "\" сделал круг и ждёт бомжей на " << stations[WhereRide][location].name << '\n';
			}
			std::this_thread::sleep_for(std::chrono::seconds(stations[WhereRide][location].timeIn));
			{
				std::lock_guard<std::shared_mutex> lock(printer);
				std::cout << "Поезд \"" << int(id) << "\" дождался и сваливает из " << stations[WhereRide][location].name << '\n';
			}
			if(BackwardLock.get()->owns_lock())
			{			
				stations[WhereRide][location].setBackHere(0);
				BackwardLock.get()->unlock();
			} else { throw std::logic_error("KALI LINUX"); }
			location--;
			std::this_thread::sleep_for(std::chrono::seconds(stations[WhereRide][location].timeBack));
		}
	}
	bool TrainMovement(char to, Way ToRide) {
		if(TrainDirection == FORWARD)
		{
			ForwardLock = std::make_shared<std::unique_lock<std::mutex>>(*stations[ToRide][location].ForwardMutex, std::defer_lock);
			BackwardLock = NULL;
		} else {
			BackwardLock = std::make_shared<std::unique_lock<std::mutex>>(*stations[ToRide][location].BackwardMutex, std::defer_lock);
			ForwardLock = NULL;
		}
			while(to != location && TrainDirection == FORWARD) {
				if(ForwardLock.get()->try_lock())
				{
					stations[WhereRide][location].setForwardHere(id);
				} else {
					while(!ForwardLock.get()->try_lock()) { 
					//	std::lock_guard<std::shared_mutex> lock(printer);
						/*std::cout << "Всё будет хорошо\n"; */
						std::this_thread::sleep_for(std::chrono::seconds(1));
					}
					stations[WhereRide][location].setForwardHere(id);
				}
				{
					std::lock_guard<std::shared_mutex> lock(printer);
					std::cout << "Поезд \"" << int(id) << "\" доехал и ждёт бомжей на " << stations[WhereRide][location].name << '\n';
				}
				std::this_thread::sleep_for(std::chrono::seconds(stations[WhereRide][location].timeIn));
				{
					std::lock_guard<std::shared_mutex> lock(printer);
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
			if(TrainDirection == FORWARD)
			{
				location--;
			}

			while(to != location && TrainDirection == BACKWARD) {
				if(BackwardLock.get()->try_lock())
				{
					stations[WhereRide][location].setBackHere(id);
				} else {
					while(!BackwardLock.get()->try_lock()) { 
						/*std::cout << "Всё будет хорошо\n";*/ 
						std::this_thread::sleep_for(std::chrono::seconds(1));
					}
					stations[WhereRide][location].setBackHere(id);
				}
				{
					std::lock_guard<std::shared_mutex> lock(printer);
					std::cout << "Поезд \"" << int(id) << "\" доехал и ждёт бомжей на " << stations[WhereRide][location].name << '\n';
				}
				std::this_thread::sleep_for(std::chrono::seconds(stations[WhereRide][location].timeIn));
				if(WhereRide == COMMON && location == 7 && TrainDirection == BACKWARD && WhenHome == 127)
				{
					if(BackwardLock.get()->owns_lock())
					{			
						stations[WhereRide][location].setBackHere(0);
						BackwardLock.get()->unlock();
					} else { throw std::logic_error("KALI LINUX"); }
					{
						std::lock_guard<std::shared_mutex> lock(printer);
						std::cout << "Поезд \"" << int(id) << "\" дождался и сваливает из " << stations[WhereRide][location].name << '\n';
					}
					return true; //Теперь едем нахрен на депо?
				}
				else if(WhereRide == PURPLE && location == 1 && TrainDirection == BACKWARD && WhenHome == 127)
				{
					if(BackwardLock.get()->owns_lock())
					{			
						stations[WhereRide][location].setBackHere(0);
						BackwardLock.get()->unlock();
					} else { throw std::logic_error("KALI LINUX"); }
					{
						std::lock_guard<std::shared_mutex> lock(printer);
						std::cout << "Поезд \"" << int(id) << "\" дождался и сваливает из " << stations[WhereRide][location].name << '\n';
					}
					return true; //Теперь едем нахрен на депо?
				}
				{
					std::lock_guard<std::shared_mutex> lock(printer);
					std::cout << "Поезд \"" << int(id) << "\" дождался и сваливает из " << stations[WhereRide][location].name << '\n';
				}
				if(BackwardLock.get()->owns_lock())
				{			
					stations[WhereRide][location].setBackHere(0);
					BackwardLock.get()->unlock();
				} else { throw std::logic_error("KALI LINUX"); }
				std::this_thread::sleep_for(std::chrono::seconds(stations[WhereRide][location].timeBack));
				location--;
				BackwardLock = std::make_shared<std::unique_lock<std::mutex>>(*stations[ToRide][location].BackwardMutex, std::defer_lock);
			}
			if(TrainDirection == BACKWARD)
			{
				location++;
			}
			return false; //какой нахрен бакмил?
	}
	void TravelToSinglePlatform() {
		location--;
		if(BackwardLock.get()->try_lock())
		{
			stations[WhereRide][location].setForwardHere(id);
		} else {while(!BackwardLock.get()->try_lock()) { /*std::cout << "Всё будет хорошо\n";*/ std::this_thread::sleep_for(std::chrono::seconds(1));}}
		{					
			std::lock_guard<std::shared_mutex> lock(printer);
			std::cout << "Поезд \"" << int(id) << "\" доехал и ждёт бомжей на " << stations[WhereRide][location].name << '\n';
		}
		std::this_thread::sleep_for(std::chrono::seconds(stations[WhereRide][location].timeIn));
		{
			std::lock_guard<std::shared_mutex> lock(printer);
			std::cout << "Поезд \"" << int(id) << "\" дождался и сваливает из " << stations[WhereRide][location].name << '\n';
		}
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
	void TravelToSinglePlatform_BACKWARD() {
		location = 0;
		BackwardLock = std::make_shared<std::unique_lock<std::mutex>>(*stations[WhereRide][location].BackwardMutex, std::defer_lock);
		ForwardLock = NULL;
		if(BackwardLock.get()->try_lock())
		{
			stations[WhereRide][location].setBackHere(id);
		} else {
			while(!BackwardLock.get()->try_lock()) {
				/*std::cout << "Всё будет хорошо\n";*/ 
				std::this_thread::sleep_for(std::chrono::seconds(1));
			}
			stations[WhereRide][location].setBackHere(id);
		}
		std::this_thread::sleep_for(std::chrono::seconds(stations[WhereRide][location].timeBack));
		if(BackwardLock.get()->owns_lock())
		{			
			stations[WhereRide][location].setBackHere(0);
			BackwardLock.get()->unlock();
		} else { throw std::logic_error("ARCH LINUX"); }
		{
			std::lock_guard<std::shared_mutex> lock(printer);
			std::cout << "Поезд \"" << int(id) << "\" в общем складу, я сомневаюсь что надо с ним дальше работать" << stations[WhereRide][location].name << '\n';
		}
	}
};
void CircleRun_Green(int id) {
	Train train(id, RedGreen_DEPO);
	train.TrainMovement(stations[RedGreen_DEPO].size(), RedGreen_DEPO);
	train.TransferLine(COMMON, 7); //6 v common
	Way change = GREEN;
	while(true)
	{
		train.TrainMovement(stations[COMMON].size(), COMMON);
		train.TransferLine(change);
		train.TrainMovement(stations[change].size(), change);
		train.ReverseMove();
		train.TrainMovement(-1, change);
		train.TransferLine(COMMON);
		if(!train.TrainMovement(-1, COMMON)) {
			train.ReverseMove();
			if(change == RED) {change = GREEN;}
			else {change = RED;}
		} else { break; }
	}
	train.TransferLine(RedGreen_DEPO); //6 v common
	train.TravelToSinglePlatform();
	train.TravelToSinglePlatform_BACKWARD();		//Без возврата на путь

}

void CircleRun_LightGreen(int id) {
	Train train(id, LIGHT_GREEN);
	while(true)
	{
		train.TrainMovement(stations[LIGHT_GREEN].size(),LIGHT_GREEN);
		train.ReverseMove();
		train.TrainMovement(-1,PURPLE);
		train.ReverseMove();
	}
}
void CircleRun_Purple(int id) {
	Train train(id, Purple_DEPO);
	train.TrainMovement(stations[Purple_DEPO].size(), Purple_DEPO);
	train.TransferLine(PURPLE, 1); //6 v common
	while(true)
	{
		train.TrainMovement(stations[PURPLE].size(),PURPLE);
		train.ReverseMove();
		if(!train.TrainMovement(0,PURPLE))
		{
			train.TravelToSinglePlatform();
		}  else { break; }

	}
	train.TransferLine(Purple_DEPO); //6 v common
	train.TravelToSinglePlatform_BACKWARD();		//Без возврата на путь

						///ФИОЛЕТОВАЯ ЛИНИЯ, В ПЛАНАХ ДОДЕЛАТЬ ВОКЗАЛ  И СМЕНУ ТОЧКИ НАЗНАЧЕНИЯ С ВОКЗАЛА НА ХОДЖАСАН И ОБРАТНО

/*	while(true)
	{
		train.TrainMovement(stations[PURPLE].size()-1,PURPLE);
		train.TrainMovement(stations[PURPLE].size()-1,PURPLE);
		train.TrainMovement(0,PURPLE);
	}*/
}

void CircleRun_Red(int id) {
	
//	Train train(id, COMMON, 6);
	Train train(id, RedGreen_DEPO);
	train.TrainMovement(stations[RedGreen_DEPO].size(), RedGreen_DEPO);
	train.TransferLine(COMMON, 7); //6 v common
	Way change = RED;
	while(true)
	{
		train.TrainMovement(stations[COMMON].size(), COMMON);
		train.TransferLine(change);
		train.TrainMovement(stations[change].size(), change);
		train.ReverseMove();
		train.TrainMovement(-1, change);
		train.TransferLine(COMMON);
		if(!train.TrainMovement(-1, COMMON)) {
			train.ReverseMove();
			if(change == RED) {change = GREEN;}
			else {change = RED;}
		} else { break; }
	}
	train.TransferLine(RedGreen_DEPO); //6 v common
	train.TravelToSinglePlatform();
	train.TravelToSinglePlatform_BACKWARD();		//Без возврата на путь
}
int main() {
	//std::thread t1(CircleRun2, Train(1, LIGHT_GREEN));
	std::thread t1(CircleRun_Green, 1);
	/*std::thread t2(CircleRun_Purple, 2);
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::thread t3(CircleRun_Purple, 3);
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::thread t4(CircleRun_Purple, 4);
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::thread t5(CircleRun_Purple, 5);
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::thread t6(CircleRun_Purple, 6);*/
	//std::thread t1(CircleRun2, Train(1, LIGHT_GREEN));
	t1.join();
	/*t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();*/
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

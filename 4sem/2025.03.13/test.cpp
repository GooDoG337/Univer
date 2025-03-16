#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <memory>

class TrainStation {
    std::pair<char, char> WhosHere{0, 0};
    bool isOneWayStation = false;
    std::shared_ptr<std::shared_mutex> ForwardMutex = std::make_shared<std::shared_mutex>();
    std::shared_ptr<std::shared_mutex> BackwardMutex = std::make_shared<std::shared_mutex>();
    std::shared_ptr<std::shared_lock<std::shared_mutex>> ForwardLock;
    std::shared_ptr<std::shared_lock<std::shared_mutex>> BackwardLock;

public:
    TrainStation() {
        // Инициализация указателей на shared_lock
        ForwardLock = std::make_shared<std::shared_lock<std::shared_mutex>>(*ForwardMutex, std::defer_lock);
        BackwardLock = std::make_shared<std::shared_lock<std::shared_mutex>>(*BackwardMutex, std::defer_lock);
    }
};

int main() {
    return 0;
}
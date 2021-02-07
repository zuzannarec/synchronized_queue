#include "log_consumer.h"
#include <variant>

LogConsumer::LogConsumer(std::shared_ptr<MyLogQueue>& queue_ptr)
{
    this->queue_ptr = queue_ptr;
}
 
void LogConsumer::ConsumeLog()
{
    while (true)
    {
        std::cout << "Pulling from queue..." << std::endl;
        auto message = this->queue_ptr->GetFromQueue();
        std::cout << "Log consumer got message: " << message << std::endl;
        std::chrono::milliseconds timespan(rand() % 1000);
        std::this_thread::sleep_for(timespan);
    }
}

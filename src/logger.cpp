#include <exception>
#include "logger.h"

Logger::Logger(std::shared_ptr<MyLogQueue>& queue_ptr)
{
    this->queue = queue_ptr;
    std::cout << "Logger created!" << std::endl;
}

void Logger::Log(std::string message)
{
    std::cout << "Log message in logger: " << message << std::endl;
    this->queue->AddToQueue(message);
}

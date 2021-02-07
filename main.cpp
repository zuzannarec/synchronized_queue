#include <stdint.h>
#include <iostream>
#include <exception>
#include <thread>
#include <memory>
#include <chrono>
#include "logger.h"
#include "log_consumer.h"


void logging(Logger& logger)
{
    int i = 0;
    while (true)
    {
        logger.Log("Message number " + std::to_string(i));
        i++;
        std::chrono::milliseconds timespan(rand() % 500);
        std::this_thread::sleep_for(timespan);
    }
}

int main()
{
    try
    {      
        std::shared_ptr<MyLogQueue> queue_ptr = std::make_shared<MyLogQueue>();
        Logger logger(queue_ptr);
        std::thread consumer_thread(&LogConsumer::ConsumeLog, LogConsumer(queue_ptr));
        logging(logger);
        consumer_thread.join();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }
    return 0;
}
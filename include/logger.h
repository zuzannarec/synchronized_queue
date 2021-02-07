#pragma once

#include <iostream>
#include <memory>
#include "log_queue.h"

class Logger
{
public:
    Logger(std::shared_ptr<MyLogQueue>& queue_ptr);

    void Log(std::string message);

private:
    std::shared_ptr<MyLogQueue> queue;
};

#pragma once

#include "log_queue.h"

class LogConsumer
{
public:
    LogConsumer(std::shared_ptr<MyLogQueue>& queue_ptr);

    void ConsumeLog();

private:
    std::shared_ptr<MyLogQueue> queue_ptr;
};


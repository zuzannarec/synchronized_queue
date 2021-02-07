#pragma once

#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <variant>

class MyLogQueue
{
public:
    MyLogQueue();

    void AddToQueue(std::string message);

    std::string GetFromQueue();

    int GetQueueLen();

    std::mutex m;
    std::condition_variable cv_full_queue;
    std::condition_variable cv_empty_queue;


private:
    std::queue<std::string> q;
    size_t max_queue_len = 10;
};

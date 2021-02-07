#include <exception>
#include <variant>
#include "log_queue.h"

MyLogQueue::MyLogQueue()
{
    std::cout << "Queue created!" << std::endl;
}
 
void MyLogQueue:: AddToQueue(std::string message)
{
    std::unique_lock<std::mutex> lock(this->m);
    auto queue_size = this->q.size();
    std::cout << "Queue size: " << queue_size << std::endl;
    if (queue_size >= this->max_queue_len)
    {
        this->cv_full_queue.wait(lock, [this]{ return this->q.size() < this->max_queue_len; });
    }
    this->q.push(message);
    std::cout << "Message added to queue: " << message << std::endl;
    if (this->q.size() == 1)
    {
        this->cv_empty_queue.notify_one();
    }
}

std::string MyLogQueue::GetFromQueue()
{
    std::unique_lock<std::mutex> lock(this->m);
    if (this->q.empty())
    {
        this->cv_empty_queue.wait(lock, [this]{ return !this->q.empty(); });
    }
    std::string message = this->q.front();
    this->q.pop();
    if (this->q.size() == this->max_queue_len - 1)
    {
        this->cv_full_queue.notify_one();
    }
    return message;
}


int MyLogQueue::GetQueueLen()
{
    return (this->q).size();
}

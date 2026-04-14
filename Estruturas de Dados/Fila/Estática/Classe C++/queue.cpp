#include "queue.hpp"

bool Queue::is_empty(){
    return this->n == 0;
}

bool Queue::is_full(){
    return this->n == SIZE;
}

bool Queue::enqueue(int x){
    if(this->is_full())return false;

    this->n++;
    this->e = (this->e + 1) % SIZE;
    this->V[this->e] = x;

    return true;
}

bool Queue::dequeue(int& x){
    if(this->is_empty())return false;

    this->n--;
    x = this->V[this->s];
    this->s = (this->s + 1) % SIZE;

    return true;
}
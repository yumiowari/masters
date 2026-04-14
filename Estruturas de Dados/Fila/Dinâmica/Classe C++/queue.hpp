#ifndef QUEUE_HPP
#define QUEUE_HPP

class Node{
    private:
        Node* next;
        int value;

    public:
        Node() {
            this->value = 0;
            this->next = nullptr;
        }

        Node(int v) : value(v) {
            this->next = nullptr;
        }

        void set_value(int v){ this->value = v; }
        int get_value() const{ return this->value; }
        void set_next(Node* n){ this->next = n; }
        Node* get_next(){ return this->next; }
};

class Queue{
    private:
        Node* front;
        Node* back;

    public:
        Queue() {
            this->front = nullptr;
            this->back = nullptr;
        }

        ~Queue() {
            int x;

            while(this->dequeue(x));
        }

        bool is_empty();
        bool enqueue(int);
        bool dequeue(int&);
};

#endif // QUEUE_HPP
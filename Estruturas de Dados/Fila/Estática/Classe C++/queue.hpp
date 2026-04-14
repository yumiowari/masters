#ifndef QUEUE_HPP
#define QUEUE_HPP

#define SIZE 10

class Queue{
    private:
        int V[SIZE];

        int s; // start index
        int e; // end index

        int n; // nº de elementos na fila

    public:
        Queue(){ 
            this->s = 0;
            this->e = -1;

            this->n = 0;
        }

        bool is_empty();

        bool is_full();

        bool enqueue(int);

        bool dequeue(int&);
};

#endif // QUEUE_HPP
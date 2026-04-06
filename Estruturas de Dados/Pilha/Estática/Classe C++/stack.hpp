#ifndef STACK_HPP
#define STACK_HPP

#define SIZE 10

class Stack{
    private:
        int V[SIZE];
        int n;
    public:
        Stack() { n = 0; }

        bool is_empty();

        bool is_full();

        bool pop(int &x);

        bool push(int x);
};

#endif // STACK_HPP
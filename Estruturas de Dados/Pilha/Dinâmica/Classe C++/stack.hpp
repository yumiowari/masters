#ifndef STACK_HPP
#define STACK_HPP

class Node{
    private:
        Node* next;
        int value;

    public:
        Node(int v) : value(v) {
            this->next = nullptr;
        }

        void set_next(Node* next){
            this->next = next;
        }

        int get_value() const{
            return this->value;
        }

        Node* get_next(){
            return this->next;
        }
};

class Stack{
    private:
        Node* top;

    public:
        Stack(){
            this->top = nullptr;
        }

        ~Stack(){
            int x;

            while(pop(x));
        }

        bool push(int);

        bool pop(int&);
};

#endif // STACK_H
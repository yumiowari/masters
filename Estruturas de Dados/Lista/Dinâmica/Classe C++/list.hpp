#ifndef LIST_HPP
#define LIST_HPP

class Node{
    private:
        int value;
        Node* next;

    public:
        Node(int v) : value(v) {
            this->next = nullptr;
        }

        ~Node() {
            if(this->next != nullptr)
                delete this->next;
        }

        int get_value() const { return this->value; }
        Node* get_next() const { return this->next; }
        void set_value(int v) { this->value = v; }
        void set_next(Node* n) { this->next = n; }
};

class List{
    private:
        Node* root;
        int size;

    public:
        List() {
            this->root = nullptr;
            this->size = 0;
        }

        /*~List() {
            Node *prev = this->root;
            while(prev != nullptr){
                Node *next = prev->get_next();
                delete prev;
                prev = next;
            }
        }*/

        ~List() {
            if(this->root != nullptr)
                delete this->root;
        }

        int get_size() const { return this->size; }

        bool is_empty() const { return this->size == 0; }

        bool insert(int value);

        bool remove(int value);

        void print();
};

#endif // LIST_HPP

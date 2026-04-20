#ifndef LIST_HPP
#define LIST_HPP

#define SIZE 10

class List{
    private:
        int V[SIZE];
        int n;

    public:
        List() {
            n = 0;
        };

        int get_size(){
            return this->n;
        }

        int get_nth(int i){
            return this->V[i];
        }

        bool is_full();

        bool is_empty();

        bool insert(int x);

        bool remove(int x);
};

#endif // LIST_HPP
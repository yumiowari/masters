/*  
 *  Implementação de Lista Encadeada Simples e Dinâmica em C++ utilizando classes.
 * 
 *  Rafael Renó Corrêa, 20 de abril de 2026.
 */

#ifndef LIST_HPP
#define LIST_HPP

class Node{
    private:
        int value;
        Node* next;

    public:
        Node(int v) : value(v), next(nullptr){}

        //~Node(){
        //    delete this->next;
        //}

        int get_value() const{ return this->value; }
        Node* get_next() const{ return this->next; }

        void set_value(int v){ this->value = v; }
        void set_next(Node* n){ this->next = n; }
};

class List{
    private:
        Node* root;
        int size;

    public:
        List(){
            this->root = nullptr;
            this->size = 0;
        }

        // Método Seguro: Destrutor que percorre a lista e deleta cada nó individualmente para evitar recursão profunda.
        ~List(){
            Node *prev = this->root;
            while(prev != nullptr){
                Node *next = prev->get_next();

                delete prev;

                prev = next;
            }
        }

        // Método Recursivo: Destrutor que deleta o nó raiz, o que aciona a chamada recursiva para deletar os próximos nós.
        // Pode causar stack overflow para listas muito grandes
        //~List(){
        //    delete this->root;
        //}

        int get_size() const{ return this->size; }
        //Node* get_root() const{ return this->root; }
        //void set_size(int s){ this->size = s; }
        //void set_root(Node* r){ this->root = r; }

        bool is_empty() const{ return this->size == 0; }
        bool insert(int);
        bool remove(int);
        void print();
};

#endif // LIST_HPP

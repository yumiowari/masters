#include "list.hpp"

bool List::is_full(){
    return this->n == SIZE;
}

bool List::is_empty(){
    return this->n == 0;
}

bool List::insert(int x){
    if(this->is_full())return false;

    if(this->is_empty()){
    // 1º caso: lista vazia
        this->V[0] = x;
        this->n++;

        return true;
    }

    // 2º caso: lista preenchida

        // encontra o índice do primeiro elemento maior que x
    int i = 0; while(i < this->n && this->V[i] < x)i++;

        // desloca os elementos a partir do índice i para a direita
    for(int j = this->n; j > i; j--)
        this->V[j] = this->V[j-1];

    this->V[i] = x;
    this->n++;

    return true;
}

bool List::remove(int x){
    if(this->is_empty())return false;

    // encontra a posição do elemento x
    int i = 0; while(i < this->n && this->V[i] != x)i++;

    if(i == this->n)return false; // não encontrou o elemento

    // desloca os elementos a partir do índice i para a esquerda
    for(int j = i; j < this->n - 1; j++)
        this->V[j] = this->V[j+1];

    this->n--;

    return true;
}
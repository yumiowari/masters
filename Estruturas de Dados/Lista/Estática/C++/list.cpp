#include "list.hpp"

void _start_list(list_t &L){
    L.n = 0;
}

bool _is_full(list_t L){
    return L.n == SIZE;
}

bool _is_empty(list_t L){
    return L.n == 0;
}

bool _insert(list_t &L, int x){
    if(_is_full(L))return false;

    if(_is_empty(L)){
    // 1º caso: lista vazia
        L.V[0] = x;
        L.n++;

        return true;
    }

    // 2º caso: lista preenchida

        // encontra o índice do primeiro elemento maior que x
    int i = 0; while(i < L.n && L.V[i] < x)i++;

        // desloca os elementos a partir do índice i para a direita
    for(int j = L.n; j > i; j--)
        L.V[j] = L.V[j-1];

    L.V[i] = x;
    L.n++;

    return true;
}

bool _remove(list_t &L, int x){
    if(_is_empty(L))return false;

    // encontra a posição do elemento x
    int i = 0; while(i < L.n && L.V[i] != x)i++;

    if(i == L.n)return false; // não encontrou o elemento

    // desloca os elementos a partir do índice i para a esquerda
    for(int j = i; j < L.n - 1; j++)
        L.V[j] = L.V[j+1];

    L.n--;

    return true;
}
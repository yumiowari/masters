# Tabela Hash

## Sumário

- [Definição](#definição)
    - [Dicionário de Dados](#dicionário-de-dados-e-tabelas-hash)
    - [Tabelas de Acesso Direto](#tabelas-de-acesso-direto)
    - [Tabelas _Hash_](#tabelas-hash)
        - [Função de _Hashing_](#função-de-hashing)
        - [_Hashing_ por Divisão](#hashing-por-divisão)
        - [Encadeamento](#encadeamento)
    - [Representação Visual](#representação-visual)
- [Repositório](#repositório)
    - [Organização](#organização)
    - [Compilação](#compilação)


## Definição

### Dicionário de Dados e Tabelas _Hash_

Assim como listas, filas e pilhas, tabelas _hash_ presentam um conjunto dinâmico de dados.

Suportam operações de inserção, remoção e busca. Com complexidade temporal média _O(1)_ para busca.

Tabelas _hash_ podem ser confundidas com Dicionários de Dados.

Em Python, por exemplo:

```
    dictionary = {
        'a' = 1,
        'b' = 9,
        'c' = 'nebraska',
        'd' = True
    }

    # insert
    dictionary['e'] = False

    # delete
    del dictionary['a']

    # search
    print(dictionary['c'])
```

Dicionários representam uma forma genérica de mapear chaves e valores.

Tabelas _hash_ são um tipo de implementação de dicionário utilizando uma função de _hashing_.

### Tabelas de Acesso Direto

O vetor (ou _array_) da linguagem C é uma tabela de acesso direto, onde há um conjunto universo _U_ de chaves: _U = {0, 1, 2, ..., 8, 9}_ e um conjunto _K_ de chaves utilizadas: _K = {4, 5, 6}_, ou seja, preenchidas com valores.

| Chave | Valor |
| :---: | :---: |
| 0 | 0 |
| 1 | 0 |
| 2 | 0 |
| ... | ... |
| 8 | 0 |
| 9 | 0 |
> Tabela 1: _Array_ com 10 elementos preenchidos com zero.

No _array_, as operações de inserção, remoção e busca ocorrem com complexidade temporal _O(1)_.

Entretanto, a representação dos valores está limitada ao tamanho do vetor: Um vetor com 10 chaves só pode armazenar 10 valores.

### Tabelas _Hash_

Na Tabela Hash, o conjunto universo _U_ de chaves também é limitado e é exatamente igual ao conjunto _K_ de chaves utilizadas, com complexidade espacial _O(K)_.

#### Função de _Hashing_

A função de _hashing_ mapeia as chaves à uma posição na tabela que armazena a informação (valor).

Para manter a busca o mais eficiente possível, a função de _hashing_ deve:
- Maximizar a aleatoriedade; e
- Produzir o mínimo possível de colisões.

Podem ser baseadas em
- Divisão
- Multiplicação
- _Hashing_ universal
- _Hashing_ dinâmico perfeito
- _Hashing_ estático perfeito

#### Hashing por Divisão

```
    #define SIZE 10
    
    int h(int k){
        return k % SIZE;
    }
```

_h(k) = k mod m_

_h(k) = k mod 10_

_h(50) = 10 mod 10 = 0_

Como o universo de chaves é limitado, é possível que a função de _hashing_ mapeie dois valores para a mesma chave, resultando em colisão.

Para resolver as colisões, é feito encadeamento dos valores na mesma chave.

#### Encadeamento

Utiliza-se listas encadeadas: Os valores nas chaves da tabela passam a atuar como um subconjunto de valores.

### Representação Visual

| Chave | Valor |
| :---: | :---: |
| 0 | {10, 20, 30} |
| 1 | 1 |
| 2 | 2 |
| 3 | 3 |
| ... | ... |
| 8 | |
| 9 | |
> Tabela 2: Tabela _hash_ com valores 1, 2, 3, 10, 20 e 30.

## Repositório

### Organização

Este repositório está organizado em três pastas com as respectivas implementações de Tabela _Hash_ em C e C++, bem como em classes C++.

### Compilação

Cada pasta possui um _bash script_ `compile.sh` com as instruções de compilação para cada implementação.

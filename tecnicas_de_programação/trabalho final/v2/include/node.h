/********************************************************
 * node.h - Trabalho - �rvore B                         *
 *                                                      *
 * Alunos: Beatriz Rodrigues de Oliveira Paiva          *
 *         RA: 0040300                                  *
 *                                                      *
 ********************************************************/

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>

using namespace std;

template <class T, const unsigned int MIN_DEGREE>
class mbtree;  // Declara��o antecipada da classe mbtree

template <class T, const unsigned int MIN_DEGREE>
class node {
public:
    node();
    virtual ~node();
    bool isLeaf() const;
    unsigned int size() const;
    void resize(unsigned int s);
    void setKey(T k, unsigned int i);
    void insertKey(T k);
    unsigned int hasKey(T k);
    void removeKey(unsigned int i);
    T getKey(unsigned int i) const;
    void setChild(node<T, MIN_DEGREE>* c, unsigned int i);
    void insertChild(int pos, node<T, MIN_DEGREE>* child);
    node<T, MIN_DEGREE>* getChild(unsigned int i);
    void splitChild(node<T, MIN_DEGREE> *x, int i);
    void mergeChildren(unsigned int i);
    void rotateKeys(unsigned int i);

    static const unsigned int MAX_KEYS = 2 * MIN_DEGREE - 1;
    static const unsigned int MIN_KEYS = MIN_DEGREE - 1;
    static const unsigned int NOT_FOUND = -1;

    friend class mbtree<T, MIN_DEGREE>;

protected:
    vector<T> keys;
    vector<node<T, MIN_DEGREE>*> children;
    bool leaf;
    unsigned int n;
};

template <class T, const unsigned int MIN_DEGREE>
node<T, MIN_DEGREE>::node() : leaf(true), n(0) {
    keys.resize(MAX_KEYS + 1); // +1 to handle temporary overflow during splitting
    children.resize(MAX_KEYS + 2); // +2 to handle children for internal nodes
}

template <class T, const unsigned int MIN_DEGREE>
node<T, MIN_DEGREE>::~node() {
    for (unsigned int i = 0; i < n + 1; ++i) {
        delete children[i];
    }

    // TODO: Implement any other cleanup logic for dynamically allocated members

    // Clear vectors to release memory
    keys.clear();
    children.clear();
}

template <class T, const unsigned int MIN_DEGREE>
bool node<T, MIN_DEGREE>::isLeaf() const {
    return leaf;
}

template <class T, const unsigned int MIN_DEGREE>
unsigned int node<T, MIN_DEGREE>::size() const {
    return n;
}

template <class T, const unsigned int MIN_DEGREE>
void node<T, MIN_DEGREE>::resize(unsigned int s) {
    if (s > keys.size()) {
        keys.resize(s);
    }

    if (!leaf && s + 1 > children.size()) {
        children.resize(s + 1);
    }
}

template <class T, const unsigned int MIN_DEGREE>
void node<T, MIN_DEGREE>::setKey(T k, unsigned int i) {
    if (i < keys.size()) {
        keys[i] = k;
    } else {
        // Tratar �ndice inv�lido
        throw std::out_of_range("Invalid index in setKey");
    }
}

template <class T, const unsigned int MIN_DEGREE>
void node<T, MIN_DEGREE>::insertKey(T k) {
    if (n < MAX_KEYS) {
        // O n� ainda tem espa�o para a chave
        unsigned int i = n;

        // Encontrar a posi��o correta para a nova chave
        while (i > 0 && k < keys[i - 1]) {
            keys[i] = keys[i - 1];
            --i;
        }

        // Inserir a nova chave na posi��o correta
        keys[i] = k;
        ++n;
    } else {
        // O n� est� cheio, n�o pode acomodar mais chaves
        throw std::overflow_error("Node is full");
    }
}

template <class T, const unsigned int MIN_DEGREE>
unsigned int node<T, MIN_DEGREE>::hasKey(T k) {
    for (unsigned int i = 0; i < n; ++i) {
        if (k == keys[i]) {
            return i;  // Chave encontrada, retorna o �ndice
        }
    }

    return NOT_FOUND;  // Chave n�o encontrada
}

template <class T, const unsigned int MIN_DEGREE>
void node<T, MIN_DEGREE>::removeKey(unsigned int i) {
    if (i < n) {
        // Deslocar as chaves � esquerda para cobrir o espa�o da chave removida
        for (unsigned int j = i; j < n - 1; ++j) {
            keys[j] = keys[j + 1];
        }

        // Decrementar o n�mero de chaves no n�
        --n;
    } else {
        // �ndice inv�lido
        throw std::out_of_range("Invalid index in removeKey");
    }
}

template <class T, const unsigned int MIN_DEGREE>
T node<T, MIN_DEGREE>::getKey(unsigned int i) const {
    if (i < n) {
        return keys[i];
    } else {
        // �ndice inv�lido
        throw std::out_of_range("Invalid index in getKey");
    }
}

template <class T, const unsigned int MIN_DEGREE>
void node<T, MIN_DEGREE>::setChild(node<T, MIN_DEGREE>* c, unsigned int i) {
    if (!leaf && i <= n) {
        children[i] = c;
    } else {
        // �ndice inv�lido ou tentativa de definir um filho em um n� folha
        throw std::out_of_range("Invalid index in setChild");
    }
}

template <class T, const unsigned int MIN_DEGREE>
void node<T, MIN_DEGREE>::insertChild(int pos, node<T, MIN_DEGREE>* child) {
    if (!leaf && n + 1 <= MAX_KEYS + 1) {
        // O n� n�o � uma folha e tem espa�o para mais um filho
        children.insert(children.begin() + pos, child);
        ++n;
    } else {
        // N� � uma folha ou n�o h� espa�o para mais um filho
        throw std::overflow_error("Node cannot accommodate more children");
    }
}

template <class T, const unsigned int MIN_DEGREE>
node<T, MIN_DEGREE>* node<T, MIN_DEGREE>::getChild(unsigned int i) {
    if (!leaf && i <= n) {
        return children[i];
    } else {
        // �ndice inv�lido ou tentativa de acessar um filho em um n� folha
        throw std::out_of_range("Invalid index in getChild");
    }
}

template <class T, const unsigned int MIN_DEGREE>
void node<T, MIN_DEGREE>::splitChild(node<T, MIN_DEGREE>* x, int i) {
    node<T, MIN_DEGREE> *z = new node<T, MIN_DEGREE>();
    node<T, MIN_DEGREE> *y = x->getChild(i);

    z->leaf = y->leaf;
    z->n = MIN_DEGREE - 1;

    // Transferir as chaves de y para z
    for (int j = 0; j < MIN_DEGREE - 1; ++j) {
        z->setKey(j, y->getKey(j + MIN_DEGREE));
    }

    // Transferir os filhos, se n�o for uma folha
    if (!y->leaf) {
        for (int j = 0; j < MIN_DEGREE; ++j) {
            z->setChild(j, y->getChild(j + MIN_DEGREE));
        }
    }

    // Atualizar o n�mero de chaves em y
    y->n = MIN_DEGREE - 1;

    // Abrir espa�o para o novo filho em x
    for (int j = x->size(); j > i; --j) {
        x->setChild(j + 1, x->getChild(j));
    }

    // Adicionar o novo filho z a x
    x->setChild(i + 1, z);

    // Mover a chave mediana de y para x
    x->setKey(i, y->getKey(MIN_DEGREE - 1));

    // Atualizar o n�mero de chaves em x
    x->n = x->size() + 1;

    // Persistir as mudan�as em disco
    DISK_WRITE(y);
    DISK_WRITE(z);
    DISK_WRITE(x);
}

template <class T, const unsigned int MIN_DEGREE>
void node<T, MIN_DEGREE>::mergeChildren(unsigned int i) {
    if (!leaf && i < n) {
        node<T, MIN_DEGREE>* leftChild = children[i];
        node<T, MIN_DEGREE>* rightChild = children[i + 1];

        // Mova a chave do n� pai para o n� da esquerda
        leftChild->keys[leftChild->n] = keys[i];

        // Mova as chaves do n� da direita para o n� da esquerda
        for (unsigned int j = 0; j < rightChild->n; ++j) {
            leftChild->keys[leftChild->n + 1 + j] = rightChild->keys[j];
        }

        // Mova os filhos do n� da direita para o n� da esquerda
        if (!rightChild->isLeaf()) {
            for (unsigned int j = 0; j <= rightChild->n; ++j) {
                leftChild->children[leftChild->n + 1 + j] = rightChild->children[j];
            }
        }

        // Atualize o n�mero de chaves no n� da esquerda
        leftChild->n += 1 + rightChild->n;

        // Remova a chave do n� pai e o ponteiro para o n� da direita
        removeKey(i);
        for (unsigned int j = i; j < n - 1; ++j) {
            children[j + 1] = children[j + 2];
        }

        // Deleta o n� da direita
        delete rightChild;
        rightChild = nullptr;
    } else {
        // �ndice inv�lido ou tentativa de mesclar um n� folha
        throw std::out_of_range("Invalid index in mergeChildren");
    }
}

template <class T, const unsigned int MIN_DEGREE>
void node<T, MIN_DEGREE>::rotateKeys(unsigned int i) {
    if (!leaf && i < n && i + 1 < n) {
        node<T, MIN_DEGREE>* leftChild = children[i];
        node<T, MIN_DEGREE>* rightChild = children[i + 1];

        // Mova a chave do n� pai para o n� da esquerda
        leftChild->keys[leftChild->n] = keys[i];

        // Mova a chave do n� da direita para o n� pai
        keys[i] = rightChild->keys[0];

        // Desloque as chaves no n� da direita
        for (unsigned int j = 0; j < rightChild->n - 1; ++j) {
            rightChild->keys[j] = rightChild->keys[j + 1];
        }

        // Se n�o for um n� folha, mova o filho do n� da direita para o n� da esquerda
        if (!rightChild->isLeaf()) {
            leftChild->children[leftChild->n + 1] = rightChild->children[0];

            // Desloque os filhos no n� da direita
            for (unsigned int j = 0; j < rightChild->n; ++j) {
                rightChild->children[j] = rightChild->children[j + 1];
            }
        }

        // Atualize o n�mero de chaves nos n�s
        ++leftChild->n;
        --rightChild->n;
    } else {
        // �ndice inv�lido ou tentativa de rotacionar um n� folha
        throw std::out_of_range("Invalid index in rotateKeys");
    }
}

#endif // NODE_H

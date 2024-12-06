/********************************************************
 * mbtree.h - Trabalho - Árvore B                       *
 *                                                      *
 * Alunos: Beatriz Rodrigues de Oliveira Paiva          *
 *         RA: 0040300                                  *
 *                                                      *
 ********************************************************/

// mbtree.h

#ifndef MBTREE_H
#define MBTREE_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "node.h"
using namespace std;

template <class T, const unsigned int MIN_DEGREE>
class mbtree {
public:
    mbtree();
    virtual ~mbtree();
    void insert(T k);
    void remove(T k);
    int search(T k);
    void print();
    void splitChild(node<T, MIN_DEGREE>* x, int i) {

    static const unsigned int MAX_KEYS = 2 * MIN_DEGREE - 1;
    static const unsigned int MIN_KEYS = MIN_DEGREE - 1;

protected:
    void insertNonFull(node<T, MIN_DEGREE>* x, T k);
    void removeAux(node<T, MIN_DEGREE>* x, T k);
    T findPredecessor(node<T, MIN_DEGREE>* x);
    T findSuccessor(node<T, MIN_DEGREE>* x);
    void printAux(node<T, MIN_DEGREE>* x, std::vector<std::string>& v, unsigned int lvl);
    int searchAux(node<T, MIN_DEGREE>* x, T k);

    node<T, MIN_DEGREE>* root;
};

template <class T, const unsigned int MIN_DEGREE>
mbtree<T, MIN_DEGREE>::mbtree() : root(nullptr) {
   if (!root)
      root = new node<T, MIN_DEGREE>();
}

template <class T, const unsigned int MIN_DEGREE>
mbtree<T, MIN_DEGREE>::~mbtree() {
   delete root;
   root = NULL;
}

template <class T, const unsigned int MIN_DEGREE>
void mbtree<T, MIN_DEGREE>::insert(T k) {
    node<T, MIN_DEGREE> *r = root;

    if (r->size() == node<T, MIN_DEGREE>::MAX_KEYS) {
        node<T, MIN_DEGREE> *s = new node<T, MIN_DEGREE>();
        root = s;

        s->leaf = false;
        s->insertChild(0, r);
        splitChild(s, 0);
        insertNonFull(s, k);
    } else {
        insertNonFull(r, k);
    }
}

template <class T, const unsigned int MIN_DEGREE>
void mbtree<T, MIN_DEGREE>::remove(T k) {
   node<T, MIN_DEGREE>* x = root;

   removeAux(x, k);
}

template <class T, const unsigned int MIN_DEGREE>
int mbtree<T, MIN_DEGREE>::search(T k) {
    return searchAux(root, k);
}

template <class T, const unsigned int MIN_DEGREE>
void mbtree<T, MIN_DEGREE>::print() {
    if (root != nullptr) {
        std::vector<std::string> output;
        printAux(root, output, 0);

        for (const auto& line : output) {
            std::cout << line << std::endl;
        }
    } else {
        std::cout << "Empty tree" << std::endl;
    }
}

template <class T, const unsigned int MIN_DEGREE>
void mbtree<T, MIN_DEGREE>::insertNonFull(node<T, MIN_DEGREE>* x, T k) {
    int i = x->n;

    if (x->leaf) {
        while (i >= 1 && k < x->getKey(i - 1)) {
            x->setKey(i, x->getKey(i - 1));
            i--;
        }
        x->setKey(i, k);
        x->n++;
        // Se o nó for alterado, você pode ter lógica adicional para persistir as mudanças no disco.
    } else {
        while (i >= 1 && k < x->getKey(i - 1)) {
            i--;
        }

        i++;  // Incremento para considerar o próximo filho

        // Se assumirmos que o filho já está na memória principal, não precisamos de DISK_READ.

        if (x->getChild(i - 1)->n == 2 * MIN_DEGREE - 1) {
            splitChild(x, i - 1);

            if (k > x->getKey(i - 1)) {
                i++;
            }
        }

        insertNonFull(x->getChild(i - 1), k);
    }
}

template <class T, const unsigned int MIN_DEGREE>
void mbtree<T, MIN_DEGREE>::removeAux(node<T, MIN_DEGREE>* x, T k) {
    unsigned int pos = x->hasKey(k);
    T aux;

    if (x->isLeaf()) { // Case 1
        if (pos != node<T, MIN_DEGREE>::NOT_FOUND) {
            x->removeKey(pos);
        }
    } else {
        if (pos != node<T, MIN_DEGREE>::NOT_FOUND && !x->isLeaf()) { // Case 2
            if (x->getChild(pos)->size() >= MIN_DEGREE) { // Case 2a
                aux = findPredecessor(x->getChild(pos));
                removeAux(x->getChild(pos), aux);
                x->setKey(aux, pos);
            } else if (x->getChild(pos + 1)->size() >= MIN_DEGREE) { // Case 2b
                aux = findSuccessor(x->getChild(pos + 1));
                removeAux(x->getChild(pos + 1), aux);
                x->setKey(aux, pos);
            } else { // Case 2c
                x->mergeChildren(pos);
                if (x == root && x->size() == 0) {
                    root = x->getChild(pos);
                    delete x;
                    removeAux(root, k);
                } else {
                    removeAux(x->getChild(pos), k);
                }
            }
        } else { // Case 3
            pos = 0;

            while (pos < x->size() && k > x->getKey(pos)) {
                pos++;
            }

            if (x->getChild(pos)->size() == MIN_DEGREE - 1) { // Case 3a
                if (pos > 0 && x->getChild(pos - 1)->size() >= MIN_DEGREE) {
                    x->rotateKeys(pos - 1);
                } else if (pos < x->size() && x->getChild(pos + 1)->size() >= MIN_DEGREE) {
                    x->rotateKeys(pos);
                } else { // Case 3b
                    if (pos == x->size()) {
                        x->mergeChildren(pos - 1);
                    } else {
                        x->mergeChildren(pos);
                    }

                    if (x == root && x->size() == 0) {
                        root = x->getChild(0);
                        delete x;
                        x = root;
                        pos = 0;

                        while (pos < x->size() && k > x->getKey(pos)) {
                            pos++;
                        }
                    }
                }
            }

            removeAux(x->getChild(pos), k);
        }
    }
}

template <class T, const unsigned int MIN_DEGREE>
T mbtree<T, MIN_DEGREE>::findPredecessor(node<T, MIN_DEGREE>* x) {
    while (!x->isLeaf()) {
        x = x->getChild(x->size());
    }
    return x->getKey(x->size() - 1);
}

template <class T, const unsigned int MIN_DEGREE>
T mbtree<T, MIN_DEGREE>::findSuccessor(node<T, MIN_DEGREE>* x) {
    while (!x->isLeaf()) {
        x = x->getChild(0);
    }
    return x->getKey(0);
}

template <class T, const unsigned int MIN_DEGREE>
void mbtree<T, MIN_DEGREE>::printAux(node<T, MIN_DEGREE>* x, std::vector<std::string>& v, unsigned int lvl) {
    if (x != nullptr) {
        for (unsigned int i = 0; i < x->size(); ++i) {
            if (!x->isLeaf()) {
                printAux(x->getChild(i), v, lvl + 1);
            }

            std::stringstream ss;
            ss << "(" << lvl << "," << i << ") " << x->getKey(i);
            v.push_back(ss.str());

            if (!x->isLeaf() && i == x->size() - 1) {
                printAux(x->getChild(i + 1), v, lvl + 1);
            }
        }
    }
}

template <class T, const unsigned int MIN_DEGREE>
int mbtree<T, MIN_DEGREE>::searchAux(node<T, MIN_DEGREE>* x, T k) {
    unsigned int i = 0;

    while (i < x->size() && k > x->getKey(i)) {
        i++;
    }

    if (i < x->size() && k == x->getKey(i)) {
        return i;
    } else {
        if (x->isLeaf()) {
            return -1;
        } else {
            // Se assumirmos que o filho já está na memória principal, não precisamos de DISK_READ.
            return searchAux(x->getChild(i), k);
        }
    }
}

#endif // MBTREE_H

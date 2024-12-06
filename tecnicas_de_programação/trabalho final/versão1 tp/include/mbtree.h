/********************************************************
 * mbtree.h - In-Memory B-Tree Class File               *
 *                                                      *
 * Author:  Dias, Samuel Pereira. 2021                  *
 *                                                      *
 * Purpose:  Demonstration of B-Tree algorithms.        *
 *                                                      *
 * Restrictions: This code can only be used in classes  *
 *    of the author's Programming Techniques (Técnicas  *
 *    de Programação/IFMG/Campus Bambuí) course, being  *
 *    forbidden to copy and modify its content.         *
 *                                                      *
 * Warning: There may be intentional bugs in the code.  *
 ********************************************************/

#ifndef MBTREE_H
#define MBTREE_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "node.h"

template <const unsigned int MIN_DEGREE>
class mbtree {
public:
    mbtree();
    virtual ~mbtree();
    void insert(char k);
    void remove(char k);
    int search(node<char, MIN_DEGREE>* x, char k);
    void print();

protected:
    void insertNonFull(node<char, MIN_DEGREE>* x, char k);
    void removeAux(node<char, MIN_DEGREE>* x, char k);
    char findPredecessor(node<char, MIN_DEGREE>* x);
    char findSuccessor(node<char, MIN_DEGREE>* x);
    void printAux(node<char, MIN_DEGREE>* x, vector<string>& v, unsigned int lvl);
    int searchAux(node<char, MIN_DEGREE>* x, char k);
    node<char, MIN_DEGREE>* root = nullptr;
};

template <const unsigned int MIN_DEGREE>
mbtree<MIN_DEGREE>::mbtree() {
    if (!root)
        root = new node<char, MIN_DEGREE>();
}

template <const unsigned int MIN_DEGREE>
mbtree<MIN_DEGREE>::~mbtree() {
    delete root;
    root = nullptr;
}

template <const unsigned int MIN_DEGREE>
void mbtree<MIN_DEGREE>::insert(char k) {
    node<char, MIN_DEGREE>* r = root, *s = nullptr;

    if (r->size() == node<char, MIN_DEGREE>::MAX) {
        s = new node<char, MIN_DEGREE>();
        root = s;

        s->insertChild(r);
        s->splitChild(0);
        insertNonFull(s, k);
    } else {
        insertNonFull(r, k);
    }
}

template <const unsigned int MIN_DEGREE>
void mbtree<MIN_DEGREE>::remove(char k) {
    node<char, MIN_DEGREE>* x = root;

    removeAux(x, k);
}

template <const unsigned int MIN_DEGREE>
int mbtree<MIN_DEGREE>::search(node<char, MIN_DEGREE>* x, char k) {
    x = root;
    return searchAux(x, k);
}

template <const unsigned int MIN_DEGREE>
void mbtree<MIN_DEGREE>::print() {
    int lvl = 0;
    vector<string> levels(1);
    printAux(root, levels, lvl);

    for (string s : levels) {
        cout << s << endl;
    }
}

template <const unsigned int MIN_DEGREE>
void mbtree<MIN_DEGREE>::insertNonFull(node<char, MIN_DEGREE>* x, char k) {
    int i = x->size() - 1;
    node<char, MIN_DEGREE>* y = nullptr;

    if (x->isLeaf()) {
        x->insertKey(k);
    } else {
        while (i >= 0 && k < x->getKey(i)) {
            i--;
        }

        i++;
        y = x->getChild(i);

        if (y->size() == node<char, MIN_DEGREE>::MAX) {
            x->splitChild(i);

            if (k > x->getKey(i)) {
                i++;
            }
        }

        insertNonFull(x->getChild(i), k);
    }
}

template <const unsigned int MIN_DEGREE>
void mbtree<MIN_DEGREE>::removeAux(node<char, MIN_DEGREE>* x, char k) {
    unsigned int pos = x->hasKey(k);
    char aux;

    if (x->isLeaf()) { // Case 1
        if (pos != node<char, MIN_DEGREE>::NOT_FOUND) {
            x->removeKey(pos);
        }
    } else {
        if (pos != node<char, MIN_DEGREE>::NOT_FOUND && !x->isLeaf()) { // Case 2
            if (x->getChild(pos)->size() > node<char, MIN_DEGREE>::MIN) { // Case 2a
                aux = findPredecessor(x->getChild(pos));
                removeAux(x->getChild(pos), aux);
                x->setKey(aux, pos);
            } else {
                if (x->getChild(pos + 1)->size() > node<char, MIN_DEGREE>::MIN) { // Case 2b
                    aux = findSuccessor(x->getChild(pos + 1));
                    removeAux(x->getChild(pos + 1), aux);
                    x->setKey(aux, pos);
                } else { // 2c
                    x->mergeChildren(pos);
                    if (x == root && x->size() == 0) {
                        root = x->getChild(pos);
                        delete x;
                        removeAux(root, k);
                    } else {
                        removeAux(x->getChild(pos), k);
                    }
                }
            }
        } else { // Case 3
            pos = 0;

            while (pos <= x->size() && k > x->getKey(pos)) {
                pos++;
            }

            if (x->getChild(pos)->size() == node<char, MIN_DEGREE>::MIN) { // Case 3a
                if (pos > 0 && x->getChild(pos - 1)->size() > node<char, MIN_DEGREE>::MIN) {
                    x->rotateKeys(pos - 1);
                } else {
                    if (pos < x->size() && x->getChild(pos + 1)->size() > node<char, MIN_DEGREE>::MIN) {
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

                            while (pos <= x->size() && k > x->getKey(pos)) {
                                pos++;
                            }
                        }
                    }
                }
            }

            removeAux(x->getChild(pos), k);
        }
    }
}

template <const unsigned int MIN_DEGREE>
char mbtree<MIN_DEGREE>::findPredecessor(node<char, MIN_DEGREE>* x) {
    if (x->isLeaf()) {
        return x->getKey(x->size() - 1);
    } else {
        return findPredecessor(x->getChild(x->size()));
    }
}

template <const unsigned int MIN_DEGREE>
char mbtree<MIN_DEGREE>::findSuccessor(node<char, MIN_DEGREE>* x) {
    if (x->isLeaf()) {
        return x->getKey(0);
    } else {
        return findSuccessor(x->getChild(0));
    }
}

template <const unsigned int MIN_DEGREE>
void mbtree<MIN_DEGREE>::printAux(node<char, MIN_DEGREE>* x, vector<string>& v, unsigned int lvl) {
    string aux = "[";
    unsigned int i = 0;

    if (v.size() < lvl + 1) {
        v.resize(lvl + 1);
    }

    if (!x->isLeaf()) {
        for (i = 0; i <= x->size(); i++) {
            if (x->getChild(i) != nullptr)
                printAux(x->getChild(i), v, lvl + 1);
        }
    }

    for (i = 0; i < x->size(); i++) {
        aux += x->getKey(i);
        aux += ", ";
    }

    if (aux.length() > 1) {
        aux.pop_back();
        aux.pop_back();
        aux += "] ";
    } else {
        aux += "] ";
    }

    v[lvl] += aux;
}

template <const unsigned int MIN_DEGREE>
int mbtree<MIN_DEGREE>::searchAux(node<char, MIN_DEGREE>* x, char k) {
    unsigned int i = 0;

    while (i < x->size() && k > x->getKey(i)) {
        i++;
    }

    if (i < x->size() && k == x->getKey(i)) {
        return i;
    } else {
        if (x->isLeaf()) {
            x = nullptr;
            return -1;
        } else {
            return searchAux(x->getChild(i), k);
        }
    }
}
#endif // MBTREE_H

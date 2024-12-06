#ifndef MBTREE_H
#define MBTREE_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "btree_node.h"
#include "serializable.h"

using namespace std;

template <class T, const unsigned int MIN_DEGREE>
class mbtree {
public:
    mbtree();
    virtual ~mbtree();
    void insert(T k);
    void remove(T k);
    int search(BTreeNode<T, MIN_DEGREE>* x, T k);
    void print();
    void serialize(std::ofstream& outFile) const;
    void deserialize(std::ifstream& inFile);
    BTreeNode<T, MIN_DEGREE>* getRoot() const;

protected:
    void insertNonFull(BTreeNode<T, MIN_DEGREE>* x, T k, std::ofstream& outFile);
    void removeAux(BTreeNode<T, MIN_DEGREE>* x, T k);
    T findPredecessor(BTreeNode<T, MIN_DEGREE>* x);
    T findSuccessor(BTreeNode<T, MIN_DEGREE>* x);
    void printAux(BTreeNode<T, MIN_DEGREE>* x, vector<string>& v, unsigned int lvl);
    int searchAux(BTreeNode<T, MIN_DEGREE>* x, T k);
    void deleteSubtree(BTreeNode<T, MIN_DEGREE>* x);
    BTreeNode<T, MIN_DEGREE>* root = nullptr;
};

template <class T, const unsigned int MIN_DEGREE>
mbtree<T, MIN_DEGREE>::mbtree() {
}

template <class T, const unsigned int MIN_DEGREE>
mbtree<T, MIN_DEGREE>::~mbtree() {
    if (root != nullptr) {
        deleteSubtree(root);
        root = nullptr;
    }
}

template <class T, const unsigned int MIN_DEGREE>
void mbtree<T, MIN_DEGREE>::deleteSubtree(BTreeNode<T, MIN_DEGREE>* x) {
    if (x != nullptr) {
        for (unsigned int i = 0; i < x->size() + 1; ++i) {
            deleteSubtree(x->getChild(i));
        }
        delete x;
    }
}

template <class T, const unsigned int MIN_DEGREE>
void mbtree<T, MIN_DEGREE>::insert(T k) {
    if (root == nullptr) {
        root = new BTreeNode<T, MIN_DEGREE>();
    }

    if (root->size() == 2 * MIN_DEGREE - 1) {
        BTreeNode<T, MIN_DEGREE>* s = new BTreeNode<T, MIN_DEGREE>();
        root = s;
        s->setLeaf(false);
        s->resize(0);
        s->setChild(root, 0);
        s->splitChild(0);

        // Crie um objeto std::ofstream
        std::ofstream outFile("teste.dat");

        // Chame a função insertNonFull com o parâmetro adicional outFile
        insertNonFull(s, k, outFile);

        // Não se esqueça de fechar o arquivo após o uso
        outFile.close();
    } else {
        // Crie um objeto std::ofstream
        std::ofstream outFile("teste.dat");

        // Chame a função insertNonFull com o parâmetro adicional outFile
        insertNonFull(root, k, outFile);

        outFile.close();
    }
}

template <class T, const unsigned int MIN_DEGREE>
void mbtree<T, MIN_DEGREE>::remove(T k) {
    if (root != nullptr) {
        root->removeKey(k);

        if (root->size() == 0) {
            BTreeNode<T, MIN_DEGREE>* newRoot = root->getChild(0);
            delete root;
            root = newRoot;
        }
    }
}

template <class T, const unsigned int MIN_DEGREE>
int mbtree<T, MIN_DEGREE>::search(BTreeNode<T, MIN_DEGREE>* x, T k) {
    if (x != nullptr) {
        std::ifstream inFile("teste.dat");  // Substitua pelo nome do seu arquivo
        x->readFromDisk(inFile);
        inFile.close();  // Lembre-se de fechar o arquivo depois de usar
        return searchAux(x, k);
    }
    return -1;
}

template <class T, const unsigned int MIN_DEGREE>
void mbtree<T, MIN_DEGREE>::print() {
    if (root != nullptr) {
        vector<string> result;
        printAux(root, result, 0);

        for (const string& line : result) {
            cout << line << endl;
        }
    }
}

template <class T, const unsigned int MIN_DEGREE>
void mbtree<T, MIN_DEGREE>::insertNonFull(BTreeNode<T, MIN_DEGREE>* x, T k, std::ofstream& outFile) {
    unsigned int i = x->size();

    if (x->isLeaf()) {
        while (i > 0 && k < x->getKey(i - 1)) {
            x->setKey(x->getKey(i - 1), i);
            i--;
        }

        x->setKey(k, i);
        x->resize(x->size() + 1);
        x->writeToDisk(outFile);  // Passa o outFile como argumento
    } else {
        while (i > 0 && k < x->getKey(i - 1)) {
            i--;
        }

        i++;

        BTreeNode<T, MIN_DEGREE>* child = x->getChild(i - 1);

        if (child->size() == 2 * MIN_DEGREE - 1) {
            child->splitChild(i - 1);

            if (k > x->getKey(i - 1)) {
                i++;
            }
        }

        child = x->getChild(i - 1);
        insertNonFull(child, k, outFile);  // Passa o outFile como argumento
    }
}

template <class T, const unsigned int MIN_DEGREE>
void mbtree<T, MIN_DEGREE>::removeAux(BTreeNode<T, MIN_DEGREE>* x, T k) {
    unsigned int pos = x->findKey(k);
    T aux;

    if (x->isLeaf()) {
        if (pos != BTreeNode<T, MIN_DEGREE>::NOT_FOUND) {
            x->removeKey(pos);
            x->writeToDisk();
        }
    } else {
        if (pos != BTreeNode<T, MIN_DEGREE>::NOT_FOUND && !x->isLeaf()) {
            if (x->getChild(pos)->size() > MIN_DEGREE) {
                aux = findPredecessor(x->getChild(pos));
                x->getChild(pos)->removeAux(aux);
                x->setKey(aux, pos);
                x->writeToDisk();
            } else {
                if (x->getChild(pos + 1)->size() > MIN_DEGREE) {
                    aux = findSuccessor(x->getChild(pos + 1));
                    x->getChild(pos + 1)->removeAux(aux);
                    x->setKey(aux, pos);
                    x->writeToDisk();
                } else {
                    x->mergeChildren(pos);
                    x->writeToDisk();

                    if (x == root && x->size() == 0) {
                        root = x->getChild(pos);
                        delete x;
                        root->removeAux(k);
                    } else {
                        x->getChild(pos)->removeAux(k);
                    }
                }
            }
        } else {
            pos = 0;

            while (pos < x->size() && k > x->getKey(pos)) {
                pos++;
            }

            if (x->getChild(pos)->size() == MIN_DEGREE) {
                if (pos > 0 && x->getChild(pos - 1)->size() > MIN_DEGREE) {
                    x->rotateKeys(pos - 1);
                    x->writeToDisk();
                } else {
                    if (pos < x->size() && x->getChild(pos + 1)->size() > MIN_DEGREE) {
                        x->rotateKeys(pos);
                        x->writeToDisk();
                    } else {
                        if (pos == x->size()) {
                            x->mergeChildren(pos - 1);
                        } else {
                            x->mergeChildren(pos);
                        }

                        x->writeToDisk();

                        if (x == root && x->size() == 0) {
                            root = x->getChild(0);
                            delete x;
                            root->removeAux(k);
                        } else {
                            x->getChild(pos)->removeAux(k);
                        }
                    }
                }
            } else {
                x->getChild(pos)->removeAux(k);
            }
        }
    }
}

template <class T, const unsigned int MIN_DEGREE>
T mbtree<T, MIN_DEGREE>::findPredecessor(BTreeNode<T, MIN_DEGREE>* x) {
    while (!x->isLeaf()) {
        x = x->getChild(x->size() - 1);
    }

    return x->getKey(x->size() - 1);
}

template <class T, const unsigned int MIN_DEGREE>
T mbtree<T, MIN_DEGREE>::findSuccessor(BTreeNode<T, MIN_DEGREE>* x) {
    while (!x->isLeaf()) {
        x = x->getChild(0);
    }

    return x->getKey(0);
}

template <class T, const unsigned int MIN_DEGREE>
void mbtree<T, MIN_DEGREE>::printAux(BTreeNode<T, MIN_DEGREE>* x, vector<string>& v, unsigned int lvl) {
    if (x != nullptr) {
        if (lvl >= v.size()) {
            v.resize(lvl + 1);
        }

        printAux(x->getChild(0), v, lvl + 1);

        stringstream ss;
        ss << x->getKey(0);
        v[lvl] += ss.str() + " ";

        for (unsigned int i = 1; i <= x->size(); ++i) {
            printAux(x->getChild(i), v, lvl + 1);
            if (i < x->size()) {
                stringstream ss;
                ss << x->getKey(i);
                v[lvl] += ss.str() + " ";
            }
        }
    }
}

template <class T, const unsigned int MIN_DEGREE>
int mbtree<T, MIN_DEGREE>::searchAux(BTreeNode<T, MIN_DEGREE>* x, T k) {
    unsigned int i = 0;

    while (i < x->size() && k > x->getKey(i)) {
        i++;
    }

    if (i < x->size() && k == x->getKey(i)) {
        return i;
    } else {
        if (!x->isLeaf()) {
            BTreeNode<T, MIN_DEGREE>* child = x->getChild(i);
            std::ifstream childFileStream("teste.dat");
            child->readFromDisk(childFileStream);
            return searchAux(child, k);
        }
    }

    return -1;
}

template <class T, const unsigned int MIN_DEGREE>
void mbtree<T, MIN_DEGREE>::serialize(std::ofstream& outFile) const {
    if (root != nullptr) {
        root->readFromDisk();
        root->serialize(outFile);
    }
}

template <class T, const unsigned int MIN_DEGREE>
void mbtree<T, MIN_DEGREE>::deserialize(std::ifstream& inFile) {
    if (root != nullptr) {
        root->deserialize(inFile);
        root->readFromDisk();
    }
}

template <class T, const unsigned int MIN_DEGREE>
BTreeNode<T, MIN_DEGREE>* mbtree<T, MIN_DEGREE>::getRoot() const {
    return root;
}

#endif // MBTREE_H

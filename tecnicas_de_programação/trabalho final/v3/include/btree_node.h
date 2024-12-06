#ifndef BTREE_NODE_H
#define BTREE_NODE_H

#include <iostream>
#include <vector>
#include "serializable.h"

template <class T, const unsigned int MIN_DEGREE>
class BTreeNode {
public:
    BTreeNode();
    ~BTreeNode();

    bool isLeaf() const;
    unsigned int size() const;
    void resize(unsigned int s);

    T getKey(int i) const;
    void setKey(T k, unsigned int i);
    void insertKey(T k);
    unsigned int findKey(T k) const;
    void removeKey(unsigned int i);
    void removeChild(unsigned int i);
    void setLeaf(bool isLeaf);
    void insertNonFull(T k);

    BTreeNode<T, MIN_DEGREE>* getChild(unsigned int i);
    void setChild(BTreeNode<T, MIN_DEGREE>* c, unsigned int i);
    void insertChild(BTreeNode<T, MIN_DEGREE>* c);

    void splitChild(unsigned int i);
    void mergeChildren(unsigned int i);
    void performRotation(unsigned int i);

    void writeToDisk(std::ofstream& outFile);
    void readFromDisk(std::ifstream& inFile);
    void serialize(std::ofstream& outFile) const;
    void deserialize(std::ifstream& inFile);
    size_t getNodeSize() const;

private:
    static const unsigned int NOT_FOUND = -1;
    bool isLeafNode;

    std::vector<T> keys;
    std::vector<BTreeNode<T, MIN_DEGREE>*> children;
};

template <class T, const unsigned int MIN_DEGREE>
BTreeNode<T, MIN_DEGREE>::~BTreeNode() {
    for (auto& child : children) {
        if (child != nullptr) {
            delete child;
            child = nullptr;
        }
    }
}

template <class T, const unsigned int MIN_DEGREE>
bool BTreeNode<T, MIN_DEGREE>::isLeaf() const {
    return children.empty();
}

template <class T, const unsigned int MIN_DEGREE>
unsigned int BTreeNode<T, MIN_DEGREE>::size() const {
    return keys.size();
}

template <class T, const unsigned int MIN_DEGREE>
void BTreeNode<T, MIN_DEGREE>::resize(unsigned int s) {
    if (s <= 2 * MIN_DEGREE - 1) {
        keys.resize(s);
        children.resize(s + 1);
    } else {
        throw std::out_of_range("Invalid size in resize");
    }
}

template <class T, const unsigned int MIN_DEGREE>
T BTreeNode<T, MIN_DEGREE>::getKey(int i) const {
    return keys[i];
}

template <class T, const unsigned int MIN_DEGREE>
void BTreeNode<T, MIN_DEGREE>::setKey(T k, unsigned int i) {
    keys[i] = k;
}

template <class T, const unsigned int MIN_DEGREE>
void BTreeNode<T, MIN_DEGREE>::insertKey(T k) {
    if (size() < 2 * MIN_DEGREE) {
        // O n� ainda tem espa�o para a chave
        int i = size();

        // Encontrar a posi��o correta para a nova chave
        while (i > 0 && k < keys[i - 1]) {
            keys[i] = keys[i - 1];
            --i;
        }

        // Inserir a nova chave na posi��o correta
        keys[i] = k;
        resize(size() + 1);
    } else {
        // O n� est� cheio, n�o pode acomodar mais chaves

        // Criar um novo n� para realizar a divis�o
        BTreeNode<T, MIN_DEGREE>* newNode = new BTreeNode<T, MIN_DEGREE>();

        // Chamar a fun��o de divis�o, que ajustar� os tamanhos e realizar� a inser��o
        splitChild(0);

        // Identificar em qual dos dois n�s a nova chave deve ser inserida
        if (k < keys[0]) {
            getChild(0)->insertKey(k);
        } else {
            newNode->insertKey(k);
        }
    }
}

template <class T, const unsigned int MIN_DEGREE>
unsigned int BTreeNode<T, MIN_DEGREE>::findKey(T k) const {
    unsigned int i = 0;

    // Encontrar a posi��o correta para a chave
    while (i < size() && k > keys[i]) {
        ++i;
    }

    // Verificar se a chave foi encontrada
    if (i < size() && k == keys[i]) {
        return i;  // Chave encontrada, retorna o �ndice
    }

    return NOT_FOUND;  // Chave n�o encontrada
}

template <class T, const unsigned int MIN_DEGREE>
void BTreeNode<T, MIN_DEGREE>::removeKey(unsigned int i) {
    if (i < size()) {
        // Deslocar as chaves � esquerda para cobrir o espa�o da chave removida
        for (unsigned int j = i; j < size() - 1; ++j) {
            keys[j] = keys[j + 1];
        }

        // Decrementar o n�mero de chaves no n�
        resize(size() - 1);
    } else {
        // �ndice inv�lido
        throw std::out_of_range("Invalid index in removeKey");
    }
}

template <class T, const unsigned int MIN_DEGREE>
void BTreeNode<T, MIN_DEGREE>::removeChild(unsigned int i) {
    if (i < children.size()) {
        delete children[i];
        children.erase(children.begin() + i);
    } else {
        // �ndice inv�lido
        throw std::out_of_range("Invalid index in removeChild");
    }
}

template <class T, const unsigned int MIN_DEGREE>
void BTreeNode<T, MIN_DEGREE>::setLeaf(bool isLeaf) {
    isLeafNode = isLeaf;
}

template <class T, const unsigned int MIN_DEGREE>
BTreeNode<T, MIN_DEGREE>* BTreeNode<T, MIN_DEGREE>::getChild(unsigned int i) {
    if (i < size()) {
        return children[i];
    } else {
        // �ndice inv�lido ou tentativa de acessar um filho inexistente
        throw std::out_of_range("Invalid index in getChild");
    }
}

template <class T, const unsigned int MIN_DEGREE>
void BTreeNode<T, MIN_DEGREE>::setChild(BTreeNode<T, MIN_DEGREE>* c, unsigned int i) {
    if (i < size()) {
        children[i] = c;
    } else {
        // �ndice inv�lido ou tentativa de definir um filho em uma posi��o inexistente
        throw std::out_of_range("Invalid index in setChild");
    }
}

template <class T, const unsigned int MIN_DEGREE>
void BTreeNode<T, MIN_DEGREE>::insertChild(BTreeNode<T, MIN_DEGREE>* c) {
    if (children.size() + 1 <= 2 * MIN_DEGREE) {
        // O n� n�o est� cheio e pode acomodar mais um filho
        children.push_back(c);
    } else {
        // N� est� cheio, n�o pode acomodar mais filhos
        throw std::overflow_error("Node cannot accommodate more children");
    }
}

template <class T, const unsigned int MIN_DEGREE>
void BTreeNode<T, MIN_DEGREE>::splitChild(unsigned int i) {
    // Verifica se o �ndice � v�lido
    if (i < children.size() && children[i]->size() == 2 * MIN_DEGREE - 1) {
        // Cria um novo n� que ser� o n� direito ap�s a divis�o
        BTreeNode<T, MIN_DEGREE>* z = new BTreeNode<T, MIN_DEGREE>();

        // Obt�m o n� que ser� dividido
        BTreeNode<T, MIN_DEGREE>* y = children[i];

        // Configura o novo n� como n�o folha se o n� dividido n�o for folha
        z->setLeaf(y->isLeaf());

        // Configura o n�mero de chaves no novo n�
        z->resize(MIN_DEGREE - 1);

        // Move as chaves para o novo n�
        for (unsigned int j = 0; j < MIN_DEGREE - 1; ++j) {
            z->setKey(y->getKey(j + MIN_DEGREE), j);
        }

        // Move os filhos para o novo n�, se n�o for folha
        if (!y->isLeaf()) {
            for (unsigned int j = 0; j < MIN_DEGREE; ++j) {
                z->setChild(y->getChild(j + MIN_DEGREE), j);
            }
        }

        // Reduz o n�mero de chaves no n� esquerdo
        y->resize(MIN_DEGREE - 1);

        // Move os filhos � direita de i em uma posi��o para acomodar o novo n�
        for (unsigned int j = size(); j > i; --j) {
            setChild(getChild(j - 1), j);
        }

        // Insere o novo n� como filho ap�s o n� esquerdo
        setChild(z, i + 1);

        // Move a chave do meio do n� esquerdo para o n� atual
        insertKey(y->getKey(MIN_DEGREE - 1));

        // Incrementa o n�mero de chaves no n� atual
        resize(size() + 1);

        // Supondo que DISK_WRITE realiza a opera��o de escrita no disco
        // DISK_WRITE(y);
        // DISK_WRITE(z);
        // DISK_WRITE(this);
    } else {
        // �ndice inv�lido ou filho n�o est� cheio
        throw std::out_of_range("Invalid index or child is not full in splitChild");
    }
}

template <class T, const unsigned int MIN_DEGREE>
void BTreeNode<T, MIN_DEGREE>::mergeChildren(unsigned int i) {
    if (i < children.size() - 1) {
        BTreeNode<T, MIN_DEGREE>* leftChild = children[i];
        BTreeNode<T, MIN_DEGREE>* rightChild = children[i + 1];

        leftChild->insertKey(keys[i]);

        for (unsigned int j = 0; j < rightChild->size(); ++j) {
            leftChild->insertKey(rightChild->getKey(j));
        }

        if (!rightChild->isLeaf()) {
            for (unsigned int j = 0; j <= rightChild->size(); ++j) {
                leftChild->insertChild(rightChild->getChild(j));
            }
        }

        removeKey(i);
        removeChild(i + 1);

        delete rightChild;
        rightChild = nullptr;
    } else {
        throw std::out_of_range("Invalid index in mergeChildren");
    }
}

template <class T, const unsigned int MIN_DEGREE>
void BTreeNode<T, MIN_DEGREE>::performRotation(unsigned int i) {
    if (i < children.size() - 1) {
        BTreeNode<T, MIN_DEGREE>* leftChild = children[i];
        BTreeNode<T, MIN_DEGREE>* rightChild = children[i + 1];
        leftChild->insertKey(keys[i]);
        setKey(rightChild->getKey(0), i);
        rightChild->removeKey(0);
        if (!rightChild->isLeaf()) {
            leftChild->insertChild(rightChild->getChild(0));
            rightChild->removeChild(0);
        }
    } else {
        throw std::out_of_range("Invalid index in performRotation");
    }
}

template <class T, const unsigned int MIN_DEGREE>
void BTreeNode<T, MIN_DEGREE>::writeToDisk(std::ofstream& outFile) {
    for (const auto& key : keys) {
        outFile.write(reinterpret_cast<const char*>(&key), sizeof(T));
    }

    for (const auto& child : children) {
        if (child != nullptr) {
            child->writeToDisk(outFile);
        }
    }
}

template <class T, const unsigned int MIN_DEGREE>
void BTreeNode<T, MIN_DEGREE>::readFromDisk(std::ifstream& inFile) {
    for (auto& key : keys) {
        inFile.read(reinterpret_cast<char*>(&key), sizeof(T));
    }

    if (keys.size() != 2 * MIN_DEGREE - 1) {
        throw std::runtime_error("Error reading keys from disk");
    }

    if (!isLeaf()) {
        // Limpar filhos existentes, se houver
        children.clear();

        for (unsigned int i = 0; i < 2 * MIN_DEGREE; ++i) {
            BTreeNode<T, MIN_DEGREE>* child = new BTreeNode<T, MIN_DEGREE>();
            child->readFromDisk(inFile);
            children.push_back(child);
        }
    }
}

template <class T, const unsigned int MIN_DEGREE>
void BTreeNode<T, MIN_DEGREE>::serialize(std::ofstream& outFile) const {
    for (const auto& key : keys) {
        outFile.write(reinterpret_cast<const char*>(&key), sizeof(T));
    }

    for (const auto& child : children) {
        if (child != nullptr) {
            child->serialize(outFile);
        }
    }

    outFile.put('\n');  // Adicionar uma linha em branco para separar os n�s no arquivo
}
template <class T, const unsigned int MIN_DEGREE>
void BTreeNode<T, MIN_DEGREE>::deserialize(std::ifstream& inFile) {
    // Limpar chaves e filhos existentes, se houver
    keys.clear();
    children.clear();

    for (unsigned int i = 0; i < 2 * MIN_DEGREE - 1; ++i) {
        T key;
        inFile.read(reinterpret_cast<char*>(&key), sizeof(T));
        keys.push_back(key);
    }

    if (!isLeaf()) {
        for (unsigned int i = 0; i < 2 * MIN_DEGREE; ++i) {
            BTreeNode<T, MIN_DEGREE>* child = new BTreeNode<T, MIN_DEGREE>();
            child->deserialize(inFile);
            children.push_back(child);
        }
    }
}

template <class T, const unsigned int MIN_DEGREE>
size_t BTreeNode<T, MIN_DEGREE>::getNodeSize() const {
    size_t keySize = sizeof(T) * keys.size();
    size_t childPointerSize = sizeof(BTreeNode<T, MIN_DEGREE>*) * (children.size() + 1);
    size_t parentPointerSize = sizeof(BTreeNode<T, MIN_DEGREE>*);
    size_t currentSizeSize = sizeof(unsigned int);
    size_t additionalDataSize = sizeof(int);

    return keySize + childPointerSize + parentPointerSize + currentSizeSize + additionalDataSize;
}

#endif // BTREE_NODE_H

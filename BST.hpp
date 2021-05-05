#ifndef BST_HPP
#define BST_HPP

#include "BinaryTree.hpp"
#include <iostream>
using namespace std;

template <typename T>
class BST : public BinaryTree<T> {
    private:
        // copy the values from one BST (argument 2) to the other (argument 1)
        // (recursively)
        void copy(BST<T>*, const BST<T>*);

        // determine if the target value (argument 2) can be found in the BST
        // (argument 1) (recursively)
        bool find(const BST<T>*, const T&) const;

        // find the minimum value in the argument BST (recursively)
        T getMin(const BST<T>*) const;

        // find the height of the argument BST (recursively)
        int height(const BST<T>*) const;

        // insert the value (argument 2) into the proper position of the BST
        // (argument 1) (recursively)
        void insert(BST<T>*, const T&);

        // find the number of leaves in the argument BST (recursively)
        int numLeaves(const BST<T>*) const;

        // find the number of nodes in the argument BST (recursively)
        int numNodes(const BST<T>*) const;

        // remove the value (argument 3) from the BST (argument) using its
        // parent (argument 2) (recursively)
        void remove(BST<T>*, BST<T>*, const T&);

        // remove the minimum value of the BST (argument 1) using its parent
        // (argument 2) (recursively)
        void removeMin(BST<T>*, BST<T>*);

    protected:
        // the value stored in the root node
        T value;

        // a pointer to the left subtree
        BST* left;

        // a pointer to the right subtree
        BST* right;

    public:
        // default constructor
        BST(T = T());

        // copy constructor
        BST(const BST<T>&);

        // overloaded assignment operator
        BST<T>& operator=(const BST<T>&);

        // destructor
        virtual ~BST();

        // determine if the value can be found
        bool find(const T&) const;

        // return the left subtree
        virtual BinaryTree<T>* getLeft() const override;

        // return the right subtree
        virtual BinaryTree<T>* getRight() const override;

        // return the minimum value
        T getMin() const;

        // return the value of the root
        virtual T getValue() const override;

        // find the height of the BST
        virtual int height() const override;

        // insert the given value into the BST
        void insert(const T&);

        // determine if the BST is a leaf node
        virtual bool isLeaf() const override;

        // find the number of leaves in the BST
        virtual int numLeaves() const override;

        // find the number of nodes in the BST
        virtual int numNodes() const override;

        // remove the value while maintaining the BST property
        void remove(const T&);

        // update the left subtree
        virtual void setLeft(BinaryTree<T>*) override;

        // update the right subtree
        virtual void setRight(BinaryTree<T>*) override;

        // update the value of the root
        virtual void setValue(const T&) override;
};

template <typename T>
bool BST<T>::find(const T& v) const {
    return find(this, v); // initial call to start the recursion process
}

template <typename T>
bool BST<T>::find(const BST<T>* t, const T& v) const {
    // TODO
}

template <typename T>
T BST<T>::getMin() const {
    return getMin(this); // initial call to start the recursion process
}

template <typename T>
T BST<T>::getMin(const BST<T>* t) const {
    // TODO
}

template <typename T>
void BST<T>::insert(const T& v) {
    insert(this, v); // initial call to start the recursion process
}

template <typename T>
void BST<T>::insert(BST<T>* t, const T& v) {
    // TODO
}

template <typename T>
void BST<T>::removeMin(BST<T>* s, BST<T>* p) {
    // TODO
}

template <typename T>
void BST<T>::remove(const T& v) {
    if (isLeaf()) {
        cout << "remove() cannot be called on a 1-node BST\n";
    }
    else {
        remove(this, nullptr, v); // initial call to start the recursion process
    }
}

template <typename T>
void BST<T>::remove(BST<T>* r, BST<T>* p, const T& v) {
    // TODO
}



/*******************************************************************************
********************************************************************************
********************************************************************************
********************CODE BELOW DOES NOT NEED TO BE MODIFIED!********************
********************************************************************************
********************************************************************************
*******************************************************************************/



template <typename T>
BST<T>::BST(T v) {
    value = v;
    left = right = nullptr;
}

template <typename T>
BST<T>::BST(const BST<T>& copyObj) {
    copy(this, &copyObj);
}

template <typename T>
BST<T>& BST<T>::operator=(const BST<T>& rightObj) {
    if (this != &rightObj) {
        delete left;
        delete right;
        copy(this, &rightObj);
    }
    return *this;
}

template <typename T>
BST<T>::~BST() {
    delete left;
    delete right;
}

template <typename T>
void BST<T>::copy(BST<T>* t, const BST<T>* copyObj) {
    if (copyObj == nullptr) {
        t = nullptr;
    }
    else {
        if (copyObj->left != nullptr) {
            t->left = new BST<T>();
        }
        if (copyObj->right != nullptr) {
            t->right = new BST<T>();
        }
        t->value = copyObj->value;
        copy(t->left, copyObj->left);
        copy(t->right, copyObj->right);
    }
}

template <typename T>
BinaryTree<T>* BST<T>::getLeft() const {
    return left;
}

template <typename T>
BinaryTree<T>* BST<T>::getRight() const {
    return right;
}

template <typename T>
T BST<T>::getValue() const {
    return value;
}

template <typename T>
int BST<T>::height() const {
    return height(this);
}

template <typename T>
int BST<T>::height(const BST<T>* t) const {
    if (t == nullptr) {
        return 0;
    }
    else {
        int hl = height(t->left);
        int hr = height(t->right);

        return 1 + (hl > hr ? hl : hr);
    }
}

template <typename T>
bool BST<T>::isLeaf() const {
    return left == nullptr && right == nullptr;
}

template <typename T>
int BST<T>::numLeaves() const {
    return numLeaves(this);
}

template <typename T>
int BST<T>::numLeaves(const BST<T>* t) const {
    if (t == nullptr) {
        return 0;
    }
    else if (t->isLeaf()) {
        return 1;
    }
    else {
        return numLeaves(t->left) + numLeaves(t->right);
    }
}

template <typename T>
int BST<T>::numNodes() const {
    return numNodes(this);
}

template <typename T>
int BST<T>::numNodes(const BST<T>* t) const {
    if (t == nullptr) {
        return 0;
    }
    else {
        return 1 + numNodes(t->left) + numNodes(t->right);
    }
}

template <typename T>
void BST<T>::setLeft(BinaryTree<T>* l) {
    cout << "Cannot call setLeft() on a BST\n";
}

template <typename T>
void BST<T>::setRight(BinaryTree<T>* r) {
    cout << "Cannot call setRight() on a BST\n";
}

template <typename T>
void BST<T>::setValue(const T& v) {
    cout << "Cannot call setValue() on a BST\n";
}

#endif

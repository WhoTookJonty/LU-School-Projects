// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// This file includes all of the pieces of the BST implementation

#include "BSTNode.h"
#include "dictionary.h"

#ifndef BST_H
#define BST_H

using namespace std;

// Binary Search Tree implementation for the Dictionary ADT
template <typename Key, typename E>
class BST : public Dictionary<Key, E> {
private:
    // Root of the BST
    BSTNode<Key, E>* root;

    // Number of nodes in the BST
    int nodecount;

    // Inserts a node into BST
    void inserthelp(BSTNode<Key, E>* root, const Key& k, const E& it)
    {
        BSTNode<Key, E>* node = new BSTNode<Key, E>(k, it, NULL, NULL);
        bool inserted = false;
        if (root->left() == root && root->right() == root)
        {
            node->setLeft(root);
            node->setLeftBit(true);
            node->setRight(root);
            node->setRightBit(true);
            root->setLeft(node);
            root->setLeftBit(false);
        }
        else
        {
            BSTNode<Key, E>* curr = root->left();
            while (!inserted)
            {
                if (k < curr->key())
                {
                    if (curr->getLeftBit())
                    {
                        node->setLeft(curr->left());
                        node->setLeftBit(true);
                        node->setRight(curr);
                        node->setRightBit(true);
                        curr->setLeftBit(false);
                        curr->setLeft(node);
                        inserted = true;
                    }
                    else
                    {
                        curr = curr->left();
                    }
                }
                else
                {
                    if (curr->getRightBit())
                    {
                        node->setRight(curr->right());
                        node->setRightBit(true);
                        node->setLeft(curr);
                        node->setLeftBit(true);
                        curr->setRightBit(false);
                        curr->setRight(node);
                        inserted = true;
                    }
                    else
                    {
                        curr = curr->right();
                    }
                }
            }
        }
    }

    // Retrieves how deep an element is in the tree
    int getDepth(BSTNode<Key, E>* mark) const
    {
        int depth = 0;
        BSTNode<Key, E>* curr = root->left();
        bool found = false;

        while (!found && curr != root)
        {
            if (mark == curr)
            {
                found = true;
            }
            else
            {
                depth++;
                if (mark->key() < curr->key())
                {
                    curr = curr->left();
                }
                else
                {
                    curr = curr->right();
                }
            }
        }
        return depth;
    }

    // Returns the inorder successor version
    BSTNode<Key, E>* inorderSuccessor(BSTNode<Key, E>* curr) const
    {
        if (curr->getRightBit())
        {
            return curr->right();
        }
        else
        {
            curr = curr->right();
            while (!curr->getLeftBit())
            {
                curr = curr->left();
            }
            return curr;
        }
    }

    // Return the inorder predecessor version
    BSTNode<Key, E>* inorderPredecessor(BSTNode<Key, E>* curr) const
    {
        if (curr->getLeftBit())
        {
            return curr->left();
        }
        else
        {
            curr = curr->left();
            while (!curr->getRightBit())
            {
                curr = curr->right();
            }
            return curr;
        }
    }

    // Print the BST
    void printhelp(BSTNode<Key, E>* root, int level) const
    {
        if (root->left() == root && root->right())
        {
            return;
        }

        BSTNode<Key, E>* curr = root->left();
        while (!curr->getLeftBit())
        {
            curr = curr->left();
        }

        while (curr != root)
        {
            int depth = getDepth(curr);
            formatSpaces(depth);
            std::cout << curr->key() << std::endl;
            curr = inorderSuccessor(curr);
        }
    }

    // Print BST inorder version
    void printInorderVersion(BSTNode<Key, E>* root, int level) const
    {
        if (root->left() == root && root->right())
        {
            return;
        }

        BSTNode<Key, E>* curr = root->left();

        while(!curr->getLeftBit())
        {
            curr = curr->left();
        }

        while(curr != root)
        {
            std::cout << curr->element() << std::endl;
            curr = inorderSuccessor(curr);
        }
    }

    // Print BST in reverse
    void printReverseVersion(BSTNode<Key, E>* root, int level) const
    {
        if (root->left() == root && root->right())
        {
            return;
        }

        BSTNode<Key, E>* curr = root->left();
        while (!curr->getRightBit())
        {
            curr = curr->right();
        }

        while (curr != root)
        {
            std::cout << curr->element() << std::endl;
            curr = inorderPredecessor(curr);
        }
    }

    // Formats spaces for the node so it looks pretty
    void formatSpaces(int s) const
    {
        for (int i = 0; i < s; ++i)
        {
            cout << "  ";
        }
    }

    // Private "helper" functions
    void clearhelp(BSTNode<Key, E>*);
    BSTNode<Key, E>* deletemin(BSTNode<Key, E>*);
    BSTNode<Key, E>* getmin(BSTNode<Key, E>*);
    BSTNode<Key, E>* removehelp(BSTNode<Key, E>*, const Key&);
    E* findhelp(BSTNode<Key, E>*, const Key&) const;
    void vist(BSTNode<Key, E>*) const;

public:
    // Constructor
    BST()
    {
        root = new BSTNode<Key, E>();
        root->setLeftBit(true);
        root->setRightBit(false);
        root->setLeft(root);
        root->setRight(root);
    }

    // Reinitialize tree
    void clear()
    {
        clearhelp(root); root = NULL; nodecount = 0;
    }

    // Destructor
    ~BST()
    {
        delete root;
    }

    // Insert a record into the tree.
    // k Key value of the record.
    // e The record to insert.
    void insert(const Key& k, const E& e) {
        inserthelp(root, k, e);
        nodecount++;
    }

    // Remove a record from the tree.
    // k Key value of record to remove.
    // Return: The record removed, or NULL if there is none.
    E* remove(const Key& k) {
        E* temp = findhelp(root, k);   // First find it
        if (temp != NULL) {
            root = removehelp(root, k);
            nodecount--;
        }
        return temp;
    }
    // Remove and return the root node from the dictionary.
    // Return: The record removed, null if tree is empty.
    E* removeAny() {  // Delete min value
        if (root != NULL) {
            E* temp = new E;
            *temp = root->element();
            root = removehelp(root, root->key());
            nodecount--;
            return temp;
        }
        else return NULL;
    }

    // Return Record with key value k, NULL if none exist.
    // k: The key value to find. */
    // Return some record matching "k".
    // Return true if such exists, false otherwise. If
    // multiple records match "k", return an arbitrary one.
    E* find(const Key& k) const { return findhelp(root, k); }

    // Return the number of records in the dictionary.
    int size() { return nodecount; }

    void print() const { // Print the contents of the BST
        if (root->left() == root && root->right() == root) cout << "The BST is empty.\n";
        else printhelp(root, 0);
    }

    // Print inorder tree
    void printInorder()
    {
        if (root->left() == root && root->right() == root)
        {
            cout << "The BST is empty\n";
        }
        else
        {
            printInorderVersion(root, 0);
        }
    }

    // Print reverse tree
    void printReverse()
    {
        if (root->left() == root && root->right() == root)
        {
            cout << "The BST is empty\n";
        }
        else
        {
            printReverseVersion(root, 0);
        }
    }
};

// Visit -- prints out root
template <typename Key, typename E>
void BST<Key, E>::vist(BSTNode<Key, E>* r) const {
    cout << "Node - " << r->element() << endl;
}

// Clean up BST by releasing space back free store
template <typename Key, typename E>
void BST<Key, E>::
clearhelp(BSTNode<Key, E>* root) {
    if (root == NULL) return;
    clearhelp(root->left());
    clearhelp(root->right());
    delete root;
}

// Delete the minimum value from the BST, returning the revised BST
template <typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::
getmin(BSTNode<Key, E>* rt) {
    if (rt->left() == NULL)
        return rt;
    else return getmin(rt->left());
}
template <typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::
deletemin(BSTNode<Key, E>* rt) {
    if (rt->left() == NULL) // Found min
        return rt->right();
    else {                      // Continue left
        rt->setLeft(deletemin(rt->left()));
        return rt;
    }
}

// Remove a node with key value k
// Return: The tree with the node removed
template <typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::
removehelp(BSTNode<Key, E>* rt, const Key& k) {
    if (rt == NULL) return NULL;    // k is not in tree
    else if (k < rt->key())
        rt->setLeft(removehelp(rt->left(), k));
    else if (k > rt->key())
        rt->setRight(removehelp(rt->right(), k));
    else {                            // Found: remove it
        BSTNode<Key, E>* temp = rt;
        if (rt->left() == NULL) {     // Only a right child
            rt = rt->right();         //  so point to right
            delete temp;
        }
        else if (rt->right() == NULL) { // Only a left child
            rt = rt->left();          //  so point to left
            delete temp;
        }
        else {                    // Both children are non-empty
            BSTNode<Key, E>* temp = getmin(rt->right());
            rt->setElement(temp->element());
            rt->setKey(temp->key());
            rt->setRight(deletemin(rt->right()));
            delete temp;
        }
    }
    return rt;
}

// Find a node with the given key value
template <typename Key, typename E>
E* BST<Key, E>::findhelp(BSTNode<Key, E>* root,
    const Key& k) const {
    if (root == NULL) return NULL;          // Empty tree
    if (k < root->key())
        return findhelp(root->left(), k);   // Check left
    else if (k > root->key())
        return findhelp(root->right(), k);  // Check right
    else {
        E* temp = new E;
        *temp = root->element();
        return temp;  // Found it
    }
}

#endif
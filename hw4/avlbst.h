#ifndef RBBST_H
#define RBBST_H

#include <iostream>
#include <exception>
#include <cstdlib>
#include <algorithm>
#include "bst.h"

struct KeyError { };

/**
* A special kind of node for an AVL tree, which adds the height as a data member, plus
* other additional helper functions. You do NOT need to implement any functionality or
* add additional data members or helper functions.
*/
template <typename Key, typename Value>
class AVLNode : public Node<Key, Value>
{
public:
    // Constructor/destructor.
    AVLNode(const Key& key, const Value& value, AVLNode<Key, Value>* parent);
    virtual ~AVLNode();

    // Getter/setter for the node's height.
    int getHeight () const;
    void setHeight (int height);

    // Getters for parent, left, and right. These need to be redefined since they
    // return pointers to AVLNodes - not plain Nodes. See the Node class in bst.h
    // for more information.
    virtual AVLNode<Key, Value>* getParent() const override;
    virtual AVLNode<Key, Value>* getLeft() const override;
    virtual AVLNode<Key, Value>* getRight() const override;

protected:
    int height_;
};

/*
  -------------------------------------------------
  Begin implementations for the AVLNode class.
  -------------------------------------------------
*/

/**
* An explicit constructor to initialize the elements by calling the base class constructor and setting
* the color to red since every new node will be red when it is first inserted.
*/
template<class Key, class Value>
AVLNode<Key, Value>::AVLNode(const Key& key, const Value& value, AVLNode<Key, Value> *parent) :
    Node<Key, Value>(key, value, parent), height_(1)
{

}

/**
* A destructor which does nothing.
*/
template<class Key, class Value>
AVLNode<Key, Value>::~AVLNode()
{

}

/**
* A getter for the height of a AVLNode.
*/
template<class Key, class Value>
int AVLNode<Key, Value>::getHeight() const
{
    return height_;
}

/**
* A setter for the height of a AVLNode.
*/
template<class Key, class Value>
void AVLNode<Key, Value>::setHeight(int height)
{
    height_ = height;
}

/**
* An overridden function for getting the parent since a static_cast is necessary to make sure
* that our node is a AVLNode.
*/
template<class Key, class Value>
AVLNode<Key, Value> *AVLNode<Key, Value>::getParent() const
{
    return static_cast<AVLNode<Key, Value>*>(this->parent_);
}

/**
* Overridden for the same reasons as above.
*/
template<class Key, class Value>
AVLNode<Key, Value> *AVLNode<Key, Value>::getLeft() const
{
    return static_cast<AVLNode<Key, Value>*>(this->left_);
}

/**
* Overridden for the same reasons as above.
*/
template<class Key, class Value>
AVLNode<Key, Value> *AVLNode<Key, Value>::getRight() const
{
    return static_cast<AVLNode<Key, Value>*>(this->right_);
}


/*
  -----------------------------------------------
  End implementations for the AVLNode class.
  -----------------------------------------------
*/


template <class Key, class Value>
class AVLTree : public BinarySearchTree<Key, Value>
{
public:
    virtual void insert (const std::pair<const Key, Value> &new_item); // TODO
    virtual void remove(const Key& key);  // TODO
protected:
    virtual void nodeSwap( AVLNode<Key,Value>* n1, AVLNode<Key,Value>* n2);

    // Add helper functions here
    void rotateLeft(AVLNode<Key,Value>* n1);
    void rotateRight(AVLNode<Key,Value>* n1);
    bool isLeftChild(AVLNode<Key,Value>* n1);
    bool isRightChild(AVLNode<Key,Value>* n1);
    int height(AVLNode<Key,Value>* n1);
    void balanceTree(AVLNode<Key,Value>* n1); //call this on the node that was inserted or the parent of the node that was
                                              //just removed. Will go up tree and fix height.
};

template<class Key, class Value>
void AVLTree<Key, Value>::insert (const std::pair<const Key, Value> &new_item)
{
    BinarySearchTree<Key,Value>::insert(new_item);
    BinarySearchTree<Key,Value>::iterator it;
    it = BinarySearchTree<Key,Value>::find(new_item.first);
    AVLNode<Key,Value> *curr = it->current_;
    AVLNode<Key,Value>* rootPtr; //this will keep track of which node is the root

    curr->height_ = 1;
    while(curr->getParent() != NULL)
    {
        curr = curr->getParent();
        curr->height_++;
    }

    curr = checkBalance(this->root_); //returns a NULL ptr if balanced

    if (curr != NULL) 
    {
        if (curr->getLeft()->height_ > curr->getRight->height_) //if left side of tree
        {
            curr = curr->getLeft();
            if (curr->getLeft()->height_ >= curr->getRight()->height_) //zig zig
            {
                rotateRight(curr->getParent());
                rootPtr = curr;
            }
            else //zig zag
            {
                AVLNode<Key,Value>* currP = curr->getParent();
                rootPtr = curr->getRight();
                rotateLeft(curr);
                rotateRight(currP);
            }
        }
        else
        {
            if (curr->getRight()->height_ > curr->getleft()->height_) //if right side of tree
            {
                curr = curr->getRight();
                if (curr->getRight()->height_ >= curr->getLeft()->height_)//zig zig
                {
                    rotateLeft(curr->getParent());
                    rootPtr = curr;
                }
                else //zig zag
                {
                    AVLNode<Key,Value>* currP = curr->getParent();
                    rootPtr = curr->getLeft();
                    rotateRight(curr);
                    rotateLeft(currP);
                }
            }
        }
        this->root_ = rootPtr; //update root
        calcHeight(rootPtr); //update heights
    }
    
}

template<class Key, class Value>
void AVLTree<Key, Value>:: remove(const Key& key)
{
    // TODO
}

template<class Key, class Value>
void AVLTree<Key, Value>::nodeSwap( AVLNode<Key,Value>* n1, AVLNode<Key,Value>* n2)
{
    BinarySearchTree<Key, Value>::nodeSwap(n1, n2);
    int tempH = n1->getHeight();
    n1->setHeight(n2->getHeight());
    n2->setHeight(tempH);
}

template<class Key, class Value>
void rotateLeft(AVLNode<Key,Value>* n1)
{
    AVLNode<Key,Value>* temp;
    temp = n1->getRight();
    n1->setRight(temp->getLeft());
    temp->setLeft(n1);
}

template<class Key, class Value>
void rotateRight(AVLNode<Key,Value>* n1)
{
    AVLNode<Key,Value>* temp;
    temp = n1->getLeft();
    n1->setLeft(temp->getRight());
    temp->setRight(n1);
}

template<class Key, class Value>
bool isLeftChild(AVLNode<Key,Value>* n1)
{
    if (n1->getParent()->getLeft() = n1)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

template<class Key, class Value>
bool isRightChild(AVLNode<Key,Value>* n1)
{
    if (n1->getParent()->getRight() = n1)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

//recursively recalculates the heights for all the nodes up to and including n1
int calcHeight(AVLNode<Key,Value>* n1)
{
    if (n1 == NULL)
    {
        n1->height_ = 0;
        return 0;
    }
    n1->height_ = 1 + max(calcHeight(n1->getLeft()), calcHeight(n1->getRight()));
    return n1->height;
}

/*recursively checks balance of all nodes below and including n1
when an unbalanced node is found that node is returned */
AVLNode<Key,Value>* checkBalance(AVLNode<Key,Value>* n1)
{
    if (n1 == NULL)
    {
        return NULL;
    }
    else if (abs(n1->getLeft()->height_ - n1->getRight()->height_) > 1)
    {
        return n1;
    }
    else
    {
        checkBalance(n1->getLeft());
        checkBalance(n1->getRight());
    }
    
}

#endif

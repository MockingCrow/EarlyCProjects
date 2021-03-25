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
    int calcHeight(Node<Key,Value>* n1);
    Node<Key,Value>* checkBalance(Node<Key,Value>* n1); //call this on the node that was inserted or the parent of the node that was
                                              
};

template<class Key, class Value>
void AVLTree<Key, Value>::insert (const std::pair<const Key, Value> &new_item)
{
    Node<Key,Value>* curr;
    Node<Key,Value>* rootPtr = NULL;
    
    BinarySearchTree<Key,Value>::insert(new_item); //do bst insert first
    
    calcHeight(static_cast<AVLNode<Key,Value>*>(this->root_));
    
    curr = checkBalance(static_cast<AVLNode<Key,Value>*>(this->root_)); //returns a NULL ptr if balanced

    if (curr != NULL) 
    {
        if (static_cast<AVLNode<Key,Value>*>(curr)->getLeft()->getHeight() > 
            static_cast<AVLNode<Key,Value>*>(curr)->getRight()->getHeight()) //if left side of tree
        {
            curr = curr->getLeft();
            if (static_cast<AVLNode<Key,Value>*>(curr)->getLeft()->getHeight() >= 
                static_cast<AVLNode<Key,Value>*>(curr)->getRight()->getHeight()) //zig zig, prefer zig zig over zig zag
            {
                rotateRight(static_cast<AVLNode<Key,Value>*>(curr->getParent()));
                rootPtr = curr;
            }
            else //zig zag
            {
                Node<Key,Value>* currP = curr->getParent();
                rootPtr = curr->getRight();
                rotateLeft(static_cast<AVLNode<Key,Value>*>(curr));
                rotateRight(static_cast<AVLNode<Key,Value>*>(currP));
            }
        }
        else
        {
            if (static_cast<AVLNode<Key,Value>*>(curr)->getRight()->getHeight() > 
                static_cast<AVLNode<Key,Value>*>(curr)->getLeft()->getHeight()) //if right side of tree
            {
                curr = curr->getRight();
                if (static_cast<AVLNode<Key,Value>*>(curr)->getRight()->getHeight() >= 
                    static_cast<AVLNode<Key,Value>*>(curr)->getLeft()->getHeight())//zig zig, prefer zig zig over zig zag
                {
                    rotateLeft(static_cast<AVLNode<Key,Value>*>(curr->getParent()));
                    rootPtr = curr;
                }
                else //zig zag
                {
                    Node<Key,Value>* currP = curr->getParent();
                    rootPtr = curr->getLeft();
                    rotateRight(static_cast<AVLNode<Key,Value>*>(curr));
                    rotateLeft(static_cast<AVLNode<Key,Value>*>(currP));
                }
            }
        }
        this->root_ = rootPtr; //update root
        calcHeight(static_cast<AVLNode<Key,Value>*>(rootPtr)); //update heights
    }
    
}

template<class Key, class Value>
void AVLTree<Key, Value>:: remove(const Key& key)
{
    BinarySearchTree<Key,Value>::remove(key);

    calcHeight(static_cast<AVLNode<Key,Value>*>(this->root_));
    Node<Key,Value>* curr;
    Node<Key,Value>* rootPtr = NULL;
    curr = checkBalance(static_cast<AVLNode<Key,Value>*>(this->root_));

    if (curr != NULL) 
    {
        if (static_cast<AVLNode<Key,Value>*>(curr)->getLeft()->getHeight() > 
            static_cast<AVLNode<Key,Value>*>(curr)->getRight()->getHeight()) //if left side of tree
        {
            curr = curr->getLeft();
            if (static_cast<AVLNode<Key,Value>*>(curr)->getLeft()->getHeight() >= 
               static_cast<AVLNode<Key,Value>*>(curr)->getRight()->getHeight()) //zig zig
            {
                rotateRight(static_cast<AVLNode<Key,Value>*>(curr->getParent()));
                rootPtr = curr;
            }
            else //zig zag
            {
                Node<Key,Value>* currP = curr->getParent();
                rootPtr = curr->getRight();
                rotateLeft(static_cast<AVLNode<Key,Value>*>(curr));
                rotateRight(static_cast<AVLNode<Key,Value>*>(currP));
            }
        }
        else
        {
            if (static_cast<AVLNode<Key,Value>*>(curr)->getRight()->getHeight() > 
                static_cast<AVLNode<Key,Value>*>(curr)->getLeft()->getHeight()) //if right side of tree
            {
                curr = curr->getRight();
                if (static_cast<AVLNode<Key,Value>*>(curr)->getRight()->getHeight() >= 
                    static_cast<AVLNode<Key,Value>*>(curr)->getLeft()->getHeight())//zig zig
                {
                    rotateLeft(static_cast<AVLNode<Key,Value>*>(curr->getParent()));
                    rootPtr = curr;
                }
                else //zig zag
                {
                    Node<Key,Value>* currP = curr->getParent();
                    rootPtr = curr->getLeft();
                    rotateRight(static_cast<AVLNode<Key,Value>*>(curr));
                    rotateLeft(static_cast<AVLNode<Key,Value>*>(currP));
                }
            }
        }
        this->root_ = rootPtr; //update root
        calcHeight(static_cast<AVLNode<Key,Value>*>(rootPtr)); //update heights
    }
}

template<class Key, class Value>
void AVLTree<Key, Value>::nodeSwap(AVLNode<Key,Value>* n1, AVLNode<Key,Value>* n2)
{
    BinarySearchTree<Key, Value>::nodeSwap(n1, n2);
    int tempH = n1->getHeight();
    n1->setHeight(n2->getHeight());
    n2->setHeight(tempH);
}

template<class Key, class Value>
void AVLTree<Key, Value>::rotateLeft(AVLNode<Key,Value>* n1)
{
    AVLNode<Key,Value>* temp;
    temp = n1->getRight();
    n1->setRight(temp->getLeft());
    temp->setLeft(n1);
}

template<class Key, class Value>
void AVLTree<Key, Value>::rotateRight(AVLNode<Key,Value>* n1)
{
    AVLNode<Key,Value>* temp;
    temp = n1->getLeft();
    n1->setLeft(temp->getRight());
    temp->setRight(n1);
}

//recursively recalculates the heights for all the nodes up to and including n1
template<class Key, class Value>
int AVLTree<Key, Value>::calcHeight(Node<Key,Value>* n1)
{
    if (static_cast<AVLNode<Key,Value>*>(n1) == NULL)
    {
        return 0;
    }
    static_cast<AVLNode<Key,Value>*>(n1)->
    setHeight(1 + std::max(calcHeight(static_cast<AVLNode<Key,Value>*>(n1)->getLeft()), 
    calcHeight(static_cast<AVLNode<Key,Value>*>(n1)->getRight())));
    return static_cast<AVLNode<Key,Value>*>(n1)->getHeight();
}

/*recursively checks balance of all nodes below and including n1
when an unbalanced node is found that node is returned */
template<class Key, class Value>
Node<Key,Value>* AVLTree<Key, Value>::checkBalance(Node<Key,Value>* n1)
{
    if (n1->getLeft() == NULL && n1->getRight() == NULL)
    {
        return NULL;
    }
    else if (n1->getLeft() != NULL && n1->getRight() == NULL)
    {   
        if (static_cast<AVLNode<Key,Value>*>(n1)->getLeft()->getHeight() >= 2)
        {
            return n1;
        }
    }
    else if (n1->getLeft() == NULL && n1->getRight() != NULL)
    {
        if (static_cast<AVLNode<Key,Value>*>(n1)->getRight()->getHeight() >= 2)
        {
            return n1;
        }
    }
    else if (abs(static_cast<AVLNode<Key,Value>*>(n1)->getLeft()->getHeight() - 
            static_cast<AVLNode<Key,Value>*>(n1)->getRight()->getHeight()) > 1)
    {
        return n1;
    }
    else
    {
        checkBalance(n1->getLeft());
        checkBalance(n1->getRight());
    }
    return NULL;  
}

#endif

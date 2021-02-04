/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even
numbers and the other contains the odd numbers. Students
will receive no credit for non-recursive solutions.
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/
#define NULL 0
#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens) {
    // edges cases for empty lists
    struct Node* eList = NULL;
    struct Node* oList = NULL;

    if (in == NULL) {
        if (odds == NULL && evens == NULL) {
            return;
        } else if (evens != NULL && odds == NULL) {
            evens->next = NULL; 
            evens = eList; //evens now points to beginning of list
            return;
        } else if (odds != NULL && evens == NULL) {
            odds->next = NULL; //odds now points to beginning of list
            odds = oList;
            return;
        } else {
            evens->next = NULL; //evens now points to beginning of list
            odds->next = NULL; //odds now points to beginning of list
            evens = eList;
            odds = oList;
            return;
        }
    }

    // is val even
    if (in->value % 2 == 0) {
        // move node to the end of the evens list and continue
        // to traverse down both the original and split list
        if (evens == NULL) {
            // if the list is empty fill it and dont traverse even
            evens = in;
            eList = evens;  // keep track of beggining of list
            split(in->next, odds, evens);
        } else {
            evens->next = in;
            split(in->next, odds, evens->next);
        }
    }

    else {
        // same but for odd vals
        if (odds == NULL) {
            // if list is empty fill it and dont traverse odd
            odds = in;
            oList = odds;  // keep track of beginning of list
            split(in->next, odds, evens);
        } else {
            odds->next = in;
            split(in->next, odds->next, evens);
        }
    }
}

/* If you needed a helper function, write it here */

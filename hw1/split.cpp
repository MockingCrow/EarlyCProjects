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

#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  //is val even
  if (in->value % 2 == 0)
  {
    /*move node to the end of the evens list and continue
    to traverse down both the original and split list*/
    evens->next = in;
    evens = even->next;
    in = in->next;
  }
  else 
  {
    //same but for odd vals
    odds->next = in;
    odds = odd->next;
    in = in->next;
  }

  //as long as there are nodes left, recursively call
  if (in != NULL)
  {
    split(in, odds, evens);
  }
  
  even->next = NULL;
  odd->next = NULL;

}

/* If you needed a helper function, write it here */

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
  //!! if in is empty add edge cases at the end!!

  if (in == NULL)
  {
    evens->next = NULL;
    odds->next = NULL;
    return;
  }

  //is val even
  if (in->value % 2 == 0)
  {
    //move node to the end of the evens list and continue
    //to traverse down both the original and split list
    if (evens == NULL)
    {
      //if the list is empty fill it and dont traverse even
      evens = in;
      eList = evens; //keep track of beggining of list
      split (in->next, odds, evens);
    }
    else
    {
      evens->next = in;
      split (in->next, odds, evens->next);
      
    }
  }

  else 
  {
    //same but for odd vals
    if (odds == NULL)
    {
      //if list is empty fill it and dont traverse odd
      odds = in;
      oList = odds; //keep track of beginning of list
      split(in->next, odds, evens);
    }
    else
    {
      odds->next = in;
      split(in->next, odds->next, evens);
      
    }
  }
 
}

/* If you needed a helper function, write it here */

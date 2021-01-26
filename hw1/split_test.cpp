#include <iostream>
#include "split.h"

using namespace std;

struct Node* head = NULL;
struct Node* odds = NULL;
struct Node* evens = NULL;
struct Node* eList = NULL;
struct Node* oList = NULL;

// make linked list by appending to the beginning
void append (int num)
{
    struct Node* addNode = (struct Node*) malloc(sizeof(struct Node));
    addNode->value = num;
    addNode->next = head;
    head = addNode;

}

// print linked list front to end
void printList(Node*& beginning)
{
    struct Node* traverse;
    traverse = beginning;
    while (traverse != NULL)
    {
        cout << traverse->value << " ";
        traverse = traverse->next; 
    }
}

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

int main(){
  //populate original list
  append(9);
  append(4);
  append(6);
  append(10);
  append(12);
  append (13);
  append(0);
  append(71);
  
  split(head, odds, evens);
  cout << "Evens: ";
  printList(eList);
  cout << "Odds: ";
  printList(odds);
  cout << endl;

  return 0;
}
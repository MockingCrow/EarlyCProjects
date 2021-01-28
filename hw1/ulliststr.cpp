#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream>

using namespace std;

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}


string* ULListStr::getValAtLoc(size_t loc) const
{
  string* ptr;
  Item* current = head_;
  unsigned int i = current->first;//keeps track of index
  unsigned int count = 0;//keeps track of count across items

  while (count != loc) //while count doesn't equal the ith element
  {
    if (i == ARRSIZE-1)
    {
      //moving to the next item when i reaches the end of the current item
      current = current->next;
      i = current->first;
    }
    else
    {
      i++;
    } 
    count++; //counting starting from "0"
  }

  ptr = &(current->val[i]);
  return ptr;
}


void ULListStr::push_back(const std::string& val)
{
  Item* current = tail_;
  
  if (head_ == NULL && tail_ == NULL)
  {
    //if the list is empty create a new item and
    //add the value the front of that item's array
    struct Item* newItem = (struct Item*) malloc(sizeof(struct Item));

    head_ = newItem;
    tail_ = newItem;

    newItem->first = 0;
    newItem->last = 1;
    newItem->val[0] = val;

    size_ = 1;
  }
  else if (current->last == ARRSIZE)             
  {
    //if the last item is full add a new one  
    //and add that value at the front of the new item's array
    struct Item* newItem = (struct Item*) malloc(sizeof(struct Item));

    current->next = newItem;
    newItem->prev = current;
    newItem->next = NULL;
    tail_ = newItem;

    newItem->first = 0;
    newItem->last = 1;
    newItem->val[0] = val;

    size_++;

  }
  else
  {
    //else just add it to the end of tail's array
    unsigned int temp = current->last;
    current->val[temp] = val;
    (current->last)++;

    size_++;

  }
}


void ULListStr::push_front(const std::string& val)
{
  Item* current = head_;

  if (head_ == NULL && tail_ == NULL)
  {
    struct Item* newItem = (struct Item*) malloc(sizeof(struct Item));

    head_ = newItem;
    tail_ = newItem;

    newItem->first = ARRSIZE-1;
    newItem->last = ARRSIZE;
    newItem->val[ARRSIZE-1] = val;

    size_ = 1;
  }
  else if (current->first == 0)
  {
    struct Item* newItem = (struct Item*) malloc(sizeof(struct Item));

    current->prev = newItem;
    newItem->prev = NULL;
    newItem->next = current;
    head_ = newItem;

    newItem->first = ARRSIZE-1;
    newItem->last = ARRSIZE;
    newItem->val[ARRSIZE-1] = val;

    size_++;
  }
  else
  {
    unsigned int temp = current->first - 1;
    current->val[temp] = val;
    (current->first)--;

    size_++;
  }


}
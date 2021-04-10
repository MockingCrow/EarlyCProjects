  #include <vector>
  #include <string>
  #include <map>
  #include <algorithm>

  template <typename T>
  class MinHeap {
     public:
        MinHeap (int d);
       /* Constructor that builds a d-ary Min Heap
        This should work for any d >= 2,
        but doesn't have to do anything for smaller d.*/

        ~MinHeap ();

        void add (T item, int priority);
        /* adds the item to the heap, with the given priority. */

        const T & peek () const;
        
        
        void remove ();
        /* removes the element with smallest priority.
	    Break ties however you wish.
        Throws an exception if the heap is empty. */


        bool isEmpty ();
        /* returns true iff there are no elements on the heap. */

   private:
    // whatever you need to naturally store things.
    // You may also add helper functions here.
    
    std::vector<T> heap;
    std::map<T, int> priority_;
    int d_;
    void trickleDown(int loc);
    void trickleUp(int loc);
};


template<class T>
MinHeap<T>::MinHeap (int d)
/* Constructor that builds a d-ary Min Heap
This should work for any d >= 2,
but doesn't have to do anything for smaller d.*/
{
    d_ = d;
}

template<class T>
MinHeap<T>::~MinHeap () {}

template<class T>
void MinHeap<T>::add (T item, int priority)
/* adds the item to the heap, with the given priority. */
{
    heap.push_back(item);
    priority_.insert(std::pair<T, int>(item, priority));
    trickleUp(heap.size()-1);
}

template<class T>
const T & MinHeap<T>::peek () const
{
/* returns the element with smallest priority.  
Break ties however you wish.  
Throws an exception if the heap is empty. */
    if (heap.size() == 0)
    {
        throw std::invalid_argument("Invalid Argument");
    }
    else
    {
        return heap[0];
    }
}

template<class T>
void MinHeap<T>::remove ()
/* removes the element with smallest priority.
Break ties however you wish.
Throws an exception if the heap is empty. */
{
    heap[0] = heap.back();
    heap.pop_back();
    trickleDown(0);
}

template<class T>
bool MinHeap<T>::isEmpty ()
/* returns true iff there are no elements on the heap. */
{
    if (heap.size() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
void MinHeap<T>::trickleDown(int loc)
{
    unsigned int smal = d_*loc+1;
    if (smal >= heap.size()) return;
    
    typename std::map<T, int>::iterator it;
    typename std::map<T, int>::iterator it1;

    for (int i = 0; i < d_; i++)
    {
        if (smal+1 < heap.size())
        {
            int nextChild = smal+1;
            
            it = priority_.find(heap[nextChild]);
            it1 = priority_.find(heap[smal]);

            if (it->second < it1->second)
            {
                smal = nextChild;
            }
        }
    }

    it = priority_.find(heap[loc]);
    it1 = priority_.find(heap[smal]);
    if (it->second > it1->second)
    {
        std::swap(heap[loc], heap[smal]);
        trickleDown(smal);
    }
}

template<class T>
void MinHeap<T>::trickleUp(int loc)
{
    int parent = (loc - 1) / d_;
    typename std::map<T, int>::iterator it;
    typename std::map<T, int>::iterator it1;
    it = priority_.find(heap[loc]);
    it1 = priority_.find(heap[parent]);

    while((parent >= 0) && (it->second < it1->second))
    {
        std::swap(heap[parent], heap[loc]);
        loc = parent;
        parent = (loc-1) / d_;
        it = priority_.find(heap[loc]);
        it1 = priority_.find(heap[parent]);
    }
}
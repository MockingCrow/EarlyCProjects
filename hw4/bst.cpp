#include <iostream>
#include "bst.h"
#include "print_bst.h"

using namespace std;

int main()
{
    BinarySearchTree<int,string> tree = BinarySearchTree<int,string>();

    tree.insert(pair<int, string>(6,"yello"));
    tree.insert(pair<int, string>(10,"hello"));
    tree.insert(pair<int, string>(14,"inclass"));
    tree.insert(pair<int, string>(11,"coding"));
    tree.insert(pair<int, string>(2,"hehe"));
    tree.insert(pair<int, string>(1,"testing"));
    tree.insert(pair<int, string>(8,"resting"));

    BinarySearchTree<int,string>::iterator it = tree.find(6); 
    Node<int, string> *ptr = it.current_;
    printRoot(ptr);

    return 0;
}
#include <map>
#include <set>
#include <vector>
#include "dataStore.h"
#include "MyDataStore.h"
#include "util.h"

using namespace std;

MyDataStore::~MyDataStore()
{

}

void MyDataStore::addProduct(Product* p)
{
    set<string> temp = p->keywords();
    set<string>::iterator it = temp.begin();

    //every keyword for a Product "p" will map to that Product
    for (; it != temp.end(); it++)
    {
        productList.insert(pair<string, Product*>(*it, p));
    }
}

void MyDataStore::addUser(User* u)
{
    userList.insert(pair<string, User*>(User->name_, User*));
}

vector<Product*> MyDataStore::search(vector<string>& terms, int type)
{
    multimap<string, Product*>::iterator it;
    it = productList.find(terms[0]);
    set<Product*> setTotal; //keeps updating as more products are compared 
    set<Product*> setNext; //finds the next set of products to compare to setTotal
    vector<Product*> finalVector;
    int count = 0;

    //populate setTotal for the first time with all Product* they correspond to the first search term
    for (int i = 0; i < productList.count(terms[0]); i++)
    {
        setTotal.insert(it->second);
        it++;
    }

    int j = 1;
    while (count != terms.size())
    {
        it = productList.find(terms[j]);
        setNext.clear();
        //populate setNext with the Product*(s) that correspond to the next search term
        for (int i = 0; i < productList.count(terms[j]); i++)
        {   
            setNext.insert(it->second)
            it++;
        }
        //compare setNext to the current "total" and update the "total"
        if (type == 0)
        {
            setTotal = setIntersection<set<Product*>>(setTotal, setNext);
        }
        else if (type == 1)
        {
            setTotal = setUnion<set<Product*>>(setTotal, setNext);
        }
        j++;
    }

    set<Product*>::iterator it1 = setTotal.begin();
    for (; it != setTotal.end(); it++)
    {
        finalVector.push_back(*it);
    }
    return finalVector;
}
    
    
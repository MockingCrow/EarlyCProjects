#include <map>
#include <set>
#include <vector>
#include "dataStore.h"
#include "MyDataStore.h"
#include "util.h"
#include "user.h"
#include "product.h"

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
        productList.insert(pair<string, Product*>(convToLower(*it), p));
    }
    noRepeats.insert(p);

}

void MyDataStore::addUser(User* u)
{
    userList.insert(pair<string, User*>(u->getName(), u));
    deque<Product*> temp;
    userCarts.insert(pair<string, deque<Product*>>(u->getName(), temp));
}

vector<Product*> MyDataStore::search(vector<string>& terms, int type)
{

    multimap<string, Product*>::iterator it;
    string tempStr = *parseStringToWords(terms[0]).begin();
    it = productList.find(tempStr);
    std::set<Product*> setTotal; //keeps updating as more products are compared 
    std::set<Product*> setNext; //finds the next set of products to compare to setTotal
    std::vector<Product*> finalVector;

    //populate setTotal for the first time with all Product* that correspond to the first search term
    for (unsigned int i = 0; i < productList.count(tempStr); i++)
    {
        setTotal.insert(it->second);
        it++;
    }

    unsigned int j = 1;
    while (j != terms.size())
    {
        tempStr = *parseStringToWords(terms[j]).begin();
        it = productList.find(tempStr);
        setNext.clear();
        //populate setNext with the Product*(s) that correspond to the next search term
        for (unsigned int i = 0; i < productList.count(tempStr); i++)
        {   
            setNext.insert(it->second);
            it++;
        }
        //compare setNext to the current "total" and update the "total"
        if (type == 0)
        {
            setTotal = setIntersection(setTotal, setNext);
        }
        else if (type == 1)
        {
            setTotal = setUnion(setTotal, setNext);
        }
        j++;
        
    }

    typename set<Product*>::iterator it1 = setTotal.begin();
    for (; it1 != setTotal.end(); it1++)
    {
        finalVector.push_back(*it1);
    }
    return finalVector;
}

void MyDataStore::dump(ostream& ofile)
{
    ofile << "<products>" << endl;
    set<Product*>::iterator it;
    it = noRepeats.begin();

    for (; it != noRepeats.end(); it++)
    {
        (*it)->dump(ofile);
    }

    ofile << "</products>" << endl;
    ofile << "<users>" << endl;

    map<string, User*>::iterator it1;
    it1 = userList.begin();
    for (; it1 != userList.end(); it1++)
    {
        it1->second->dump(ofile);
    }
    ofile << "</users>" << endl;
}
    
    
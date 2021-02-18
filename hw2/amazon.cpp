#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include "product.h"
#include "db_parser.h"
#include "product_parser.h"
#include "util.h"
#include "MyDataStore.h"
#include "book.h"
#include "clothing.h"
#include "movie.h"
#include "datastore.h"

using namespace std;

struct ProdNameSorter {
    bool operator()(Product* p1, Product* p2) {
        return (p1->getName() < p2->getName());
    }
};
void displayProducts(vector<Product*>& hits);
void displayItems(deque<Product*>& cart);

int main(int argc, char* argv[])
{
    if(argc < 2) {
        cerr << "Please specify a database file" << endl;
        return 1;
    }

    /****************
     * Declare your derived DataStore object here replacing
     *  DataStore type to your derived type
     ****************/
    MyDataStore ds;



    // Instantiate the individual section and product parsers we want
    ProductSectionParser* productSectionParser = new ProductSectionParser;
    productSectionParser->addProductParser(new ProductBookParser);
    productSectionParser->addProductParser(new ProductClothingParser);
    productSectionParser->addProductParser(new ProductMovieParser);
    UserSectionParser* userSectionParser = new UserSectionParser;

    // Instantiate the parser
    DBParser parser;
    parser.addSectionParser("products", productSectionParser);
    parser.addSectionParser("users", userSectionParser);

    // Now parse the database to populate the DataStore
    if( parser.parse(argv[1], ds) ) {
        cerr << "Error parsing!" << endl;
        return 1;
    }

    cout << "=====================================" << endl;
    cout << "Menu: " << endl;
    cout << "  AND term term ...                  " << endl;
    cout << "  OR term term ...                   " << endl;
    cout << "  ADD username search_hit_number     " << endl;
    cout << "  VIEWCART username                  " << endl;
    cout << "  BUYCART username                   " << endl;
    cout << "  QUIT new_db_filename               " << endl;
    cout << "====================================" << endl;

    vector<Product*> hits;
    bool done = false;
    while(!done) {
        cout << "\nEnter command: " << endl;
        string line;
        getline(cin,line);
        stringstream ss(line);
        string cmd;
        if((ss >> cmd)) {
            if( cmd == "AND") {
                string term;
                vector<string> terms;
                while(ss >> term) {
                    term = convToLower(term);
                    terms.push_back(term);
                }
                hits = ds.search(terms, 0);
                displayProducts(hits);
            }
            else if ( cmd == "OR" ) {
                string term;
                vector<string> terms;
                while(ss >> term) {
                    term = convToLower(term);
                    terms.push_back(term);
                }
                hits = ds.search(terms, 1);
                displayProducts(hits);
            }
            else if ( cmd == "QUIT") {
                string filename;
                if(ss >> filename) {
                    ofstream ofile(filename.c_str());
                    ds.dump(ofile);
                    ofile.close();
                }
                done = true;
            }
            else if (cmd == "VIEWCART")
            {
                string name_;
                
                if (ss >> name_)
                {
                    name_ = convToLower(name_);
                    map<string, deque<Product*>>::iterator it;
                    if (ds.userCarts.find(name_) == ds.userCarts.end())
                    {
                        cout << "Invalid username" << endl;
                    }
                    else
                    {
                        it = ds.userCarts.find(name_);
                        deque<Product*> cart;
                        cart = it->second;
                        displayItems(cart);
                    }
                    
                }
                else
                {
                    cout << "Invalid request" << endl;
                }
                
               
            }
            else if (cmd == "ADD")
            {
                string name_;
                if (ss >> name_)
                {
                    name_ = convToLower(name_);
                    unsigned int hitNum;
                    if (ss >> hitNum){
                        deque<Product*> temp;

                        map<string, deque<Product*>>::iterator it;
                        if (ds.userCarts.find(name_) == ds.userCarts.end())
                        {
                            cout << "Invalid request" << endl;
                        }
                        else
                        {
                            it = ds.userCarts.find(name_);
                            temp = it->second;
                            if (hitNum > hits.size())
                            {
                                cout << "Invalid request" << endl;
                            }
                            else
                            {
                                temp.push_back(hits[hitNum-1]);
                                it->second = temp;
                            }
                            
                        }
                        
                    }
                    else
                    {
                        cout << "Invalid request" << endl;
                    }
                }
                else
                {
                    cout << "Invalid request" << endl;
                }
                
            }
            else if (cmd == "BUYCART")
            {
                string name_;
                if (ss >> name_)
                {
                    if (ds.userList.find(name_) == ds.userList.end())
                    {
                        cout << "Invalid request" << endl;
                    }
                    else
                    {
                        map<string, User*>::iterator it = ds.userList.find(name_);
                        User* currentUser = it->second;

                        map<string, deque<Product*>>::iterator it1 = ds.userCarts.find(name_);
                        deque<Product*> currentCart = it1->second;
                    
                        double epsilon = .001f;
                        for (unsigned int i = 0; i < currentCart.size(); i++)
                        {
                            if(currentUser->getBalance() - currentCart[i]->getPrice() > epsilon)
                            {
                                if (currentCart[i]->getQty() >= 1)
                                {
                                    currentUser->deductAmount(currentCart[i]->getPrice());
                                    currentCart[i]->subtractQty(1);
                                    it1->second.pop_front();
                                
                                }
                            
                            }
                        
                        }
                    }
                    
                    
                }
                else
                {
                    cout << "Invalid request" << endl;
                }
            }



            else {
                cout << "Unknown command" << endl;
            }
        }

    }
    return 0;
}

void displayProducts(vector<Product*>& hits)
{
    int resultNo = 1;
    if (hits.begin() == hits.end()) {
    	cout << "No results found!" << endl;
    	return;
    }
    std::sort(hits.begin(), hits.end(), ProdNameSorter());
    for(vector<Product*>::iterator it = hits.begin(); it != hits.end(); ++it) {
        cout << "Hit " << setw(3) << resultNo << endl;
        cout << (*it)->displayString() << endl;
        cout << endl;
        resultNo++;
    }
}

void displayItems(deque<Product*>& cart)
{
    int resultNo = 1;
    if (cart.begin() == cart.end()) {
    	cout << "No results found!" << endl;
    	return;
    }
    //std::sort(hits.begin(), hits.end(), ProdNameSorter());
    for(deque<Product*>::iterator it = cart.begin(); it != cart.end(); ++it) {
        cout << "Item " << setw(3) << resultNo << endl;
        cout << (*it)->displayString() << endl;
        cout << endl;
        resultNo++;
    }
}

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"

using namespace std;

class Book: public Product {
    public:
        Book(const string category, const string name, double price, int qty, string isbn, 
        string author);

        ~Book();

        set<string> keywords();

        string displayString();

        void dump(ostream& os);
        
    private:
        string isbn_;
        string author_;
};
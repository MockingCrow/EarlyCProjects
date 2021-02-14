#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"

using namespace std;

class Clothing: public Product {
    public: 
        Clothing(const string category, const string name, double price, int qty, string size, 
        string brand);

        ~Clothing();

        set<string> keywords();

        string displayString();

        void dump(ostream& os);

    private:
        string size_;
        string brand_;
};
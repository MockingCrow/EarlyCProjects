#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"

using namespace std;

class Movie: public Product {
    public:
        Movie(const string category, const string name, double price, int qty, string genre, 
        string rating);

        ~Movie();

        set<string> keywords();

        string displayString();

        void dump(ostream& os);
        
    private:
        string genre_;
        string rating_;
};
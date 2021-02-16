#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"

class Movie: public Product {
    public:
        Movie(const std::string category, const std::string name, double price, int qty, std::string genre, 
        std::string rating);

        ~Movie();

        std::set<std::string> keywords();

        std::string displayString();

        void dump(std::ostream& os);
        
    private:
        std::string genre_;
        std::string rating_;
};
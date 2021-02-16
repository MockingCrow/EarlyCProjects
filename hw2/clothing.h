#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"

class Clothing: public Product {
    public: 
        Clothing(const std::string category, const std::string name, double price, int qty, std::string size, 
        std::string brand);

        ~Clothing();

        std::set<std::string> keywords();

        std::string displayString();

        void dump(std::ostream& os);

    private:
        std::string size_;
        std::string brand_;
};
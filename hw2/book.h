#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"

class Book: public Product {
    public:
        Book(const std::string category, const std::string name, double price, int qty, std::string isbn, 
        std::string author);

        ~Book();

        std::set<std::string> keywords();

        std::string displayString();

        void dump(std::ostream& os);
        
    private:
        std::string isbn_;
        std::string author_;
};
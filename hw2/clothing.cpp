#include "clothing.h"

#include "product.h"
#include "util.h"
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

Clothing::Clothing(const string category, const string name, double price, int qty, string size, string brand)
        : Product(category, name, price, qty) {
    size_ = size;
    brand_ = brand;
}

Clothing::~Clothing() {}

set<string> Clothing::keywords() const {
    set<string> keySet;
    set<string> tempSet;

    tempSet = parseStringToWords(name_);
    keySet.insert(tempSet.begin(), tempSet.end());

    tempSet = parseStringToWords(brand_);
    keySet.insert(tempSet.begin(), tempSet.end());

    return keySet;
}

string Clothing::displayString() const {
    string qtyStr = to_string(qty_);
    string priceStr = to_string(price_);
    priceStr.erase(5, 5);

    string display = name_;

    display.append("\n");
    display.append("Size: ");
    display.append(size_);
    display.append(" Brand: ");
    display.append(brand_);
    display.append("\n");
    display.append(priceStr);
    display.append(" ");
    display.append(qtyStr);
    display.append(" left.\n");

    return display;
}

void Clothing::dump(ostream& os) const {
    os << category_ << endl;
    os << name_ << endl;
    os << price_ << endl;
    os << qty_ << endl;
    os << size_ << endl;
    os << brand_ << endl;
}
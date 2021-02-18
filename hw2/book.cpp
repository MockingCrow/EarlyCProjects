#include <sstream>
#include <iomanip>
#include "product.h"
#include "book.h"
#include <string> 
#include "util.h"

using namespace std;

Book::Book(const string category, const string name, double price, int qty, string isbn, 
    string author): Product(category, name, price, qty)
{
    isbn_ = isbn;
    author_ = author;
    

}

Book::~Book()
{

}

set<string> Book::keywords() const
{
    set<string> keySet;
    set<string> tempSet;

    tempSet = parseStringToWords(name_);
    keySet.insert(tempSet.begin(), tempSet.end());
    
    tempSet = parseStringToWords(author_);
    keySet.insert(tempSet.begin(), tempSet.end());

    keySet.insert(isbn_);

    return keySet;
}

string Book::displayString() const
{
    string qtyStr = to_string(qty_);
    string priceStr = to_string(price_);
    priceStr.erase(5,5);

    string display = name_;
  
    display.append("\n");
    display.append("Author: ");
    display.append(author_);
    display.append(" ISBN: ");
    display.append(isbn_);
    display.append("\n");
    display.append(priceStr);
    display.append(" ");
    display.append(qtyStr);
    display.append(" left.\n");
    
    return display;
}

void Book::dump(ostream& os) const
{
    os << category_ << endl;
    os << name_ << endl;
    os << price_ << endl;
    os << qty_ << endl;
    os << isbn_ << endl;
    os << author_ << endl;
}
#include <sstream>
#include <iomanip>
#include "product.h"
#include "movie.h"
#include <string> 
#include "util.h"

using namespace std;

Movie::Movie(const string category, const string name, double price, int qty, string genre, 
    string rating): Product(category, name, price, qty)
{
    genre_ = genre;
    rating_ = rating;

}

Movie::~Movie()
{

}

set<string> Movie::keywords() const
{
    set<string> keySet;
    set<string> tempSet;

    tempSet = parseStringToWords(name_);
    keySet.insert(tempSet.begin(), tempSet.end());
    
    tempSet = parseStringToWords(genre_);
    keySet.insert(tempSet.begin(), tempSet.end());

    return keySet;
}

string Movie::displayString() const
{
    string qtyStr = to_string(qty_);
    string priceStr = to_string(price_);
    priceStr.erase(5,5);

    string display = name_;
  
    display.append("\n");
    display.append("Genre: ");
    display.append(genre_);
    display.append(" Rating: ");
    display.append(rating_);
    display.append("\n");
    display.append(priceStr);
    display.append(" ");
    display.append(qtyStr);
    display.append(" left.\n");
    
    return display;
}

void Movie::dump(ostream& os) const
{
    os << category_ << endl;
    os << name_ << endl;
    os << price_ << endl;
    os << qty_ << endl;
    os << genre_ << endl;
    os << rating_ << endl;
}
#include <string>
#include <set>
#include <map>
#include <vector>
#include "product.h"
#include "user.h"
#include "datastore.h"
#include <deque>

class MyDataStore: public DataStore {
    public:

        ~MyDataStore();

        void addProduct(Product* p);

        void addUser(User* u);

        std::vector<Product*> search(std::vector<std::string>& terms, int type);
        
        void dump(std::ostream& ofile);
    /*
    Every keyword for each Product will map to that Product, but there 
    will also be Products with the same keyword, thus the need for a multimap
    */
        std::multimap<std::string, Product*> productList; 
        std::map<std::string, User*> userList;
        std::map<std::string, std::deque<Product*>> userCarts;
        std::set<Product*> noRepeats;
};
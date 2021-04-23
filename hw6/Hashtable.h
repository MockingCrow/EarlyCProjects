#include <string>
#include <iostream>
#include <fstream>

class Hashtable {
    public:
        Hashtable (bool debug, unsigned int probing);
        ~Hashtable();
        void add (std::string k);
        int count (std::string k);
        void reportAll (std::ostream &) const;
        int hash (std::string k) const;

    private:
        void resize ();
        
        bool debug_;
        unsigned int probing_;
        int m;
};
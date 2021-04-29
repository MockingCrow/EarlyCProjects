#include <string>
#include <iostream>
#include <fstream>
#include <vector>

class Hashtable {
    public:
        Hashtable (bool debug, unsigned int probing);
        ~Hashtable();
        void add (std::string k);
        int count (std::string k);
        void reportAll (std::ostream &) const;

    private:
        void resize ();
        int hash (std::string k) const;
        int hashdos(std::string k) const;
        bool debug_;
        unsigned int probing_;
        int m;
        int n;
        int idx;
        int r1, r2, r3, r4, r5;
        std::pair<std::string, int> *arr;

        int sizes[28] = {11, 23, 47, 97, 197, 397, 797, 1597, 3203, 
        6421, 12853, 25717, 51437, 102877, 205759, 411527, 
        823117, 1646237, 3292489, 6584983, 13169977, 26339969, 
        52679969, 105359969, 210719881, 421439783, 842879579, 1685759167};
        int primes[28] = {7, 19, 43, 89, 193, 389, 787, 1583, 3191, 6397, 12841, 25703, 
        51431, 102871, 205721, 411503, 823051, 1646221, 3292463, 6584957, 
        13169963, 26339921, 52679927, 105359939, 210719881, 421439749, 842879563, 1685759113};
};
#include <iostream>
#include <ctime>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <map>
#include "Hashtable.h"

using namespace std;

int main(int argc, char *argv[]) {

    clock_t start;
    double duration;

    /* Preprocessing here that you don't want to time */
    if (argc != 6)
    {
        cout << "Wrong Number of Arguments" << endl;
        return -1;
    }
    int x = (int)*argv[3]-48;
    int d = (int)*argv[4]-48;
    int r = (int)*argv[5]-48;
    ifstream f;
    f.open(argv[1]);
    if (f.fail())
    {
        cout << "Failed to Open Input File" << endl;
        return -2;
    }

    string temp;
    vector<string> words;
    while (f >> temp)
    {
        for (unsigned int i = 0; i < temp.size(); i++)
        {
            if (!isalpha(temp[i]))
            {
                temp.erase(i--, 1);
            }
        }
        transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        words.push_back(temp);
    }

    start = clock();

    /* Your algorithm here */
    
    for (int i = 0; i < r; i++)
    {
        map<string, int> *wordMap = new map<string, int>();
        Hashtable *table = new Hashtable((bool)d, x);
        if (x == 3)
        {
            for (unsigned int j = 0; j < words.size(); j++)
            {
                wordMap->insert(make_pair(words[j], 1));
            }
        }
        else
        {
            for (unsigned int j = 0; j < words.size(); j++)
            {
                table->add(words[j]);
            }
        }
    }
    
    duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;

    std::cout << duration/r << endl;

    ofstream of;
    of.open(argv[2]);
    if (of.fail())
    {
        cout << "Failed to Open Output File" << endl;
        return -3;
    }
    of << "Time: " << duration/r << endl;
    if (x == 3)
    {
        map<string, int> *wordMap = new map<string, int>();
        for (unsigned int j = 0; j < words.size(); j++)
        {
            wordMap->insert(make_pair(words[j], 1));
        }
        map<string, int>::iterator it;
        for (it = wordMap->begin(); it != wordMap->end(); it++)
        {
            of << it->first << " " << it->second << endl;
        }
    }
    else
    {
        Hashtable *table = new Hashtable((bool)d, x);
        for (unsigned int j = 0; j < words.size(); j++)
        {
            table->add(words[j]);
        }
        table->reportAll(of);
    }
}

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
    int x = argv[3];
    int d = argv[4];
    int r = argv[5];
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
        for (int i = 0; i < temp.size(); i++)
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
    map<string, int> wordMap;
    Hashtable *table = new Hashtable(d, x);
    if (x == 3)
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < words.size(); j++)
            {
                wordMap.insert(words[j]);
            }
        }
    }
    else
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < words.size(); j++)
            {
                table->add(words[j]);
            }
        }
    }
    

    duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;

    std::cout << duration/r << endl;
    of.open(argv[2])
    if (of.fail())
    {
        cout << "Failed to Open Output File" << endl;
        return -3;
    }
    of << "Time: " << duration/r << endl;
    if (x == 3)
    {
        map<string, int>::iterator it;
        for (it = wordMap.begin(); it != wordMap.end(); it++)
        {
            of << it->first << " " << it->second << endl;
        }
    }
    else
    {
        table->reportAll(of);
    }
}

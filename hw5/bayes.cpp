#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
    map<string, vector<string>*> fruits;
    map<string, int> fruitSpread;
    map<string, vector<string>*>::iterator it;
    vector<string> adj;
    string temp1;
    int total;
    int numFruits;

    ifstream train;
    train.open(argv[1]); 

    if (!train.fail())
    {
        train >> numFruits;
        getline(train, temp1);

        for (int i = 0; i < numFruits; i++)
        {
            string name;
            string str;
            string temp;
            getline(train, str);
            stringstream ss(str);
            ss >> name;
            if (fruitSpread.find(name) == fruitSpread.end())
            {
                fruitSpread.insert(make_pair(name, 1));
                total++;
            }
            else
            {
                map<string, int>::iterator it1 = fruitSpread.find(name);
                it1->second++;
                total++;
            }

            if (fruits.find(name) == fruits.end())
            {
                vector<string> *vec = new vector<string>;
                fruits.insert(make_pair(name, vec));
            }
            while (ss>>temp)
            {
                it = fruits.find(name);
                it->second->push_back(temp);
            }
        }
    }
    else
    {
        cout << "Failed to open training file" << endl;
    }

    ifstream classify;
    classify.open(argv[2]);
    
    if (!classify.fail())
    {
        int numLines;
        classify >> numLines;
        getline(classify, temp1);

        for (int i = 0; i < numLine; i++)
        {   
            string str;
            string temp;
            getline(classify, str);
            stringstream ss1(str);
            while (ss1 >> temp)
            {
                
            }

        }
        
        ss1 >> 
    }
    else
    {

    }

    return 0;
}
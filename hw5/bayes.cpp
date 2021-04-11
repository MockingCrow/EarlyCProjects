#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        cout << "Wrong number of Arguments" << endl;
        return -1;
    }
    map<string, vector<string>*> fruits; //holds number of adjectives each fruit has, contains duplicate adjs
    map<string, int> fruitSpread; //holds the number of occurances of each fruit
    map<string, vector<string>*>::iterator it;
    string temp1;
    int total = 0;
    int numFruits;

    ifstream train;
    train.open(argv[1]); 

    if (!train.fail())
    {
        train >> numFruits;
        getline(train, temp1); //takes the newline after the number of fruits

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
                fruitSpread.insert(make_pair(name, 1)); //populate occurances of fruit
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
                vector<string> *vec = new vector<string>; //populate fruits
                fruits.insert(make_pair(name, vec));
            }
            while (ss>>temp)
            {
                it = fruits.find(name); //populate array of adjs
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
    ofstream output;
    output.open(argv[3]);
    
    if (!classify.fail())
    {
        int numLines;
        classify >> numLines;
        getline(classify, temp1);

        for (int i = 0; i < numLines; i++)
        {   
            double currMax = 0;
            string str;
            string temp;
            string theFruit;
            getline(classify, str);

            for (it = fruits.begin(); it != fruits.end(); it++)
            {
                stringstream ss1(str);
                double numerator = 0;
                double denominator = 0;
                double answer = 0;
                double egivenf = 1;
                double probF;
                double probnotF;
                double egivennotf = 1;
                while (ss1 >> temp)
                {
                    int num1 = 0;
                    int num2 = 0;
                    for (int i = 0; i < it->second->size(); i++)
                    {
                        if (it->second->at(i) == temp)
                        {
                            num1++;
                        }
                    }

                    map<string,int>::iterator it1 = fruitSpread.find(it->first);
                    egivenf = egivenf * (1+double(num1))/(1+double(it1->second));
                    probF = double(it1->second)/double(total);
                    probnotF = 1 - probF;

                    map<string, vector<string>*>::iterator it2;
                    for (it2 = fruits.begin(); it2 != fruits.end(); it2++)
                    {
                        if (it2->first != it->first)
                        {
                            for (int j = 0; j < it2->second->size(); j++)
                            {
                                if (it2->second->at(j) == temp)
                                {
                                    num2++;
                                }   
                            }
                        }
                    }
                    egivennotf = egivennotf * (1+double(num2))/(1+double(total - it1->second));
                }
                numerator = egivenf * probF;
                denominator = egivenf * probF + egivennotf * probnotF;
                answer = numerator/denominator;
                if (answer > currMax)
                {
                    currMax = answer;
                    theFruit = it->first;
                }
            }
            if (!output.fail())
            {
                output << theFruit << endl;
            }
            else
            {
                cout << "Failed to open output" << endl;
            }
            
        }
    }
    else
    {
        cout << "Failed to open classify" << endl;
    }
    for (it = fruits.begin(); it != fruits.end(); it++)
    {
        delete it->second;
    }
    train.close();
    classify.close();
    output.close();

    return 0;
}
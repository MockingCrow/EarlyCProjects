#include "Hashtable.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>    
#include <time.h> 
#include <fstream>
#include <cmath> 
#include <cstring>
#include <array>

using namespace std;

Hashtable::Hashtable (bool debug, unsigned int probing)
{
    debug_ = debug;
    probing_ = probing;
    m = 11;
    n = 0;
    idx = 0;
    if (debug_ == false)
    {
        srand(120239847);
        r1 = rand() % m;
        r2 = rand() % m;
        r3 = rand() % m;
        r4 = rand() % m;
        r5 = rand() % m;
    }
    else
    {
        r1 = 983132572;
        r2 = 62337998;
        r3 = 552714139;
        r4 = 984953261;
        r5 = 261934300;
    }

    for (int i = 0; i < sizes[idx]; i++)
    {
        pair<string, int>* temp = new pair<string, int>("", 0);
        arr[i] = temp;
    }
}

Hashtable::~Hashtable() {}

void Hashtable::add (string k)
{
    int num = hash(k);
    for (int i = 1; i <= m; i++)
    {
        if ((double)(n+1)/(double)m > .5)
        {
            resize();
            num = hash(k);
        }
        if (arr[num]->first == "" && arr[num]->second == 0)
        {
            pair<string, int>* temp = new pair<string, int>(k, 1);
            arr[num] = temp;
            n++;
            return;
        }
        if (arr[num]->first == k)
        {
            ++(arr[num]->second);
            return;
        }

        if (probing_ == 0)
        {
            num++;
            num = num % m;
        }
        else if (probing_ == 1)
        {
            num = (num + (i^2)) % m;
        }
        else
        {
            num = (num + i*hashdos(k)) % m;
        }
    }
}

int Hashtable::count (string k)
{
    int num = hash(k);
    for (int i = 1; i <= m; i++)
    {
        if (arr[num] == nullptr) return 0;
        if (arr[num]->first == k) return arr[num]->second;

        if (probing_ == 0)
        {
            num++;
            num = num % m;
        }
        else if (probing_ == 1)
        {
            num = (num + (i^2)) % m;
        }
        else
        {
            num = (num + i*hashdos(k)) % m;
        }
    }
    return -1;
}

void Hashtable::reportAll (ostream& of) const
{
    for (int i = 0; i < m; i++)
    {
        if (arr[i]->first != "" && arr[i]->second != 0)
        {
            of << arr[i]->first << " " << arr[i]->second << endl;
        } 
        
    }
    
}

void Hashtable::resize()
{
    ++idx;
    m = sizes[idx];
    pair<string, int> **tempArr = new pair<string, int>*[sizes[idx]];
    for (int i = 0; i < sizes[idx]; i++)
    {
        pair<string, int>* tempP1 = new pair<string, int>("", 0);
        tempArr[i] = tempP1;
    }

    for (int i = 0; i < sizes[idx-1]; i++)
    {
        if (arr[i]->first != "" && arr[i]->second != 0)
        {
    
            int num = hash(arr[i]->first);
            for (int j = 1; j <= m; j++)
            {
                if (tempArr[num]->first == "" && tempArr[num]->second == 0)
                {
                    pair<string, int>* temp = new pair<string, int>(arr[i]->first, arr[i]->second);
                    tempArr[num] = temp;
                    break;
                }
                else if (tempArr[num]->first == arr[i]->first)
                {
                    ++(tempArr[num]->second);
                    break;
                }

                if (probing_ == 0)
                {
                    num++;
                    num = num % m;
                }
                else if (probing_ == 1)
                {
                    num = (num + (i^2)) % m;
                }
                else
                {
                    num = (num + i*hashdos(arr[i]->first)) % m;
                }
            }
        }
    } 
    for (int i = 0; i < sizes[idx-1]; i++)
    {
        delete arr[i];
    }
    delete [] arr;
    arr = tempArr;
}

int Hashtable::hash (string k) const
{
    int iter = 1;
    vector<int> w;
    int j = 0;
    int total = 0;
    int start = k.size()-1;
    if (k.size() < (unsigned int)6*iter)
    {
        for (int i = start; i >= 0; i--)
        {
            total += pow(26, j) * (k[i]-97);
            j++;
        }
    }
    else
    {
        for (int i = start; i > start-6; i--)
        {
            total += pow(26, j) * (k[i]-97);
            j++;
        }
    }
    w.push_back(total);
    iter++;
    j = 0;
    total = 0;

    if (k.size() < (unsigned int)6*iter)
    {
        for (int i = start - 6*(iter-1); i >= 0; i--)
        {
            total += pow(26, j) * (k[i]-97);
            j++;
        }
    }
    else
    {
        for (int i = start - 6*(iter-1); i > start - 6*(iter); i--)
        {
            total += pow(26, j) * (k[i]-97);
            j++;
        }
    }
    w.push_back(total);
    iter++;
    j = 0;
    total = 0;

    if (k.size() < (unsigned int)6*iter)
    {
        for (int i = start - 6*(iter-1); i >= 0; i--)
        {
            total += pow(26, j) * (k[i]-97);
            j++;
        }
    }
    else
    {
        for (int i = start - 6*(iter-1); i > start - 6*(iter); i--)
        {
            total += pow(26, j) * (k[i]-97);
            j++;
        }
    }
    w.push_back(total);
    iter++;
    j = 0;
    total = 0;

    if (k.size() < (unsigned int)6*iter)
    {
        for (int i = start - 6*(iter-1); i >= 0; i--)
        {
            total += pow(26, j) * (k[i]-97);
            j++;
        }
    }
    else
    {
        for (int i = start - 6*(iter-1); i > start - 6*(iter); i--)
        {
            total += pow(26, j) * (k[i]-97);
            j++;
        }
    }
    w.push_back(total);
    iter++;
    j = 0;
    total = 0;

    if (k.size() < (unsigned int)6*iter)
    {
        for (int i = start - 6*(iter-1); i >= 0; i--)
        {
            total += pow(26, j) * (k[i]-97);
            j++;
        }
    }
    else
    {
        for (int i = start - 6*(iter-1); i > start - 6*(iter); i--)
        {
            total += pow(26, j) * (k[i]-97);
            j++;
        }
    }
    w.push_back(total);

    long long n1, n2, n3, n4, n5;
    n1 = (long long)r1*(long long)w[4];
    n2 = (long long)r2*(long long)w[3];
    n3 = (long long)r3*(long long)w[2];
    n4 = (long long)r4*(long long)w[1];
    n5 = (long long)r5*(long long)w[0];
    int answer = (n1 + n2 + n3 + n4 + n5) % m;
    return answer;
}


int Hashtable::hashdos(std::string k) const
{
    int iter = 1;
    vector<int> w;
    int j = 0;
    int total = 0;
    int start = k.size()-1;
    if (k.size() < (unsigned int)6*iter)
    {
        for (int i = start; i >= 0; i--)
        {
            total += pow(26, j) * (k[i]-97);
            j++;
        }
    }
    else
    {
        for (int i = start; i > start-6; i--)
        {
            total += pow(26, j) * (k[i]-97);
            j++;
        }
    }
    w.push_back(total);
    iter++;
    j = 0;
    total = 0;

    if (k.size() < (unsigned int)6*iter)
    {
        for (int i = start - 6*(iter-1); i >= 0; i--)
        {
            total += pow(26, j) * (k[i]-97);
            j++;
        }
    }
    else
    {
        for (int i = start - 6*(iter-1); i > start - 6*(iter); i--)
        {
            total += pow(26, j) * (k[i]-97);
            j++;
        }
    }
    w.push_back(total);
    iter++;
    j = 0;
    total = 0;

    if (k.size() < (unsigned int)6*iter)
    {
        for (int i = start - 6*(iter-1); i >= 0; i--)
        {
            total += pow(26, j) * (k[i]-97);
            j++;
        }
    }
    else
    {
        for (int i = start - 6*(iter-1); i > start - 6*(iter); i--)
        {
            total += pow(26, j) * (k[i]-97);
            j++;
        }
    }
    w.push_back(total);
    iter++;
    j = 0;
    total = 0;

    if (k.size() < (unsigned int)6*iter)
    {
        for (int i = start - 6*(iter-1); i >= 0; i--)
        {
            total += pow(26, j) * (k[i]-97);
            j++;
        }
    }
    else
    {
        for (int i = start - 6*(iter-1); i > start - 6*(iter); i--)
        {
            total += pow(26, j) * (k[i]-97);
            j++;
        }
    }
    w.push_back(total);
    iter++;
    j = 0;
    total = 0;

    if (k.size() < (unsigned int)6*iter)
    {
        for (int i = start - 6*(iter-1); i >= 0; i--)
        {
            total += pow(26, j) * (k[i]-97);
            j++;
        }
    }
    else
    {
        for (int i = start - 6*(iter-1); i > start - 6*(iter); i--)
        {
            total += pow(26, j) * (k[i]-97);
            j++;
        }
    }
    w.push_back(total);

    int answer = primes[idx] - ((w[4]+w[3]+w[2]+w[1]+w[0]) % primes[idx]);
    return answer;
}



#include "Hashtable.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>    
#include <time.h> 
#include <fstream>
#include <cmath> 

using namespace std;

Hashtable::Hashtable (bool debug, unsigned int probing)
{
    debug_ = false;
    probing_ = 0;
    m = 11;
    n = 0;
    idx = 0;
    *arr = new pair<string, int>[11];
}

Hashtable::~Hashtable() {}

void Hashtable::add (string k)
{
    int num = hash(k);
    for (int i = 1; i <= m; i++)
    {
        if ((double)(n+1)/(double)m > .5) resize();
        if (arr[num] == nullptr)
        {
            *arr[num] = pair<string, int>(k, 1);
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
            num = (num + i*hashdos(k, idx)) % m;
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
            num = (num + i*hashdos(k, idx)) % m;
        }
    }
}

void Hashtable::reportAll (ostream &) const
{
    for (int i = 0; i < m; i++)
    {
        ostream << arr[i]->first << " " << arr[i]->second << "\n";
    }
    
}

void Hashtable::resize()
{
    ++idx;
    *arr = pair<string, int>[sizes[idx]];
    m = sizes[idx];
    for (int i = 0; i < sizes[idx-1]; i++)
    {
        if (arr[i] != nullptr)
        {
            string temp = arr[i]->first;
            delete arr[i];
            arr[i] = nullptr;
            add(temp);   
        }
    } 
}

int Hashtable::hash (string k) const
{
    int r1, r2, r3, r4, r5;
    int iter = 1;
    vector<int> w;
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


int Hashtable::hashdos(std::string k, int idx) const
{
    int r1, r2, r3, r4, r5;
    int iter = 1;
    vector<int> w;
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



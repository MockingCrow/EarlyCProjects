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
    debug_ = true;
    probing_ = 0;
    m = 11;
}

Hashtable::~Hashtable() {}

void Hashtable::add (string k)
{

}

int Hashtable::count (string k)
{

}

void Hashtable::reportAll (ostream &) const
{

}

void Hashtable::resize()
{

}

int Hashtable::hash (string k) const
{
    int r1, r2, r3, r4, r5;
    vector<int> w;
    int iter = 1;
    if (debug_ == false)
    {
        srand(time(NULL));
        r1 = rand() % m;
        cout << r1 << endl;
        r2 = rand() % m;
        cout << r2 << endl;
        r3 = rand() % m;
        cout << r3 << endl;
        r4 = rand() % m;
        cout << r4 << endl;
        r5 = rand() % m;
        cout << r5 << endl;
        cout << m << endl;
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
    if (k.size() < 6*iter)
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

    if (k.size() < 6*iter)
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

    if (k.size() < 6*iter)
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

    if (k.size() < 6*iter)
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

    if (k.size() < 6*iter)
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
    n1 = (r1*w[4]);
    n2 = (r2*w[3]);
    n3 = (r3*w[2]);
    n4 = (r4*w[1]);
    n5 = (long long)r5* (long long)w[0];
    cout << w[0] << " " << r5 << " " << n5 << endl;
    int answer = (n1 + n2 + n3 + n4 + n5) % m;
    cout << answer << endl;
}



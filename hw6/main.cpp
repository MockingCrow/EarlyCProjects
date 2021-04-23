#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>    
#include <time.h> 
#include "Hashtable.h"


int main()
{
    std::string k = "zzyyxx";
    Hashtable* table = new Hashtable(false, 0);
    int num = table->hash(k);
}
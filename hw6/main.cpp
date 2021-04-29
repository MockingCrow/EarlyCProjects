#include "Hashtable.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>    
#include <time.h> 
#include <fstream>
#include <cmath> 

using namespace std;

int main ()
{
    Hashtable table(true, 2);
    table.add("hi");
    table.add("hi");
    table.add("rutebega");
    table.add("rutebega");
    table.add("rutebega");
    table.add("penepolperetegeba");
    table.add("estatos");
    table.add("p");
    table.add("ello");
    table.add("tumadre");
    table.add("antidisestablishmentarianism");
    table.add("sdflk");
    table.add("eeeehhhhsl");
    table.add("marisha");
    table.add("marisha");
    table.add("marisha");
    table.add("marisha");
    table.add("sdf");
    table.add("asdf");
    table.add("testingtesting");
    table.count("hi");
    table.reportAll(cout);
}
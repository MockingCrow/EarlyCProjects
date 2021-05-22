#include <iostream>
#include <fstream>
#include <string>
#include "Color.h"

using namespace std;

int main (int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Wrong number of arguments" << endl;
        return -1;
    }

    ifstream f;
    f.open(argv[1]);
    if (f.fail())
    {
        cout << "Failed to read argument" << endl;
        return -2;
    }

    int numCountries;
    f >> numCountries;
    int rows;
    f >> rows;
    int cols;
    f >> cols;
    
    char **input = new char*[rows];
    for (int i = 0; i < rows; i++)
    {
        input[i] = new char[cols];
    }

    string temp;
    getline(f, temp);
    for (int i = 0; i < rows; i++)
    {
        
        getline(f, temp);
        int k = 0;

        for (int j = 0; j < cols; j++)
        {
            input[i][j] = temp[k];
            k++;
        }
    }

    Color test(rows, cols, numCountries, input);
    test.findColors();
    test.printColors();



    return 0;
}

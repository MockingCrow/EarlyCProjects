#include "Color.h"
#include <iostream>
#include <string>

using namespace std;

Color::Color(int rows, int cols, int numCountries, char **input)
{
    rows_ = rows;
    cols_ = cols;
    numCountries_ = numCountries;

    map = new char*[rows_];
    for (int i = 0; i < rows_; i++)
    {
        map[i] = new char[cols_];
    }

    for (int i = 0; i < rows_; i++)
    {
        for (int j = 0; j < cols_; j++)
        {
            map[i][j] = input[i][j];
        }
    }

    adjacencies = new bool*[numCountries_];
    for (int i = 0; i < numCountries_; i++)
    {
        adjacencies[i] = new bool[numCountries_];
    }

    mapColors = new int[numCountries_];

    for (int i = 0; i < numCountries_; i++)
    {
        for (int j = 0; j < numCountries_; j++)
        {
            adjacencies[i][j] = false;
        }
        mapColors[i] = 0;
    }

    int temp1;
    int temp2; 
    for (int i = 0; i < rows_; i++)
    {
        for (int j = 0; j < cols_; j++)
        {
            if (i != 0)
            {
                if (map[i-1][j] != map[i][j])
                {
                    temp1 = map[i-1][j] - 65;
                    temp2 = map[i][j]-65;
                    adjacencies[temp1][temp2] = true;
                    adjacencies[temp2][temp1] = true;
                }
            }
            if (i != rows-1)
            {
                if (map[i+1][j] != map[i][j])
                {
                    temp1 = (int)map[i+1][j] - 65;
                    temp2 = (int)map[i][j]-65;
                    adjacencies[temp1][temp2] = true;
                    adjacencies[temp2][temp1] = true;
                }
            }
            if (j != cols-1)
            {
                if (map[i][j+1] != map[i][j])
                {
                    temp1 = (int)map[i][j+1] - 65;
                    temp2 = (int)map[i][j]-65;
                    adjacencies[temp1][temp2] = true;
                    adjacencies[temp2][temp1] = true;
                }
            }
            if (j != 0)
            {
                if (map[i][j-1] != map[i][j])
                {
                    temp1 = (int)map[i][j-1] - 65;
                    temp2 = (int)map[i][j]-65;
                    adjacencies[temp1][temp2] = true;
                    adjacencies[temp2][temp1] = true;
                }
            }
        }
    }
   
}

Color::~Color() {}

void Color::findColors()
{
    colorHelper('A');
}

void Color::printColors()
{
    for (int i = 0; i < numCountries_; i++)
    {
        cout << char(i+65) << " " << mapColors[i] << endl;
    }
}

bool Color::isValid()
{
    for (int i = 0; i < numCountries_; i++)
    {
        for (int j = 0; j < numCountries_; j++)
        {
            if (mapColors[i] != 0 && mapColors[j] != 0)
            {
                if ((mapColors[i] == mapColors[j]) && adjacencies[i][j] == true)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

bool Color::colorHelper(char country)
{
    if((int)country > numCountries_+64)
    {
        
        return true;
    }

    for (int c = 1; c <= 4; c++)
    {
        for (int i = 0; i < rows_; i++)
        {
            for (int j = 0; j < cols_; j++)
            {
                if (map[i][j] == country)
                {
                    mapColors[country-65] = c;
                }
            }
        }
        if (isValid())
        {
            if (colorHelper((char)(country+1)) == true)
            {
                return true;
            }
        }
        
    }
    mapColors[country-65] = 0;
    return false;
    
}


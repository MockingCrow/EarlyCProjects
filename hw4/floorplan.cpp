#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include "avlbst.h"
#include <map>

using namespace std;

struct Rectangle
{
    int ID;
    int length;
    int height;
};

// Typedefs for you input and output map. Start with
// std::map but once the backtracking search algorithm is working
// try to use your AVL-tree map implementation by changing these
// typedef's
typedef std::map<int, Rectangle> InputMapType;
typedef std::map<int, std::pair<int, int> > OutputMapType;

// Allowed global variables: the dimensions of the grid
int n; // X-dim size
int m; // Y-dim size

// No other global variables are allowed

// A dummy operator << for Rectangles so the BST and AVL BST will
// compile with their printRoot() implementations
std::ostream& operator<<(std::ostream& os, const Rectangle& r)
{
    os << r.ID;
    return os;
}

// A dummy operator << for pairs so the BST and AVL BST will
// compile with their printRoot() implementations
template <typename T, typename U>
std::ostream& operator<<(std::ostream& os, const std::pair<T,U>& p)
{
    os << p.first << "," << p.second;
    return os;
}



void printSolution(std::ostream& os, InputMapType& input, OutputMapType& output)
{
    for (OutputMapType::iterator it = output.begin(); it != output.end(); ++it)
    {
        InputMapType::iterator rbit = input.find(it->first);
        os << it->first << " ";
        os << it->second.first << " ";
        os << it->second.second << " ";
        os << rbit->second.length << " ";
        os << rbit->second.height << endl;
    }
}

// Changes the grid entries to their opposite values for the
// rectangle r starting at x1,y1
void flip(int x1, int y1, const Rectangle& r, vector<vector<bool> >& grid)
{
    for (int x = x1; x < x1+r.length; x++)
    {
        for (int y = y1; y < y1+r.height; y++) grid[x][y] = !grid[x][y];
    }
}

bool isValid(int x, int y, int length, int height, vector<vector<bool>> grid)
{
    cout << x << endl;
    cout << y << endl;
    cout << endl;
    for (int i = x; i < x+length; i++)
    {
        for (int j = y; j < y+height; j++)
        {
            if (grid[i][j] == true)
            {
                return false;
            }
        }
    }
    return true;
}

bool search(InputMapType input, OutputMapType output,  vector<vector<bool> > grid, 
InputMapType::iterator it, InputMapType::iterator it1)
{
    if (it == it1)
    {
        cout << "end case" << endl;
        return true;
    }
    
    for (int i = 0; i <= n - it->second.length; i++)
    {
        for (int j = 0; j <= m - it->second.height; j++)
        {
            
            if (isValid(i, j, it->second.length, it->second.height, grid))
            {
                cout << "such" << endl;
                flip(i, j, it->second, grid);
                
                if (search(input, output, grid, ++it, it1) == true)
                {
                    return true;
                }
            }
            else if (isValid(i, j, it->second.height, it->second.length, grid))
            {
                cout << "such" << endl;
                swap(it->second.height, it->second.length); 
                flip(i, j, it->second, grid);
                if (search(input, output, grid, ++it, it1) == true)
                {
                    return true;
                }
            }
        }
    }
    return false;
    
}

int main(int argc, char *argv[])
{
    if (argc < 3) {
        cout << "please specify an input and output file";
        return 0;
    }
    ifstream ifile(argv[1]);
    stringstream ss;
    string line;
    ofstream ofile(argv[2]);
    int x;
    getline(ifile, line);
    ss << line;
    ss >> n;
    ss >> m;
    ss >> x;

    InputMapType input;
    OutputMapType output;
    for (int i = 0; i < x; i++) {
        getline(ifile, line);
        stringstream ss2(line);
        Rectangle r;
        ss2 >> r.ID;
        ss2 >> r.length;
        ss2 >> r.height;
        input.insert(std::make_pair(r.ID, r));
    }
    ifile.close();
    vector<vector<bool> > grid;

    for (int i = 0; i < n; i++)
    {
        grid.push_back(vector<bool>(m, false));
    }
    InputMapType::iterator it = input.begin();
    InputMapType::iterator it1 = input.end();
    bool solution_exists = false;

    if (search(input, output, grid, it, it1) == true)
    {
        solution_exists = true;
    }

    if (!solution_exists) {
        ofile << "No solution found.";
    }
    else {
        printSolution(ofile, input, output);
    }
    ofile.close();
    return 0;
}
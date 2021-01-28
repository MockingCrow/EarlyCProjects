/* Write your test code for the ULListStr in this file */
#include "ulliststr.h"
#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{
  ULListStr test_list;
  test_list.push_back("1");
  test_list.push_back("2");
  test_list.push_back("3");

  cout << test_list.get(0) << " " << test_list.get(1) << " " << test_list.get(2) << endl;

  return 0;
}

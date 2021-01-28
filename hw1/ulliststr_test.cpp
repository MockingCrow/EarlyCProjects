/* Write your test code for the ULListStr in this file */
#include "ulliststr.h"
#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{
  ULListStr test_list;
  
  /*
  Testing push_back and get/getValAtLoc.
  First populated a list greater that ARRSIZE then used
  get to check that the list is created properly (including new Items)
  */

  test_list.push_back("1");
  test_list.push_back("2");
  test_list.push_back("3");
  test_list.push_back("4");
  test_list.push_back("5");
  test_list.push_back("6");
  test_list.push_back("7");
  test_list.push_back("8");
  test_list.push_back("9");
  test_list.push_back("10");
  test_list.push_back("11");
  test_list.push_back("12");

  //change the indexes to whatever values you want to check
  cout << test_list.get(0) << " " << test_list.get(10) << " "
  << test_list.get(11) << endl; 

  return 0;
}

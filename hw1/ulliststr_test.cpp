/* Write your test code for the ULListStr in this file */
#include "ulliststr.h"
#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{
  ULListStr test_list;
  
  /*
  PUSH_BACK TEST/GET TEST
  */

  cout << "TESTING PUSH_BACK AND GET" << endl;

  test_list.push_back("1"); //this tests the empty list case
  cout << "empty case: " << test_list.get(0) << endl;
  cout << "size: " << test_list.size() << endl;

  test_list.push_back("2");//the following is for a non empty list case
  test_list.push_back("3");
  test_list.push_back("4");
  test_list.push_back("5");
  test_list.push_back("6");
  test_list.push_back("7");
  test_list.push_back("8");
  test_list.push_back("9");
  test_list.push_back("10");//edge case
  test_list.push_back("11");//edge case
  test_list.push_back("12");

  cout << "border and end case: " << test_list.get(9) << " "
  << test_list.get(10) << " " << test_list.get(11) << endl;

  cout << "final size: " << test_list.size() << endl; //check size


  /*
  TEST SET FUNCTION
  */ 
  cout << endl;
  cout << "TESTING SET:" << endl;
  test_list.set(5, "number six");
  test_list.set(9, "number ten");
  cout << test_list.get(5) << " " << test_list.get(9) >> endl;

  test_list.clear(); //clear list


  /*
  PUSH_FRONT TEST
  */
  
  cout << endl;
  cout << "TESTING PUSH_FRONT" << endl;

  test_list.push_front("1"); //empty list case
  cout << "empty case: " << test_list.get(0) << endl;
  cout << "size: " << test_list.size() << endl; //check size

  test_list.push_front("2");
  test_list.push_front("3");
  test_list.push_front("4");
  test_list.push_front("5");
  test_list.push_front("6");
  test_list.push_front("7");
  test_list.push_front("8");
  test_list.push_front("9");
  test_list.push_front("10"); //edge case
  test_list.push_front("11"); //edge case
  test_list.push_front("12");
  cout << test_list.size() << endl; //check size
  
  //check first item and border cases
  cout << "border and edge cases: ";
  cout << test_list.get(0) << " " << test_list.get(9) << " "
  << test_list.get(10) << endl; 


  

  return 0;
}

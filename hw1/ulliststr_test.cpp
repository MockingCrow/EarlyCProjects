/* Write your test code for the ULListStr in this file */
#include "ulliststr.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    ULListStr test_list;

    /*
    PUSH_BACK TEST/GET TEST
    */

    cout << "TESTING PUSH_BACK AND GET" << endl;

    test_list.push_back("1");  // this tests the empty list case
    cout << "empty case: " << test_list.get(0) << endl;
    cout << "size: " << test_list.size() << endl;

    test_list.push_back("2");  // the following is for a non empty list case
    test_list.push_back("3");
    test_list.push_back("4");
    test_list.push_back("5");
    test_list.push_back("6");
    test_list.push_back("7");
    test_list.push_back("8");
    test_list.push_back("9");
    test_list.push_back("10");  // edge case
    test_list.push_back("11");  // edge case
    test_list.push_back("12");

    // check border and edge cases
    cout << "last 3 items: " << test_list.get(9) << " " << test_list.get(10) << " " << test_list.get(11)
         << endl;

    cout << "final size: " << test_list.size() << endl;  // check size

    /*
    SET FUNCTION TEST
    */
    cout << endl;
    cout << "TESTING SET:" << endl;
    cout << "Changing index 5 and 9" << endl;
    test_list.set(5, "number six");
    test_list.set(9, "number ten");
    cout << test_list.get(5) << " " << test_list.get(9) << endl;

    /*
    PUSH_FRONT TEST
    */

    ULListStr test_list2;
    // ULListStr test_list2;

    cout << endl;
    cout << "TESTING PUSH_FRONT" << endl;

    test_list2.push_front("1");  // empty list case
    cout << "empty case: " << test_list2.get(0) << endl;
    cout << "size: " << test_list2.size() << endl;  // check size

    test_list2.push_front("2");
    test_list2.push_front("3");
    test_list2.push_front("4");
    test_list2.push_front("5");
    test_list2.push_front("6");
    test_list2.push_front("7");
    test_list2.push_front("8");
    test_list2.push_front("9");
    test_list2.push_front("10");  // edge case
    test_list2.push_front("11");  // edge case
    test_list2.push_front("12");

    // check first item and border cases
    cout << "border and edge cases: ";
    cout << test_list2.get(0) << " " << test_list2.get(9) << " " << test_list2.get(10) << endl;

    cout << "final size: " << test_list2.size() << endl;  // check size

    /*
    POP_BACK TEST
    */

    cout << endl;
    cout << "TESTING POP BACK" << endl;
    cout << "adding extra1 then extra2 to back of list" << endl;
    test_list2.push_back("extra1");
    test_list2.push_back("extra2");

    cout << "Initial size: " << test_list2.size() << endl;
    test_list2.pop_back();
    unsigned int size = test_list2.size();
    cout << "size: " << test_list2.size() << endl;
    cout << "last item: " << test_list2.get(size - 1) << endl;

    cout << "Checking deletion case" << endl;
    test_list2.pop_back();
    size = test_list2.size();
    cout << "size: " << test_list2.size() << endl;
    cout << "last item: " << test_list2.get(size - 1) << endl;

    /*
    POP_FRONT TEST
    */

    cout << endl;
    cout << "TESTING POP FRONT" << endl;

    cout << "Initial size: " << test_list2.size() << endl;
    test_list2.pop_front();
    cout << "size: " << test_list2.size() << endl;
    cout << "last item: " << test_list2.get(0) << endl;

    cout << "Checking deletion case" << endl;
    test_list2.pop_front();
    cout << "size: " << test_list2.size() << endl;
    cout << "last item: " << test_list2.get(0) << endl;

    /*
    BACK AND FRONT TEST
    */

    cout << endl;
    cout << "TESTING BACK" << endl;
    cout << "expected: 1" << endl;
    cout << test_list2.back() << endl;

    cout << "TESTING FRONT" << endl;
    cout << "expected: 10" << endl;
    cout << test_list2.front() << endl;

  
    return 0;
}

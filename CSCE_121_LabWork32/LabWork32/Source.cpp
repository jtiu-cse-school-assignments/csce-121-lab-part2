#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    /* Populate a vector container and a set container*/
    vector<int> fibvec = {1, 1, 2, 3, 5, 8, 13, 21, 34};
    set<int> lucasset = {2, 1, 3, 4, 7, 11, 18, 29, 47};

    /* You are to iterate through the provided vector and set
       containers and print the values contained in them.
       You will do so first in a familiar way, then using the
       new concept of iterators.

       Note: Print the values separated by a comma and a space,
             and add a couple of newlines after completing
    */

    // FIXME: Iterate through vector using a standard for (int i...) loop
    for (int i = 0; i < fibvec.size(); i++) {
        cout << fibvec.at(i) << ", ";
    }
    
    cout << endl;

    
    // FIXME: Iterate through vector using iterators
    for (vector<int>::iterator i = fibvec.begin(); i != fibvec.end(); i++) {
        cout << *i << ", ";
    }
    
    cout << endl;

    
    // FIXME: Iterate through set using iterators
    for (set<int>::iterator i = lucasset.begin(); i != lucasset.end(); i++) {
        cout << *i << ", ";
    }

    cout << endl;

}
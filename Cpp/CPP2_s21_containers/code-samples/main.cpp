#include <iostream>
#include "testVector.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
    Vector<int> v = {1, 2, 3, 4, 5};
    v.push_back(6);
    for (int i = 0; i < v.size(); i++) {
       std::cout << v.at(i); 
    }
}

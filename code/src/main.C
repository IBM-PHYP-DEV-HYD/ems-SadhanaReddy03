#include <iostream>
#include "ExtendedDeque.H"
using namespace std;

void testInsert() {
    ExtendedDeque<int> dq;
    dq.pushBack(10);
    dq.pushBack(20);
    dq.pushBack(30);
    dq.insertAt(0, 5);
    dq.display(); cout << endl;
    dq.insertAt(2, 15);
    dq.display(); cout << endl;
    dq.insertAt(dq.size(), 40);
    dq.display(); cout << endl;
}

void testRemove() {
    ExtendedDeque<int> dq;
    dq.pushBack(10);
    dq.pushBack(20);
    dq.pushBack(30);
    dq.pushBack(40);
    dq.removeAt(0);
    dq.display(); cout << endl;
    dq.removeAt(dq.size()-1);
    dq.display(); cout << endl;
    dq.removeAt(1);
    dq.display(); cout << endl;
}

int main() {

    testInsert();
    testRemove();

    return 0;
}
#include "linked_list.h"
#include <iostream>

using namespace std;
using namespace linked_lists;

int main() {
    LinkedList list;
    list.push_front(15);
    list.push_front(20);
    list.push_front(25);

    cout << list.contains(20) << endl;
    cout << list.contains(17) << endl;
}
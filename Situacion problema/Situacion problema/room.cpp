#include <iostream>
#include "room.h"
using namespace std;

ostream& operator<<(ostream& os, const Room& room) {
    os << "con: " << room.monster << endl;
    return os;
}
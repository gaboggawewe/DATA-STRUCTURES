#include <iostream>
#include "room.h"
using namespace std;

ostream& operator<<(ostream& os, const Room& room) {
    os << "Cuarto con: " << room.monster << endl;
    return os;
}
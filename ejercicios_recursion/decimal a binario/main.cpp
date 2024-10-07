#include <iostream>
using namespace std;

int convert(int decimal){
    if (decimal == 0){
        return 0;
    }
    else{
        return (decimal%2) + 10 * convert(decimal/2);
    }
}

int main(){
    int resultado = convert(13);
    cout << resultado;
    return 0;
}
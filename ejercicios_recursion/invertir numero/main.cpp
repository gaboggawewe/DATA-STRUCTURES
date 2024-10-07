#include <iostream>
using namespace std;

int invertir(int numero){
    if (numero == 1){
        return 1;
    }
    else{
        return invertir(numero/10)+invertir(numero/10)%10;
    }
}

int main(){
    int resultado = invertir(12345);
    cout<<resultado;
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;



int main(){
    int n = 0;
    cin >> n;
    vector<int> datos(n);
    for (int i = 0; i < n; i++){
        int num = 0;
        cin>>num;
        datos[i] = num;
    }
    
    vector<int> acumulado(n);
    for (int i = 1; i <= n; i++){
        acumulado[i] = acumulado[i-1] + datos[i-1];
    }
    for(int j = 0; j<n ; j++){
        for (int i = n; i>j; i--){
            if (acumulado[i]%7 == 0){
                int posicion = i;
                break;
            }
        }
    }


    for (int i = 0; i<n; i++){
        cout << datos[i];
        cout << acumulado[i];
    }
}
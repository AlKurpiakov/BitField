#include "set.h"

int main(){
    uint64_t N;
    cin >> N;
    Set sett(N + 1);
    for (uint64_t i = 0; i < N + 1; i++){
        //sett.InsElem(i);
    }
    vector <uint64_t> simple;

    simple = sett.GetPriority();
    for (uint64_t i = 0; i < simple.size(); i++){
        cout << simple[i];
    }  
}

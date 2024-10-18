#include "set.h"

int main(){
    int N;
    cin >> N;
    Set sett(N + 1);
    for (int i = 0; i < N + 1; i++){
        sett.InsElem(i);
    }
    vector <uint64_t> simple;
    simple = sett.GetPriority();
    for (int i = 0; i < simple.size(); i++){
        cout << simple[i];
    }  
}

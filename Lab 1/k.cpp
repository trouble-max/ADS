//

#include <iostream>
#include <math.h>

using namespace std;

bool is_prime(int x){
    if(x <= 1) return false;
    for(int i = 2; i <= sqrt(x); i++){
        if(x % i == 0) return false;
    } return true;
}

int main(){
    int x;

    cin >> x;

    cout << (is_prime(x) ? "prime" : "composite");

    return 0;
}
//

#include <iostream>

using namespace std;

int main(){
    int x, y, d, r, curr, m1, m2;

    cin >> x >> y;

    m1 = (x > y) ? x : y;
    m2 = (x > y) ? y : x;

    r = m1 % m2;

    while(r != 0){
        d = m1 / m2;
        curr = m1 - m2 * d;
        m1 = m2;
        m2 = r;
        r = m1 % m2;
    }

    cout << m2;

    return 0;
}
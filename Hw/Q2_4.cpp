#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

bool isPrime(int n) {
    for(int i = 2; i <= (int)sqrt(n); i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int main(void) {
    cout << "The prime number in 3~100 : " << endl;
    for(int i = 3; i <= 100; i++) {
        if(isPrime(i)) {
            cout << i << " ";
        }
    }
    system("pause");
    return 0;
}

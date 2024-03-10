#include <iostream>
#include <stdlib.h>
using namespace std;

int main(void) {
    for(int T = 0; T < 10; T++) {
        for(int O = 0; O < 10; O++) {
            for(int G = 0; G < 10; G++) {
                for(int D = 0; D < 10; D++) {
                    if(T != O && T != G && T != D && O != G && O != D && G != D) {
                        if(4 * (100 * T + 10 * O + O) == 1000 * G + 100 * O + 10 * O + D) {
                            cout << "T = " << T << ", O = " << O << ", G = " << G << ", D = " << D << endl;
                        }
                    }
                }
            }
        }
    }
    system("pause");
    return 0;
}

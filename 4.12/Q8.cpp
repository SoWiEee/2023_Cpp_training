
#include <iostream>
using namespace std;


int main()
{
    int birth[50];
    bool same[10000];
    double probability,sum;

    

    for (int p = 2; p <= 50; p++)
    {
        probability = 0;
        sum = 0;
        for (int c = 0; c < 10000; c++)
        {
            same[c] = 0;
        }

        for (int t = 0; t < 10000; t++)
        {
            for (int i = 0; i < 50; i++)
            {
                birth[i] = rand() % 365 + 1;
            }
            for (int j = 0; j < p - 1; j++)
            {
                for (int k = j + 1; k < p; k++)
                {
                    if (birth[j] == birth[k])
                    {
                        same[t] = 1;
                    }
                }
            }
            
        }
        for (int c = 0; c < 10000; c++)
        {
            sum += same[c];
        }
        probability = sum / 10000;
        cout << "For " << p << " people, the probability of two birthday is about " << probability<<"\n";
       

    }


    system("PAUSE");
    return 0;
}


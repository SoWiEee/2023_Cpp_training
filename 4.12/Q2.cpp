
#include <iostream>
using namespace std;


void deleteRepeats(char a[], int &size)
{
    for (int i = 0; i < size-1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (a[i] == a[j])
            {
                for (int k = j; k < size; k++)
                {
                    a[k] = a[k + 1];
                }
                size--;
                j--;
            } 
        } 
    }
}

int main()
{
    char array[500] = "Mary had a little lamb. its fleece was white as snow. Now is the time for all good men to come to the aid of the country.";
    int size = 0;


    size = strlen(array);
    for (int i = 0; i < size; i++)
    {
        cout << array[i];
    }
 
    cout << "\n";
    cout << "The size of the array is "<<size << ".\n";
    deleteRepeats(array, size);
    cout << "The array after delete the same letter is=>\n";
    for (int i = 0; i < size; i++)
    {
        cout << array[i];
    }
    cout << "\nThe size of the array is " << size << ".\n";


    system("PAUSE");
    return 0;
}

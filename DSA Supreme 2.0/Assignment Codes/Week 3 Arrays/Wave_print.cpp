#include <iostream>
using namespace std;
void waveprint(int arr[][5], int n, int m)
{
    for (int i = 0; i < m; i++)
    {
        if (i & 1)
        {
            for (int j = n - 1; j <= 0; j--)
            {
                cout << arr[j][i];
            }
        }
        else
        {
            for (int j = 1; j < n; j++)
            {
                cout << arr[j][i];
            }
        }
    }
}

    int main()
    {
        int arr[4][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}};
        waveprint(arr, 4, 5);

        return 0;
    }
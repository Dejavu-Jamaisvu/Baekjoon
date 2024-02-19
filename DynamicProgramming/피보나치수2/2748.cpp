#include <iostream>
#include <vector>

using namespace std;

// int fibonacci(int n)
// {
//     if (n == 0)
//     {
//         return 0;
//     }
//     else if (n == 1)
//     {
//         return 1;
//     }
//     else
//     {
//         return fibonacci(n - 1) + fibonacci(n - 2);
//     }
// }

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 0번째 피보나치 수는 0이고, 1번째 피보나치 수는 1
    int n; // 구하는 피보나치 수. 몇번째 피보나치 수 인가.

    cin >> n;

    // vector<int> arr;
    long long arr[n]; //n이 90일 때 2880067194370816120이 나올 수 있어야 함.

    for (int i = 0; i <= n; i++)
    {
        if (i == 0)
        {
            arr[i] = 0;
        }
        else if (i == 1)
        {
            arr[i] = 1;
        }
        else
        {
            arr[i] = arr[i - 1] + arr[i - 2];
        }
    }

    cout << arr[n] << "\n";

    return 0;
}
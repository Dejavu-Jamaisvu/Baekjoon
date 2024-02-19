#include <iostream>

using namespace std;

int fibonacci(int n)
{
    if (n == 0)
    {
        cout << 0;
        return 0;
    }
    else if (n == 1)
    {
        cout << 1;
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 0번째 피보나치 수는 0이고, 1번째 피보나치 수는 1
    int n; // 구하는 피보나치 수. 몇번째 피보나치 수 인가.

    cin >> n;

    fibonacci(n);

    return 0;
}
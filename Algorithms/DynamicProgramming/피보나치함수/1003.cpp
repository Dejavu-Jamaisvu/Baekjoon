#include <iostream>
#include <vector>

using namespace std;

// int zero = 0;
// int one = 0;

// int fibonacci(int n)
// {
//     if (n == 0)
//     {
//         zero++;
//         return 0;
//     }
//     else if (n == 1)
//     {
//         one++;
//         return 1;10
//     }
//     else
//     {
//         return fibonacci(n - 1) + fibonacci(n - 2);
//     }
// }

// int main()
// {

//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     int t; // 테스트 케이스 개수
//     cin >> t;

//     // 0번째 피보나치 수는 0이고, 1번째 피보나치 수는 1
//     int n; // 구하는 피보나치 수. 몇번째 피보나치 수 인가.

//     for (int i = 0; i < t; i++)
//     {
//         // 변수 초기화
//         zero = 0;
//         one = 0;

//         cin >> n;

//         fibonacci(n);

//         cout << zero << " " << one << "\n";
//     }
//     return 0;
// }

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; // 테스트 케이스 개수
    cin >> t;

    // 0번째 피보나치 수는 0이고, 1번째 피보나치 수는 1
    int n; // 구하는 피보나치 수. 몇번째 피보나치 수 인가.

    for (int j = 0; j < t; j++)
    {

        cin >> n;

        int zero[n+1];
        int one[n+1];

        for (int i = 0; i <= n; i++)
        {
            if (i == 0)
            {
                zero[i] = 1;
                one[i] = 0;
            }
            else if (i == 1)
            {
                zero[i] = 0;
                one[i] = 1;
            }
            else
            {
                zero[i] = zero[i - 1] + zero[i - 2];
                one[i] = one[i - 1] + one[i - 2];
            }
        }
        cout << zero[n] << " " << one[n] << "\n";
    }
    
    return 0;
}
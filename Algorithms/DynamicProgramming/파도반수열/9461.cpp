#include <iostream>
#include <vector>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; // 테스트 케이스 개수
    cin >> t;

    int n; // n번째 수는 무엇일까.

    for (int j = 0; j < t; j++)
    {

        cin >> n;

        long long arr[n + 1]; //100번째에 888855064897이 나와야함.

        for (int i = 1; i <= n; i++)
        {
            if (i == 1 || i == 2 || i == 3)
            {
                arr[i] = 1;
            }
            else if (i == 4 || i == 5)
            {
                arr[i] = 2;
            }
            else
            {
                arr[i] = arr[i - 1] + arr[i - 5];
            }
        }

        cout << arr[n] << "\n";
    }

    return 0;
}
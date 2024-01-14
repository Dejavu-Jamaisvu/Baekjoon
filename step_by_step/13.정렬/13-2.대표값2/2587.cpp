#include <iostream>
#include <cmath>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 5;
    int arr[n];

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    // 선택정렬. 첫번째 부터 끝까지 크기 비교해서 가장 작은 수를 첫번째랑 교환, 두번째부터 끝까지 가장작은수를 두번째 수와 교환.

    int temp;
    int minIndex;

    for (int i = 0; i < n-1; i++) // n-1까지 하면 마지막건 자동으로 가장 큰값 들어감.
    {
        minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << "\n";
    // }

    int centerIndex = round(n / (double)2) - 1; // 2분의1해서 반올림 후, 인덱스는 0부터니까 1빼줌

    cout << sum / n << "\n";
    cout << arr[centerIndex];
    return 0;
}

#include <iostream>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; // 배열크기 및 비교할 숫자
    cin >> n;

    int arr[n]; // 입력받을 배열

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int min = arr[0];
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }
    cout << min << " " << max << "\n";
    return 0;
}

#include <iostream>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; // 배열크기
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int num; // 비교할 숫자
    cin >> num;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
            count++;
    }

    cout << count;

    return 0;
}

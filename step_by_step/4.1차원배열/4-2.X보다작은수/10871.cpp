#include <iostream>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x; // 배열크기 및 비교할 숫자
    cin >> n >> x;


    int arr[n];  // 입력받을 배열
    int arr2[n]; // 기준 숫자보다 작은 수를 넣을 배열
    int index = 0;//입력받을 배열에 쓸 인덱스


    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < x)
            arr2[index]=arr[i];
            index++;
    }

    for (int i = 0; i <= index; i++)
    {
        cout << arr2[index] << endl;
    }

    return 0;
}

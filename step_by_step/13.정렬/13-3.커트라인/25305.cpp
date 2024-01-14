#include <iostream>
#include <cmath>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int rank;
    cin >> n >> rank;
    int arr[n];

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // 삽입정렬. 두번째 것부터 그 앞에 있는 것과 비교해서 두번째 것이 작다면 오른쪽으로 한칸 밀어내고 자신의 자리를 찾아 삽입함. 그다음 세번째도 마찬가지.

    int temp;
    int index;

    for (int i = 1; i < n; i++)
    {
        temp = arr[i];
        index=i;
        for (int j = i - 1; j >= 0 && arr[j] > temp; j--)
        {
            if (temp < arr[j])
            {
                arr[j+1] = arr[j];
                index=j;
            }  
        }
        arr[index]=temp;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << "\n";
    // }

    cout << arr[n - rank]; // 역순으로 sort되어 크기에서 rank를 빼면 인덱스(0부터 시작)
    return 0;
}
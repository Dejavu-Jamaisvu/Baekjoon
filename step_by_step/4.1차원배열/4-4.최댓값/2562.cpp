#include <iostream>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[9]; // 입력받을 배열

    for (int i = 0; i < 9; i++)
    {
        cin >> arr[i];
    }

    int max = arr[0];
    int maxindex = 0;
    for (int i = 1; i < 9; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            maxindex = i;
        }
    }
    cout << max << "\n"
         << maxindex + 1 << "\n";
    return 0;
}

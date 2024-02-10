#include <iostream>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[10] = {0};  // 나머지 구할 배열
    int arr2[10] = {0}; // 나머지들을 중복제거해서 넣을 배열

    int input;

    for (int i = 0; i < 10; i++)
    {
        cin >> input;
        arr[i] = input % 42;
    }

    int index=-1;//arr2에서 사용할 인덱스

    for (int i = 0; i < 10; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            
            if (arr[i] != arr2[j])
            {
                cout << i + 1 << "\n";
            }
        }
    }

    return 0;
}

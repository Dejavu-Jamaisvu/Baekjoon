#include <iostream>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //int arr[30] = {-1}; // 배열을 -1로 초기화
    int arr[10] = {-1}; // 배열을 -1로 초기화
    int index;

    for (int i = 0; i < 8; i++) // 28개의 입력
    {
        cin >> index;
        arr[index - 1] = 0; // 입력받은 수가 3이라면 3번째수인 인덱스2번(0부터시작하기에)에 0기입.
    }

    for (int i = 0; i < 10; i++)
    {
        if (arr[i] == -1)// 0이 아닌거를 찾아도 됨.
        { 
            cout << i + 1 << "\n";
        }
    }
    return 0;
}

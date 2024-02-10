#include <iostream>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;             // 명령의 수
    int topIndex = -1; // 스택 topindex
    int command;       // 1: push, 2: pop, 3:size 4: empty, 5: top
    int num;           // inputnum

    cin >> N;
    int stack[N]; // 명령수보다 개수가 많이 들어갈 수 없으니 이렇게 함

    for (int i = 0; i < N; i++)
    {
        cin >> command;

        if (command == 1)
        {
            cin >> num;
            stack[++topIndex] = num;
        }
        else if (command == 2)
        {
            if (topIndex > -1)
            {
                cout << stack[topIndex--] << "\n";
            }
            else
                cout << -1 << "\n";
        }
        else if (command == 3)
        {
            if (topIndex > -1)
            {
                cout << topIndex + 1 << "\n"; // 정수 개수는 인덱스 보다 하나 많음
            }
        }
        else if (command == 4)
        {
            if (topIndex > -1)
            {
                cout << 0 << "\n";
            }
            else
                cout << 1 << "\n";
        }
        else if (command == 5)
        {
            if (topIndex > -1)
            {
                cout << stack[topIndex] << "\n";
            }
            else
                cout << -1 << "\n";
        }
    }

    return 0;
}

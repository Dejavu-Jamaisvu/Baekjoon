#include <iostream>
#include <queue>
// #include <string>

using namespace std;
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<int> Queue;

    int N, K;
    cin >> N >> K;

    // 큐에 요소 추가
    for (int i = 1; i <= N; i++)
    {
        Queue.push(i);
    }

    // 루프돌며 출력
    cout << "<";

    while (!Queue.empty())
    {
        for (int i = 1; i <= K - 1; i++)
        {
            Queue.push(Queue.front());
            Queue.pop();
        }
        cout << Queue.front();
        Queue.pop();

        if (!Queue.empty())
            cout << ", ";
    }

    cout << ">";

    return 0;
}
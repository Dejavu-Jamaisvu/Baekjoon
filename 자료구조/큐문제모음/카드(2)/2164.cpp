#include <iostream>
#include <queue>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<int> queue;

    int N;
    cin >> N;
    string command;
    int element;

    for (int i = 1; i <= N; i++)
    {
        queue.push(i);
    }

    while (queue.size() != 1)
    {
        // 맨위에 있는 것 버리기
        queue.pop();

        // 그 다음 것 밑으로 옮기기(밑에로 가도록 push하고 pop하기)
        queue.push(queue.front());
        queue.pop();
    }

    cout << queue.front() << "\n";

    return 0;
}

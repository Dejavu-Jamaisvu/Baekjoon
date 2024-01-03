#include <iostream>
#include <queue>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<int> q1;//작업할 큐
    queue<int> q2;//결과 순열을 넣을 곳

    int N, K;
    cin >> N >> K;


    for (int i = 1; i <= N; i++)
    {
        q1.push(i);
    }

    while (!q1.empty())
    {
        for (int i = 1; i < K; i++) // K번째가 되기 전까지는 맨뒤로 옮겨서 원형큐처럼 만들기
        {

            q1.push(q1.front());
            q1.pop();
        }

        // 그 다음 것  pop하고, q2에 넣기
        q2.push(q1.front());
        q1.pop();
    }


    cout << "<";
    for (int i = 0; i < N; i++)
    {
        cout << q2.front();
        q2.pop();

        if (!q2.empty())
            cout << ", ";
    }
    cout << ">";

    return 0;
}

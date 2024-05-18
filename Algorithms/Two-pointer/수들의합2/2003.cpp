#include <iostream>
#include <vector>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력받을 값
    int N; // n개의 수로 된 수열.
    int M; // 되어야하는 수열의 합.

    cin >> N >> M;

    // 이용할 변수
    vector<int> vec(N);
    int start = 0; // 더할 수열의 시작 위치
    int end = 0;   // 더할 수열의 끝 위치
    int sum = 0;   // 현재 start~end 까지의 합.

    // 출력할 값
    int count = 0; // 출력값. 합이 m이 되는 수열 개수

    // input
    for (int i = 0; i < N; ++i)
    {
        cin >> vec[i];
    }

    // 수열 합 계산 후 합이 M이 되는 수열을 만나면 카운트 증가
    while (start < N)
    {
        if (sum >= M || end == N)
        {
            sum -= vec[start];
            start++;
        }
        else
        {
            sum += vec[end];
            end++;
        }

        // cout << "sum " << sum << ", count " << count << "\n";
        if (sum == M)
            count++;
    }

    cout << count << "\n";
    return 0;
}

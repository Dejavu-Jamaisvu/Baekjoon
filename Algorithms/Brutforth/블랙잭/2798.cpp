#include <iostream>
#include <vector>

using namespace std;

int blackjack(vector<int> &arr, int M)
{
    int n = arr.size();
    int max = 0;
    int sum = 0;

    // 모든 조합을 확인. 3개의 합이 m을 넘지않은 가장 큰 수.
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            for (int k = j + 1; k < n; ++k)
            {
                sum = arr[i]+arr[j]+arr[k];

                if (sum <= M && sum > max)
                    max = sum;
            }
        }
    }
    return max;
}

int main()
{

    // 입력받을 값
    int N; // n개의 수로 된 수열.
    int M; // 되어야하는 수열의 합.

    cin >> N >> M;
    vector<int> arr(N);

    // input
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    int result = blackjack(arr, M);
    cout << result << "\n";

    return 0;
}
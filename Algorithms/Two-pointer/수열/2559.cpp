#include <iostream>
#include <vector>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력받을 값
    int N; // 온도를 측정한 전체 날짜의 수
    int K; // 합을 구하기 위한 연속적인 날짜의 수

    cin >> N >> K;

    // 이용할 변수
    vector<int> vec(N);
    int start = 0; // 더할 수열의 시작 위치
    int end = 0;   // 더할 수열의 끝 위치
    int sum = 0;   // 현재 start~end 까지의 합.

    // 출력할 값
    int max = 0; // 출력값. K일의 온도의 합이 최대가 되는 값.

    // input
    for (int i = 0; i < N; ++i)
    {
        cin >> vec[i];
    }

    // 수열 합 계산 후 합이 M이 되는 수열을 만나면 카운트 증가
    while (start < N)
    {
        if (end - start + 1 > K || end == N)
        {
            // cout << "개수초과start옮겨서빼기" << sum << "-" << vec[start] << "\n";
            sum -= vec[start];
            start++; // 개수초과되고 ++하면 sum은 K-1개의 수열의 합이 됨. K개 수열의 합이 될 수없음 
        }
        else
        {
            // cout << "현재end포인터까지더하기" << sum << "+" << vec[end] << "\n";
            sum += vec[end];
            end++; // 다음을 위해 ++. 다음에 더해줄 위치를 가리킴
        }

        if (end - start == K && max < sum) //주의!! 계산 후 end를 ++해준 후라서 +1을 뺸것과 K를 비교함. 즉, +1-1한 것.
        {
            // cout << end << "-" << start << "=" << end - start << "/ sum " << sum << ", max " << max << "\n";
            max = sum;
        }
    }

    cout << max << "\n";
    return 0;
}
// 두개의 합일 때만이 아닌 하나일 때도 max를 체크함.
// 어차피 하나일때는 최대가 나올 수 없으니 상관없지만, 두개의 합일 때만 가능하도록 고쳐보는 것이 좋을 듯.
// => end - start == K && max < sum 로 고침.
// end == n 맞는지 한번더 확인
// => end > N. end가 n보다 커야함.
#include <iostream>
#include <algorithm>

using namespace std;

// 가장 작은 수끼리 먼저 힙하고 차례로 큰수를 합하는 방식으로 해야 비교 횟수가 적어짐

// 0번 10 => 10 10 10 10  ...n-1개
// 1번 20 => 20 20 20 20  ...n-1개
// 2번 40 => 40 40 40  ...n-2개
// 3번 70 => 70 70  ...2개
// 4번 90 => 90  ...1개
//  맨 좌측열 부터 더해지기 시작한다고 생각하면 편리함.
//<중요> 0번 1번은 그냥 더해주고 2번 인덱스 부터는 지금까지 더해진 카운트 + !!직전 카운트!! + 현재 인덱스 해줘야 작은 세모의 합이 나옴.

//=>어떻게 할까?
// 배열을 하나 더 만들어서, 직전값과 현재값을 더한 배열을 만들어 다 더해주고 인덱스0값을 빼줌.
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int card[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> card[i];
    }

    // card 배열 정렬하기
    sort(card, card + n); // 정렬할 시작과 끝을 넣어줌.

    // // 정렬한 배열 출력 확인
    // for (int i = 0; i < n; ++i)
    // {
    //     cout << card[i] << "  ";
    // }

    // cout << "\n";

    // 새로운 배열 만들어 직전합과 더하기
    int count[n];
    count[0] = card[0];
    for (int i = 1; i < n; i++)
    {
        count[i] = card[i] + count[i - 1];
    }

    // //새로운 배열 출력
    // for (int i = 0; i < n; ++i)
    // {
    //     cout << count[i] << "  ";
    // }
    // cout << "\n";

    // 만들어준 배열 값을 모두 더하기. 단, 인덱스 0은 뺌.
    int all = 0;
    for (int i = 1; i < n; i++) // 인덱스 0은 뺴줘야함.
    {
        all += count[i];
    }
    
    cout << all << "\n";

    return 0;
}
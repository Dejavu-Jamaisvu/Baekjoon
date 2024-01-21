#include <iostream>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num = 0; // case 1번 쓸 때 사용

    int L, P, V;
    cin >> L >> P >> V;

    // 캠핑장을 연속하는 P일 중, L일동안만 사용할 수 있는데, V일짜리 휴가가 있다.
    while (!(L == 0 && P == 0 && V == 0))
    {

        int count = 0; // 결과값 선언 및 초기화
        num += 1;

        // 휴가 20일 중에 8일 중 5번을 갈 수 있다고 할 때, 20일 중 8일이 몇번 있는지 확인. V/P해서 2번.
        // 그것을 8일동안 5번씩 갈 수 있으니, L을 곱해줌
        count += L * (V / P);

        // 20일 중 8일 두번인 16번을 뺴면 남은 값. 4번.
        // 이것이 추가로 더 사용할 수 있는 5번 보다 작거나 같다면 더해주고, 크다면 최대 5까지 더해줄 수 있음
        if (V % P <= L)
        {
            count += V % P;
        }
        else
        {
            count += L;
        }
        // 간단하게 아래처럼 사용 가능
        // count += min(L, V % P);

        cout << "Case " << num << ": " << count << "\n";

        cin >> L >> P >> V;
    }

    return 0;
}
//하단에서 다른 케이스 입력 받기전에 계속 루프가 도는 현상이 생겼다가 껐다 다시하니까 또 됨..




//다른방법 - while은 항상 true로 하고 안에서 if 문 break 이용해서 빠져나옴

// #include <iostream>

// using namespace std;

// int main()
// {

//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     int num = 0; // case 1번 쓸 때 사용

//     // 캠핑장을 연속하는 P일 중, L일동안만 사용할 수 있는데, V일짜리 휴가가 있다.
//     while (true)
//     {

//         int L, P, V;
//         cin >> L >> P >> V;

//         if (L == 0 && P == 0 && V == 0)
//         {
//             // 입력이 모두 0일 때 루프 종료
//             break;
//         }

//         int count = 0; // 결과값 선언 및 초기화
//         num += 1;

//         // 휴가 20일 중에 8일 중 5번을 갈 수 있다고 할 때, 20일 중 8일이 몇번 있는지 확인. V/P해서 2번.
//         // 그것을 8일동안 5번씩 갈 수 있으니, L을 곱해줌
//         count += L * (V / P);

//         // 20일 중 8일 두번인 16번을 뺴면 남은 값. 4번.
//         // 이것이 추가로 더 사용할 수 있는 5번 보다 작거나 같다면 더해주고, 크다면 최대 5까지 더해줄 수 있음
//         if (V % P <= L)
//         {
//             count += V % P;
//         }
//         else
//         {
//             count += L;
//         }
//         // 간단하게 아래처럼 사용 가능
//         // count += min(L, V % P);

//         cout << "Case " << num << ": " << count << "\n";

//         // cin >> L >> P >> V;
//     }

//     return 0;
// }
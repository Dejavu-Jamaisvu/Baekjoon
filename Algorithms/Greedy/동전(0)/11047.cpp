#include <iostream>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, money;
    cin >> n >> money;

    int coin[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> coin[i];
    }

    // 참고!
    // 범위기반으로 하려면 이거말고
    // for (int i:coin){
    //     cin >> coin[i];
    // }
    // 이거처럼 해야하는 듯 -> 확인 필요
    // for (int &i : coin) {
    //     cin >> i;
    // }

    int count = 0;

    for (int i = n - 1; i >= 0; i--) // n은 크기이므로 마지막 인덱스는 n-1임.
    {
        // cout << " 0구역 " << i << " " << count << " " << money << "\n";
        if (money % coin[i] == 0) // 딱떨어지게 되어 더이상 다음계산이 필요없음
        {
            count += money / coin[i];
            // money = money % i; // 없어도 괜찮음.

            // cout << " 1구역 " << i << " " << count << " " << money << "\n";
            break;
        }
        else
        {
            count += money / coin[i];
            money = money % coin[i];

            // cout << " 2구역 " << i << " " << count << " " << money << "\n";
        }
    }
    cout << count << "\n";

    return 0;
}
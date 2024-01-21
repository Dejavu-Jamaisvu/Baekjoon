#include <iostream>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int change[6] = {500, 100, 50, 10, 5, 1};
    int n;
    cin >> n;

    int j = 1000 - n; // 우선 잔액 전체를 넣어줌. 포문안에서 크기가 큰 잔액을 뺀 후 다음 계산을 위한 액수를 넣을 변수로 이용
    int count = 0;    // 몇개인지 세기 위해서

    // 참고) 배열의 크기 는 아래와 같이 계산, 여기서는 범위기반 for 루프로 for(int i:change) 사용
    // sizeof(myArray) / sizeof(myArray[0])

    for (int i : change)
    {
        if (j % i == 0) // 딱떨어지게 되어 더이상 잔액계산이 필요없음
        {
            count += j / i;
            break;
        }
        else
        {
            count += j / i;
            j = j % i;
        }
    }
    cout << count << "\n";

    return 0;
}
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void selfNumber(vector<int> &arr, int num)
{
    // 정수를 문자열로 변환
    string strNum = to_string(num);
    int sum = num;

    // 각 자릿수를 순회하며 더함
    for (char digit : strNum)
    {
        sum += digit - '0'; // 문자를 숫자로 변환하여 더함
    }

    if (sum < arr.size() && num != sum) // 10000보다 크면 안됨!! 합이 자기자신인 경우는 ++해주지 않고 재귀부르지 않음(무한루프)
    {
        arr[sum]++;
        selfNumber(arr, sum);
    }
}

int main()
{
    int N = 10000; // N보다 작거나 같은 셀프 넘버를 찾아야함.

    vector<int> arr(N + 1, 0); // 1부터 10000를 담아야해서 10001개. 인덱스0은 안쓸예정. 0으로 초기화

    // input
    for (int i = 1; i <= N; ++i) // 1부터 10000
    {
        selfNumber(arr, i);
    }

    // output
    for (int i = 1; i <= N; ++i)
    {
        if (arr[i] == 0)
            cout << i << "\n";
    }

    return 0;
}
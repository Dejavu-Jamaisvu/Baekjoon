#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
// #include <string>

using namespace std;
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; // 입력값 개수
    cin >> N;

    // 배열을 이용해봤다가 벡터를 이용하게 되어 주석처리
    // int input[N];
    // int sum = 0;
    // // 입력
    // for (int i = 0; i < N; i++)
    // {
    //     cin >> input[i];
    // }

    // // 산술평균
    // for (int i = 0; i < N; i++)
    // {
    //     sum += input[i];
    // }
    // cout << sum / N << "/n";

    vector<int> vec;
    int sum = 0;
    // 입력 및 산술평균 계산
    for (int i = 0; i < N; ++i)
    {
        cin >> vec[i];
        sum += vec[i];
    }
    cout << sum / N << "\n";

    // 중앙값
    sort(vec.begin(), vec.end());
    cout << vec[N / 2] << "\n";

    // 최빈값. 여러개 있을 때는 최빈값 중 두번째로 작은 값
    vector<int> vec2(N, 0); // 0으로 초기화

    vector<std::pair<int, int>> combined;


    // 범위
    cout << vec.end() - vec.begin() << "\n";//백이랑 프론트로 해야한다고함!!!!!!!!!

    return 0;
}
// unordered_map 사용도 할 수 있음 //unordered_map<int, int> map;
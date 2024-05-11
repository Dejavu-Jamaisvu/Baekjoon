// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// vector<int> findDwarfs(vector<int> &arr, int H)
// {
//     vector<int> result;
//     int N = arr.size();
//     int sum = 0;

//     // 모든 조합을 확인. 7개의 합이 H가 되는 수.
//     for (int i = 0; i < N; ++i)
//     {
//         for (int j = i + 1; j < N; ++j)
//         {
//             for (int k = j + 1; k < N; ++k)
//             {
//                 for (int l = k + 1; l < N; ++l)
//                 {
//                     for (int m = l + 1; m < N; ++m)
//                     {
//                         for (int n = m + 1; n < N; ++n)
//                         {
//                             for (int o = n + 1; o < N; ++o)
//                             {
//                                 sum = arr[i] + arr[j] + arr[k] + arr[l] + arr[m] + arr[n] + arr[o];

//                                 if (sum == H)
//                                 {
//                                     result.push_back(arr[i]);
//                                     result.push_back(arr[j]);
//                                     result.push_back(arr[k]);
//                                     result.push_back(arr[l]);
//                                     result.push_back(arr[m]);
//                                     result.push_back(arr[n]);
//                                     result.push_back(arr[o]);
//                                 }
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     return result;
// }

// int main()
// {
//     int N = 9;   // 난쟁이 총 9명
//     int M = 7;   // 난쟁이 7명이 필요
//     int H = 100; // 해당 난쟁이 7명의 키 합은 100

//     vector<int> arr(N);

//     // input
//     for (int i = 0; i < N; ++i)
//     {
//         cin >> arr[i];
//     }

//     sort(arr.begin(), arr.end()); // 정렬

//     vector<int> result = findDwarfs(arr, H);

//     // output
//     for (int i = 0; i < result.size(); ++i)
//     {
//         cout << result[i] << "\n";
//     }

//     return 0;
// }

// 위에게 틀렸다고 함.
// 7개를 찾는게 아니라 2개를 찾아서 빼는 방법으로 변경함
// 위 방법은 후에 다시 해볼 것.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findDwarfs(vector<int> &arr, int H, int total)
{
    vector<int> result = arr;
    int N = arr.size();
    int sum = 0;

    // 7개의 합이 H가 되는 수. 총 9개 합에서 2개를 빼서 7개를 만듦.
    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            sum = total - arr[i] - arr[j];

            if (sum == H)
            {
                result.erase(result.begin() + j); // 인덱스 j의 제거 (0부터 시작) //j가 뒤 인덱스라 먼저 삭제해주어야함!!
                result.erase(result.begin() + i);
                return result;
                // 런타임에러 떠서 찾아보니 어떤분이 여기에 break 함. 내생각엔 여기 리턴하면 될듯해서 넣음 //https://www.acmicpc.net/board/view/64946
            }
        }
    }
    return result;
}

int main()
{
    int N = 9;   // 난쟁이 총 9명
    int M = 7;   // 난쟁이 7명이 필요
    int H = 100; // 해당 난쟁이 7명의 키 합은 100

    vector<int> arr(N);
    int total = 0;

    // input
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
        total += arr[i];
    }

    sort(arr.begin(), arr.end()); // 정렬

    vector<int> result = findDwarfs(arr, H, total);

    // output
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << "\n";
    }

    return 0;
}
#include <iostream>

using namespace std;

// MenOfPassion(A[], n) {
//     sum <- 0;
//     for i <- 1 to n
//         for j <- 1 to n
//             for k <- 1 to n
//                 sum <- sum + A[i] × A[j] × A[k]; # 코드1
//     return sum;
// }

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n; // 입력의 크기  500,000까지임
    cin >> n;
    cout << n * n * n << "\n" // 수행횟수
         << 3;                // 최고차항 차수
    return 0;
}

#include <iostream>

using namespace std;

// MenOfPassion(A[], n) {
//     sum <- 0;
//     for i <- 1 to n - 2
//         for j <- i + 1 to n - 1
//             for k <- j + 1 to n
//                 sum <- sum + A[i] × A[j] × A[k]; # 코드1
//     return sum;
// }


//입력값이 7인 경우

//1, 2 : 3 4 5 6 7 ->5번
//   3 : 4 5 6 7 ->4번
//   4 : 5 6 7 ->3번
//   5 : 6 7 ->2번
//   6 : 7 ->1번

//2, 3 : 4 5 6 7 >4번
//   4 : 5 6 7 ->3번
//   5 : 6 7 ->2번
//   6 : 7 ->1번

//3, 4 : 5 6 7 ->3번
//   5 : 6 7 ->2번
//   6 : 7 ->1번

//4, 5 : 6 7 ->2번
//   6 : 7 ->1번

//5, 6 : 7 ->1번

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n; // 입력의 크기 500,000까지임
    cin >> n;
    cout << n * n * n << "\n" // 수행횟수
         << 3;                // 최고차항 차수
    return 0;
}

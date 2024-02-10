#include <iostream>
#include <deque>

using namespace std;

int indexNum(int *arr, int N, int num)
{
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == num)
        {
            return i;
        }
    }
    return -1; //-1을 반환하여 해당 숫자가 배열에 없음을 표시
}
void printArray(int *arr, int N)
{
    for (int i = 0; i < N; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    deque<int> deque;

    int N;
    cin >> N;
    int input;
    int arr[N];  // 배열 인덱스 확인용
    int arr2[N]; // 터진 풍선 번호 출력용
    int num;

    for (int i = 0; i < N; i++)
    {
        cin >> input;
        deque.push_back(input);
        arr[i] = input;
    }

    // printArray(arr, N);
    printArray(arr2, N);

    num = deque.front();
    arr2[indexNum(arr, N, num)] = 1; // 첫번째 pop하는 인덱스 찾아서 그 인덱스에 1 넣어주기
    deque.pop_front();

    for (int i = 2; i <= N; i++)
    {
        if (num < 0)
        {
            for (int j = -1; j > num; j--) // 범위 주의
            {
                deque.push_front(deque.back());
                deque.pop_back();
            }
            num = deque.back();
            arr2[indexNum(arr, N, num)] = i;
        }
        else
        {
            for (int j = 1; j < num; j++) // 범위 주의
            {
                deque.push_back(deque.front());
                deque.pop_front();
            }

            num = deque.front();
            arr2[indexNum(arr, N, num)] = i;
        }
    }
    printArray(arr2, N);

    return 0;
}
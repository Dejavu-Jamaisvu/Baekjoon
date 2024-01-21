#include <iostream>
#include <string>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int start[n];
    int finish[n];

    // n 만큼 입력받아 배열에 넣기
    for (int i = 0; i < n; i++)
    {
        cin >> start[i] >> finish[i];
    }

    // 만약 입력받은 배열이 finish기준으로 오름차순 정렬 해주기-버블
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 1; j < n - 1; ++j)
        {
            if (finish[j] > finish[j + 1])
            {
                swap(finish[j], finish[j - 1]);
                swap(start[j], start[j - 1]);
            }
        }
    }

    // // 정렬한 배열 출력해서 확인
    // cout << "정렬 후"
    //      << "\n";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << start[i] <<" "<< finish[i] << "\n";
    // }

    int count = 0;
    int minIndex = 0; // 첫번째 인덱스를 초기에 넣어줌 //정렬해줘서 가장 빨리 끝나는 회의임.

    // 첫번째로 가장 빨리 끝나는 회의를 찾는다.
    // 가장 빨리 끝나는건 첫번째 인덱스임.
    // for (int i = 1; i < n; ++i)
    // {
    //     if (finish[i] < finish[minIndex])
    //     {
    //         minIndex = i;
    //         count++;
    //         cout << " 1구간 " << i << "" << minIndex << " " << count << "\n";
    //     }
    // }


    // 끝난 시간을 기준으로 이 이후에 시작하면서 또 가장 빠르게 끝나는 회의를 찾으며 count를 올린다.
    for (int j = 0; j < n; j++)
    {
        if (start[j] >= finish[minIndex])
        {

            cout << " 2구간 j " << j << " " << minIndex << " " << count << "\n";

            for (int i = j; i < n; ++i)
            {
                if (finish[i] < finish[minIndex])
                {
                    minIndex = i;
                    count++;

                    cout << " 2구간 i " << i << " " << minIndex << " " << count << "\n";
                }
            }
        }
    }
    cout << count << "\n";

    return 0;
}
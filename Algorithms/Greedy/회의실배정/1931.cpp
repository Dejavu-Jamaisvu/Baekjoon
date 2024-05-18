#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct MeetingTime
{
    int finish;
    int start;
};

bool compareByTime(const MeetingTime &a, const MeetingTime &b)
{
    return a.finish < b.finish;
}
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;


    vector<MeetingTime> meeting(n); // 크기지정안해주면 25634 segmentation fault 뜸.!!!

    // n 만큼 입력받아 배열에 넣기
    for (int i = 0; i < n; i++)
    {
        cin >> meeting[i].start >> meeting[i].finish;
    }



    vector<MeetingTime> search;
    sort(meeting.begin(), meeting.end(), compareByTime); // 이런식으로 compareByTime 사용자정의함수 이용해서 구조체 안에 있는 내용으로 정렬할 수 있다고함.!! 람다를 이용할 수도 있음.

    int count = 1; // 회의의 수는 1 ≤ N ≤ 100,000 이며, 첫번째 인덱스는 맨처음에 항상 사용되어서 1

    // 현재 회의실을 사용하는 index의 finish 보다 시작점이 큰것들로만 배열을 만들어 재정렬함.
    for (int i = 1; i < meeting.size(); i++)
    {
        if (meeting[i].start >= meeting[0].finish)
        {
            search.push_back(meeting[i]);
            // cout << "i " << i << "\n";
        }
    }

    while (search.size() != 0) // 현재 회의실을 사용하는 index의 finish 보다 시작점이 큰 요소들이 담긴 배열크기가 1이상이면 반복!
    {
        // 다음 후보군 중 finish가 가장 작은 인덱스를 찾음 = minIndex, 그리고 카운트도 올림.
        // sort(search.begin(), search.end(), compareByTime); // 정렬후 0번째 인덱스가 finish가 가장 작은 인덱스임.//그런데 이미 정렬된 상태이기에 굳이 또 할 필요없음!!

        meeting.clear();                                   // meeting과 search를 반복문속에서 계속 사용하기 위해
        meeting = search;                                  // meeting에 search값을 넣고
        search.clear();                                    // clear() 후 search에는 그다음 회의실의 후보군을 넣을 것임.
        count++;
        // cout << "count " << count << "\n";

        // 또 다시 회의실을 사용하는 index의 finish 보다 시작점이 큰것들로만 배열을 만들어 재정렬함.
        for (int i = 1; i < meeting.size(); i++)
        {
            if (meeting[i].start >= meeting[0].finish)
            {
                search.push_back(meeting[i]);
                // cout << "i " << i << "\n";
            }
        }
    }
    cout << count << "\n";

    return 0;
}
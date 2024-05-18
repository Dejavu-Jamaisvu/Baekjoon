#include <iostream>
#include <string>

using namespace std;
int ACLanguage() {}

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

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm> // reverse 함수를 사용하기 위해 필요
#include <sstream>

using namespace std;

void PrintX(vector<int> &x)
{
    cout << "[";
    for (int j = 0; j < x.size(); j++)
    {
        cout << x[j];
        if (j != x.size() - 1) // 마지막이 아니면
            cout << ",";
    }
    cout << "]" << "\n";
}

bool ACLanguage(vector<int> &x, char c)
{
    if (c == 'R')
    { // 함수 R은 배열에 있는 수의 순서를 뒤집는 함수
        reverse(x.begin(), x.end());
    }
    else if (c == 'D')
    { // D는 첫 번째 수를 버리는 함수
        if (x.empty())
        {
            cout << "error\n";
            return false;
        }
        else
        {
            x.erase(x.begin());
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; // 테스트 케이스 개수
    // scanf("%d", &T);
    cin >> T;

    //??? 전체 테스트 케이스에 주어지는 p의 길이의 합과 n의 합은 70만을 넘지 않는다.??어디에쓰는걸까?

    for (int i = 0; i < T; i++)
    {
        string p; // 수행할 함수 // 1보다 크거나 같고, 100,000보다 작거나 같다.
        cin >> p;

        int n; // 배열에 들어있는 수의 개수 (0 ≤ n ≤ 100,000)
        // scanf("%d", &n);
        cin >> n;

        string list; // [x1,...,xn] 형태의 문자열
        cin >> list;
        // list[,,]를 구분하여 x에 넣음.
        vector<int> x;              //[x1,...,xn]의 요소를 넣음 // 정수 (1 ≤ xi ≤ 100)
        list.erase(list.end() - 1); // 문자열 맨 뒤의 문자 ] 삭제
        list.erase(list.begin());   // 문자열 맨 앞의 문자 [ 삭제

        stringstream ss(list);
        string token;
        while (getline(ss, token, ','))
        { // 문자열을 구분자 ','를 기준으로 분리하여 정수로 변환하여 벡터에 저장
            x.push_back(stoi(token));
        }

        // // list[,,]를 구분하여 x에 넣음. //두자릿수 이상의 수를 가져오지 못하는 문제가 있어서 폐기
        // for (char a : list)
        // {
        //     if (a != '[' && a != ',' && a != ']')
        //     {
        //         x.push_back(a-'0');
        //     }
        // }

        // ACLanguage함수 호출 // p 크기 만큼
        bool b = true;
        for (char a : p)
        {
            b = ACLanguage(x, a);
            if (!b)
                break; // 해당 for문만 나가짐.
        }

        if (b)
            PrintX(x);
    }

    return 0;
}

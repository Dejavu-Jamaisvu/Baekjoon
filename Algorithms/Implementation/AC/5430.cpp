#include <iostream>
#include <string>
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
        if (j != x.size() - 1) // 마지막게 아니면
        {
            cout << ",";
        }
    }
    cout << "]" << "\n";
}
bool ACLanguage(vector<int> &x, char c)
{

    if (c == 'R') // 함수 R은 배열에 있는 수의 순서를 뒤집는 함수
    {
        reverse(x.begin(), x.end());
    }
    else if (c == 'D') // D는 첫 번째 수를 버리는 함수. 배열이 비어있는데 D를 사용한 경우 에러.
    {

        if (x.size() == 0)
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

    int T; // 테스트 케이스 개수//최대 100
    cin >> T;

    // string p; // 수행할 함수 //p의 길이는 1보다 크거나 같고, 100,000보다 작거나 같다.
    // int n;    // 배열에 들어있는 수의 개수 (0 ≤ n ≤ 100,000)

    // string list;      //[x1,...,xn]과 같은 형태
    // vector<int> x(n); //[x1,...,xn]과 같은 형태를 넣을 공간. 정수 (1 ≤ xi ≤ 100)

    //??? 전체 테스트 케이스에 주어지는 p의 길이의 합과 n의 합은 70만을 넘지 않는다.??어디에쓰는걸까?

    for (int i = 0; i < T; i++)
    {
        string p; // 수행할 함수 //p의 길이는 1보다 크거나 같고, 100,000보다 작거나 같다.
        int n;    // 배열에 들어있는 수의 개수 (0 ≤ n ≤ 100,000)

        string list;      //[x1,...,xn]과 같은 형태
        vector<int> x(n); //[x1,...,xn]과 같은 형태를 넣을 공간. 정수 (1 ≤ xi ≤ 100)

        cin >> p;
        cin >> n;
        cin >> list;
        x.clear();

        // // list[,,]를 구분하여 x에 넣음. //두자릿수 이상의 수를 가져오지 못하는 문제가 있어서 폐기
        // for (char a : list)
        // {
        //     if (a != '[' && a != ',' && a != ']')
        //     {
        //         x.push_back(a-'0');
        //     }
        // }

        // list[,,]를 구분하여 x에 넣음.
        list.erase(list.end() - 1); // 문자열 맨 뒤의 문자 ] 삭제 //string이라 -1 해주어야함!!!
        list.erase(list.begin());   // 문자열 맨 앞의 문자 [ 삭제

        stringstream ss(list);
        string token;
        while (getline(ss, token, ',')) // 문자열을 구분자','를 기준으로 분리
        {
            x.push_back(stoi(token));
        }

        // cout << "\n-----구분선------\n";

        // ACLanguage함수 호출 //p 크기 만큼
        bool b = true;
        for (char a : p)
        {
            b = ACLanguage(x, a);

            if (b == false)
                break; // 해당 for문만 나가짐.
        }

        // 결과값 출력
        if (b == true)
        {
            PrintX(x);
        }
    }
    return 0;
}
#include <iostream>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;

    while (1)
    {
        cin >> a >> b;
        if (cin.eof())// 위치가 cin 바로 다음이어야하는 듯. cout 밑에 두니까 에러남.
            break; 
        cout << a + b << "\n";
    }

    return 0;
}
// EOF 참고
// https://heestory0324.tistory.com/10
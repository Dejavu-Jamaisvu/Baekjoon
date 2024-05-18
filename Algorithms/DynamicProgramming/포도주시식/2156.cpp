#include <iostream>


using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; //몇개의 잔이 있는가
    cin >> t;
    int glass[t];

    for (int i = 0; i < t; i++)
    {

        cin >> glass[i];

    }

    return 0;
}
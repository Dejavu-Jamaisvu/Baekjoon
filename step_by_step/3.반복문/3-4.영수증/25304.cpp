#include <iostream>

using namespace std;

int main()
{

    int allPrice;
    int allCount;
    int sum = 0;
    int price, num; //문제에서의 a,b

    cin >> allPrice;
    cin >> allCount;

    for (int i = 1; i <= allCount; i++)
    {
        cin >> price >> num;
        sum += price * num;
        // cout << sum << endl;
    }

    if (allPrice == sum)
    {

        cout << "Yes" << endl;
    }
    else
    {

        cout << "No" << endl;
    }

    return 0;
}
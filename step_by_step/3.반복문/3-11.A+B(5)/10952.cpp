#include <iostream>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;

    cin >> a >> b;
    do
    {
        cout << a + b << "\n";
        cin >> a >> b;
    } while (!(a == 0 && b == 0));

    return 0;
}
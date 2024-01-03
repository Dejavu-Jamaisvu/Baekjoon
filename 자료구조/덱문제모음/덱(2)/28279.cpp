#include <iostream>
#include <deque>


using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    deque<int> deque;

    int N;
    cin >> N;
    int command;
    int element;

    for (int i = 0; i < N; i++)
    {
        cin >> command;

        if (command == 1)
        {
            cin >> element;
            deque.push_front(element);
        }else if (command == 2)
        {
            cin >> element;
            deque.push_back(element);
        }
        else if (command == 3)
        {
            if (deque.empty())
            {
                cout << -1 << "\n";
            }
            else{
                cout << deque.front() << "\n";
                deque.pop_front();
            }
        }else if (command == 4)
        {
            if (deque.empty())
            {
                cout << -1 << "\n";
            }
            else{
                cout << deque.back() << "\n";
                deque.pop_back();
            }
        }
        else if (command == 5)
        {
            cout << deque.size() << "\n";
        }
        else if (command == 6)
        {
            if (deque.empty())
            {
                cout << 1 << "\n";
            }
            else
                cout << 0 << "\n";
        }
        else if (command == 7)
        {
            if (deque.empty())
            {
                cout << -1 << "\n";
            }
            else
                cout << deque.front() << "\n";
        }
        else if (command == 8)
        {
            if (deque.empty())
            {
                cout << -1 << "\n";
            }
            else
                cout << deque.back() << "\n";
        }
    }

    return 0;
}
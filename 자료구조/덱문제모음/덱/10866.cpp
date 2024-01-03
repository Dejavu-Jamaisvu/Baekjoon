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
    string command;
    int element;

    for (int i = 0; i < N; i++)
    {
        cin >> command;

        if (command == "push_front")
        {
            cin >> element;
            deque.push_front(element);
        }else if (command == "push_back")
        {
            cin >> element;
            deque.push_back(element);
        }
        else if (command == "pop_front")
        {
            if (deque.empty())
            {
                cout << -1 << "\n";
            }
            else{
                cout << deque.front() << "\n";
                deque.pop_front();
            }
        }else if (command == "pop_back")
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
        else if (command == "size")
        {
            cout << deque.size() << "\n";
        }
        else if (command == "empty")
        {
            if (deque.empty())
            {
                cout << 1 << "\n";
            }
            else
                cout << 0 << "\n";
        }
        else if (command == "front")
        {
            if (deque.empty())
            {
                cout << -1 << "\n";
            }
            else
                cout << deque.front() << "\n";
        }
        else if (command == "back")
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
#include <iostream>
#include <queue>


using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    queue<int> queue;

    int N;
    cin >> N;
    string command;
    int element;

    for (int i = 0; i < N; i++)
    {
        cin >> command;

        if (command == "push")
        {
            cin >> element;
            queue.push(element);
        }
        else if (command == "pop")
        {
            if (queue.empty())
            {
                cout << -1 << "\n";
            }
            else{
                cout << queue.front() << "\n";
                queue.pop();
            }
        }
        else if (command == "size")
        {
            cout << queue.size() << "\n";
        }
        else if (command == "empty")
        {
            if (queue.empty())
            {
                cout << 1 << "\n";
            }
            else
                cout << 0 << "\n";
        }
        else if (command == "front")
        {
            if (queue.empty())
            {
                cout << -1 << "\n";
            }
            else
                cout << queue.front() << "\n";
        }
        else if (command == "back")
        {
            if (queue.empty())
            {
                cout << -1 << "\n";
            }
            else
                cout << queue.back() << "\n";
        }
    }

    return 0;
}
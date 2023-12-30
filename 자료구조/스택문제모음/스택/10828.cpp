#include <iostream>
#include <stack>


using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    stack<int> stack;

    int N;
    cin >> N;
    string command;
    int element;

    for (int i = 0; i < N; i++)
    {
        cin >> command;

        if (command == "push")//1. 정수를 스택에 넣는다
        {
            cin >> element;
            stack.push(element);
        }
        else if (command == "pop")//2. 정수가 있다면 맨위에 정수를 빼고 출력. 없다면 -1
        {
            if (stack.empty())
            {
                cout << -1 << "\n";
            }
            else{
                cout << stack.top() << "\n";
                stack.pop();
            }
        }
        else if (command == "size")//3. 스택에 들어있는 정수 개수
        {
            cout << stack.size() << "\n";
        }
        else if (command == "empty")//4. 스택이 비어있으면 1 아니면 0
        {
            if (stack.empty())
            {
                cout << 1 << "\n";
            }
            else
                cout << 0 << "\n";
        }
        else if (command == "top")//5. 스택에 정수가 있다면 맨위 정수 출력. 없으면 -1
        {
            if (stack.empty())
            {
                cout << -1 << "\n";
            }
            else
                cout << stack.top() << "\n";
        }
    }

    return 0;
}

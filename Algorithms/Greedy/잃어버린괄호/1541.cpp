#include <iostream>
#include <string>

using namespace std;

// 내가 몰랐던 포인트! ... 예제를 대충봐서 그냥 수식 따라 더하고 빼면 되지 뭐가 문제인가 했다.
//'-' 뒤에 오는 '+'식들을 괄호쳐서 전부 뺄셈 처리하면 식의 값이 최소가 된다.
// Ex).
// 55-50+40-30+10
// 55-(50+40)-(30+10)
// 55-50-40-30-10
// '-' 기호가 1번이라도 나오면 그 뒤의 모든 숫자는 빼준다.!!!!!! 중요!!!
// https://scarlettb.tistory.com/64

// 나는 기호로 문자열 자르고, 스택을 이용해서 더하고 뺴려고 했는데 그냥 받아와서 바로바로 계산해주면 되는 듯하다.
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input; // 입력받을 문자열
    cin >> input;

    string currentNumber; // 문자열 중에서 숫자만
    int result = 0;       // 수식을 더하고 뺄 변수. 최종적으로 결과 값
    bool isMinus = false; // 마이너스를 만나면 뒷부분을 빼주기 위한 참 거짓 값

    for (int i = 0; i <= input.size(); i++)
    {
        if (isdigit(input[i]))
        {
            // 현재 문자가 숫자인 경우, 현재 찾아진 숫자에 추가
            currentNumber += input[i];
        }
        else if (input[i] == '-' || input[i] == '+' || i == input.size()) // 뒤에 부호를 만나거나 문자열의 끝을 만나 숫자가 끝나면
        {
            if (isMinus)
            {
                result -= stoi(currentNumber);
                currentNumber.clear();
            }
            else
            {
                result += stoi(currentNumber);
                currentNumber.clear();
            }
        }

        if (input[i] == '-') // 맨 나중에 체크해야함. 읽은 부분까지 계산 끝내고 부호 만난 이후부터 모든 부호를 마이너스 처리해줘야하기 때문.
        {
            isMinus = true;
        }
    }

    cout << result << "\n";

    return 0;
}
// stoi 함수에 대해 자세히 알아보기
// string에 있는 clear empty 등의 함수도 알아보기
// 배열 size와 length에 대해 비교해보기

// 스터디 - 유민
// string 을 int로 바꾸지 않고 int로만 계산 할때
// num = num*10+(ch-'0')
// 기존거를 10곱해주고 현재 수를 int형으로 바꿔서 넣어줌
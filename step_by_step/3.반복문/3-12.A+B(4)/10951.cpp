// #include <iostream>

// using namespace std;

// int main()
// {

//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     int a, b;

//     while (1)
//     {
//         cin >> a >> b;
//         if (cin.eof())// 위치가 cin 바로 다음이어야하는 듯. cout 밑에 두니까 에러남.
//             break; 
//         cout << a + b << "\n";
//     }

//     return 0;
// }
// EOF 참고
// https://heestory0324.tistory.com/10





// 유정 코드 - c
// c의 경우는 scanf리턴값이 !=EOF 인지 여부로 조건문 사용하면 된다고 함.
// #include<stdio.h>

// int main()
// {
//     int A = 0, B = 0;
    
//     while(scanf("%d %d", &A, &B) != EOF)
//     {
//         if (scanf("%*s") == EOF)  // 추가된 부분
//             break;
//         printf("%d\n", A+B);
//     }

//     return 0;
// }
//여기서 %*s는 문자열을 읽어들이지만 저장하지 않는 형식입니다. 이를 통해 입력 버퍼에서 문자열을 제거할 수 있습니다.
//%*s는 입력된 문자열을 읽어들이지만 저장하지 않는 형식입니다. %*s에서 %*는 일반적으로 읽은 값을 저장하지 않도록 하는데 사용되는 modifier입니다. 따라서 해당 형식을 사용하면 입력된 문자열을 읽어들이지만 저장하지 않고 넘어가므로 입력 버퍼에서 해당 문자열을 제거하는 효과를 얻을 수 있습니다.
// 비정상종료되는 현상을 보여줌. 확인해볼 것.


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
        if (!(cin >> a >> b))
        {
            // 입력 오류가 발생하면 루프를 종료합니다.
            // 이는 입력이 정수가 아닌 경우에 발생할 수 있습니다.
            break;
        }
        cout << a + b << "\n";
    }

    return 0;
}
//이렇게하면 무한루프 안함. EOF로 백준에서 승인될지는 모르겠으니 확인필요함!
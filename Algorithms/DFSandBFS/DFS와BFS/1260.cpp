#include <iostream>
#include <string>

using namespace std;

// 오른, 아래, 왼, 위
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void dfs()
{
}
void bfs()
{
}

int** allocateArray(int rows, int cols) {
    int** newArray = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        newArray[i] = new int[cols];
    }
    return newArray;
}

void initializeArray(int** array, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            array[i][j] = 0;
        }
    }
}

void printDoubleArray(int** array, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << array[i][j] << " ";
        }
        cout << "\n";
    }
}

void deallocateArray(int** array, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    static int n, m, v; // 정점의 개수, 간선의 개수, 탐색 시작할 정점 번호
    cin >> n >> m >> v;



    // 배열 동적 할당
    int** myArray = allocateArray(n, n);
    int** visited = allocateArray(n, n);

    // 배열 초기화
    initializeArray(myArray, n, n);

    // 배열 출력
    printDoubleArray(myArray, n, n);

    // 배열 해제
    deallocateArray(myArray, n);



    // // 간선이 연결하는 두 정점의 번호를 입력 받음
    // for (int i = 0; i < m; i++) // 간선의 개수만큼

    // {
    //     int x, y = -1;
    //     cin >> x >> y;
    //     // 간선을 입력받아서 배열에 표기해줌
    //     // 배열에 넣을때는 -1해주고 넣기! 인덱스0부터 시작하니까!
    // }
}


//배열 초기화 방식 한번 알아볼 것.
//memset(arr, 0, sizeof(arr)); // 배열초기화 : memset(시작 주소, 설정하려는 값, 전체 크기) ... 그냥 {{0}}하니까 크기가 고정되지 않아서 동적할당해줘야한다고 빨간줄 뜸.

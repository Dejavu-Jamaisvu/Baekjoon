#include <iostream>

int main(int argc, char **argv) {
    for (int i = 0; i < argc; i++) {
        std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
    }
    int n = 3;
    for (int i = 0; i < n; i++) {
        std::cout << i << std::endl;
    }
    return 0;
}
//https://korbillgates.tistory.com/248 [생물정보학자의 블로그:티스토리]
//F5키를 눌러서 다음 breakpoint 로 이동. F10키를 눌러서 한 줄씩 실행.
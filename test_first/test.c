#include <stdio.h>
// int main(){
//     char *str[] ="Hello world!";
//     str[0]='h';
//     printf(%s,str);
//     free(str);
// }

int main(){
    int x=10;
    int *y=&x; //or x
    int z=20;
    x=z;

    printf("x=%d, y=%d, z=%d",x, y, z);
}
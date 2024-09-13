#include <stdio.h>

extern void temp(); //để sử dụng hàm của file test
//extern int i;

int main(int argc, char const *argv[])
{
    temp();
    return 0;
}


//địa chỉ kiểu trả về
// int *ptr(){
//     static int test = 20; //biến static cục bộ chỉ được sử dụng trong hàm này
//     return &test;
// }


// int *ptr = NULL;

// void count(){
//     static int i = 0;
//     ptr = &i;
//     //int x = 3;
//     printf("i = %d\n", i);
//     i++;
//     //x++;
// }


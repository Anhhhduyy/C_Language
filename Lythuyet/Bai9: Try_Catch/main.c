#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf buf;
int check = 0; //sử dụng để bằng setjmpbuf để khi nào có longjmp sẽ trả lại setjmp


double thuong(int a, int b){
    if(b == 0){
        longjmp(buf, 1);
    }
    return (double)a/b;
}

void string(char array[], int length){
    if(length <= 0){
        longjmp(buf, 2);
    }
}

int main(int argc, char const *argv[])
{
    char arr[] = "Hello";
    check = setjmp(buf);
    if(check == 0){
        printf("Thuong cua a va b la: %.2f\n", thuong(6, 1));
        string(arr, 0);
    }else if(check == 1){
        printf("ERROR! Mau bang 0\n");
    }else if(check == 2){
        printf("ERROR! Mang <= 0\n");
    }
    return 0;
}
//Giải thích: ban đầu check = 0, khi b = 0 chương trình sẽ quay về thương
//để check đk if và con trỏ lúc đó sẽ thoát ra khỏi thuong và trỏ về check
// (lúc này check sẽ bằng 1 do longjmp) và thực hiện in ra ERROR

#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h>

jmp_buf buf;
int check = 0;

#define TRY if((check = setjmp(buf)) == 0)
#define CATCH(num) else if(check == num)
#define THROW(num) longjmp(buf, num)


double thuong(int a, int b){
    if(b == 0){
        THROW(1);
    }
    return (double)a/b;
}

void string(char array[], int length){
    if(length <= 0){
        THROW(2);
    }
}

int main(int argc, char const *argv[])
{
    char arr[] = "Hello";
    TRY{
        printf("Thuong cua a va b la: %.2f\n", thuong(6, 1));
        string(arr, 0);
    }CATCH(1){
        printf("ERROR! Mau bang 0\n");
    }CATCH(2){
        printf("ERROR! Mang <= 0\n");
    }
    return 0;
}
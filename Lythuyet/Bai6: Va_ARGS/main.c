#include <stdio.h>
#include <stdarg.h>

int tong(int num, ...){ //num = bao nhiêu thì duyệt bấy nhiêu "..."
    int sum = 0;
    va_list va; //khai báo 1 biến thuộc kiểu va_list
    va_start(va, num); //(list, input parameter)
    //va tác dụng như 1 con trỏ 
    for (int i = 0; i < num; i++)
    {
        sum += va_arg(va, int);
    }
    va_end(va); //thu hồi vùng nhớ
    return sum;
    
}

int main(int argc, char const *argv[])
{
    printf("tong a va b: %d\n", tong(3, 5, 1, 1));
    return 0;
}

#include <stdio.h>
#include <stdbool.h>
#include <setjmp.h>
#include <stdlib.h>

int val;
jmp_buf butffer;

void test1(){
    int key = 0;
    do 
    {
        printf("CT test 1\n");
        printf("Nhan 1 quay lai\n");
        scanf("%d", &key);
    } while (key != 1);
    longjmp(butffer, 1);
    
}

void test2(){
    int key = 0;
    do 
    {
        printf("CT test 2\n");
        printf("Nhan 2 quay lai\n");
        scanf("%d", &key);
    } while (key != 2);
    longjmp(butffer, 2);
    
}

int main(int argc, char const *argv[])
{

    val = setjmp(butffer); //truyền giá trị vào but vừa mới khởi tạo, có gtri trả về = 0
    int  key = 0;
    do
    {
        printf("CT test 1\n");
        printf("Nhan 1: test 1\n");
        printf("Nhan 2: test 2\n");
        scanf("%d", &key);
    } while (key != 1 && key != 2);
    switch (key)
    {
    case 1:
        key =0;
        test1();
        break;
    case 2: 
        key = 0;
        test2();
        break;
    default:
        break;
    }
    return 0;
}





// int main(int argc, char const *argv[])
// {
//     while (1)
//     {
//         for (int i = 0; i < 10; i++)
//         {
//             for (int j = i +1; j < 11; j++)
//             {
//                 printf("i = %d, j = %d\n", i, j);
//                 if(i ==3 && j ==5){
//                     printf("i = 3, j = 5\n");
//                     goto bottom;
//                     break;
//                 }
//             }
//         }  
//     }
//     bottom:
//     return 0;
// }








// int main(int argc, char const *argv[])
// {
//     int key = 0;
//     top:
//     do
//     {
//         printf("Chuong trinh test\n");
//         printf("Case1: Noi dung 1\n");
//         printf("Case2: Noi dung 2\n");
//         scanf("%d", &key);
//     } while (key != 1 && key != 2);

//     switch (key)
//     {
//     case 1:
//         printf("Chuong trinh 1\n");
//         goto top;
//         break;
//     case 2:
//         printf("Chuong trinh 2\n");
//         goto top;
//         break;
//     default:
//         break;
//     }
//     return 0;
// }

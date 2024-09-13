#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(){
    uint8_t *ptr = (uint8_t *)malloc(sizeof(uint8_t)*5);//cấp phát động, phải ép kiểu
    for(int i = 0; i < 5; i++){
        ptr[i] = 2*i;
    }   
    for (int i = 0; i < 5; i++)
    {
        printf("i = %d\n", ptr[i]);
    }

    printf("---------------\n");
    //thay đổi kích thước bộ nhớ
    ptr = (uint8_t *)realloc(ptr, sizeof(uint8_t)*7);
    for(int i = 0; i < 7; i++){
        ptr[i] = 3*i;
    }   
    for (int i = 0; i < 7; i++)
    {
        printf("i = %d\n", ptr[i]);
    }
    return 0;
    //free(ptr);
}
// void tong(int a, int b){ //a, b là input parameters
//     int c = a + b; //c là biến cục bộ
//     printf("Tong %d va %d la: %d\n", a, b, c);
// }

// int main(){
//     tong(5, 7); 

//     tong(2, 9);
//     return 0;
// }
// int main(){
//     int array[] = {1, 7, 3, 5, 9};
//     for(int i = 0; i < 5; i++){
//         printf("Dia chi: %p\n", array+i);
//     }
//     return 0;
// }

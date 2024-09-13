#include <stdio.h>

#define CREAT_FUNC(name, cmd)                   \
void name(){                                    \
    printf("%s", (char*)#cmd);                   \
}//Thêm dấu #trước 1 label sẽ đc tự hiểu là 1 chuỗi

#define CREAT_VAR(name)     \
int name__##var1;           \
int name__##var2;           \
int name__##var3;       //sử dụng ## được gọi là nối chuỗi tức là cái label mình truyền vào sẽ được nối vào chuỗi

CREAT_FUNC(test1, this is test);
CREAT_FUNC(test2, This is test2);

#define VAR(...) __VA_ARGS__

int main(int argc, char const *argv[])
{
    VAR(int a, int b, int c;);
    return 0;
}



// #define SIZE 30
// #if SIZE == 20
// void display(){
//     printf("size: 20\n");
// }
// #elif SIZE > 20

// void display(){
//     printf("size: >20\n");
// }

// #else

// void display(){
//     printf("size: <20\n");
// }

// #endif


// int main(int argc, char const *argv[])
// {
//     display();
//     return 0;
// }

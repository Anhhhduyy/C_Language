#include <stdio.h>
#include "test.c"

#define MAX 20
#define SUM(a, b) a + b

//This is function
void display(){
    printf("This is main.c\n");
}

int main(int argc, char const *argv[])
{
    int array[MAX];
    printf("Tong a va b: %d\n", SUM(4, 5));

    //display
    display();
    //file test.c
    test();
    return 0;
}

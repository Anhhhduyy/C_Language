#include <stdio.h>


static int i = 10;

static void count(){
    printf("i = %d\n", i);
    i++;
}

typedef struct
{   
    double x1;
    double x2;

} result;

void temp(){
    count();
}
//VD
void input(int a, int b, int c);
double getDelta(int a, int b, int c);

result output(){
    result var;
    return var;
}
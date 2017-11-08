#include <stdio.h>

typedef union {
    char ch;
    int i;
    double d;
} test_union;

int main(int argc,char* argv[]){
    test_union uni;
    scanf("%x",&(uni.i));
    printf("double:%x\n",uni.d);
    printf("int:%x\n",uni.i);
    printf("char:%x\n",uni.ch);
    return 0;
}

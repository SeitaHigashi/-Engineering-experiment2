#include <stdio.h>
#include <stdlib.h>

typedef struct{
    double x,y;
} input;

typedef struct{
    double sum,diff,pro,quo;
} output;

output calc(input in){
    output out;
    if(!in.y)exit(1);
    out.sum = in.x + in.y;
    out.diff = in.x - in.y;
    out.pro = in.x * in.y;
    out.quo = in.x / in.y;
    return out;
}

int main(int argc,char* argv[]){
    input in;
    output out;
    scanf("%lf %lf",&(in.x),&(in.y));
    out = calc(in);
    printf("sum:%lf\n",out.sum);
    printf("diff:%lf\n",out.diff);
    printf("pro:%lf\n",out.pro);
    printf("quo:%lf\n",out.quo);
    return 0;
}

#include <stdio.h>

void swap(void*,void*,int);

int main(){
    double x=100,y=-5634;

    printf("%lf %lf\n",x,y);

    printf("%lu %lu\n",sizeof(int),sizeof(char));
    swap(&x,&y,sizeof(double));

    printf("%lf %lf\n",x,y);

}

void swap(void* inputx,void* inputy,int size){
    char* x=(char*)inputx;
    char* y=(char*)inputy;
    char temp;
    for(int i=0;i<size;i++){
        temp=x[i];
        x[i]=y[i];
        y[i]=temp;
    }
}

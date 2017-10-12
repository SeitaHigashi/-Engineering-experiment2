#include <stdio.h>

void swap(void*,void*,int);

int main(){
    double x=100,y=-5634;
    int i1=200,i2=543;
	printf("x=%lf y=%lf\n",x,y);

    swap(&x,&y,sizeof(double));

    printf("x=%lf y=%lf\n",x,y);


    printf("i1=%d i2=%d\n",i1,i2);

    swap(&i1,&i2,sizeof(int));

    printf("i1=%d i2=%d\n",i1,i2);
    return 0;
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

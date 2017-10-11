#include <stdio.h>

void swap(void*,void*,int);

int main(){
    int x[]={1,2,3,4,5,6,7,8,9};
    int y[]={9,8,7,6,5,4,3,2,1};

    for(int i=0;i<9;i++)printf("x[%d]=%d,y[%d]=%d\n",i,x[i],i,y[i]);

    swap(&x,&y,sizeof(x));
    puts("swap");

    for(int i=0;i<9;i++)printf("x[%d]=%d,y[%d]=%d\n",i,x[i],i,y[i]);
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

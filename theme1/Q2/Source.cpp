#include <stdio.h>

int main(){
	int a[5];
	int *p;
	a[0]=10;a[1]=20;a[2]=30;a[3]=40;a[4]=50;
	p=a;
	printf("%d,%d,%d,%d,%d\n",*p,*(p+1),*(p+2),*(p+3),*(p+4));
	printf("%d,%d,%d,%d,%d\n",*p,*p+1,*p+2,*p+3,*p+4);
	return 0;
}

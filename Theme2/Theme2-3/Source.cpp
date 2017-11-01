#include <stdio.h>

void calc(double* num){
	num[2]=num[0]+num[1];
	num[3]=num[0]-num[1];
	num[4]=num[0]*num[1];
	num[5]=num[0]/num[1];
	return;
}

int main(){
	double num[6]={86436432,46436342};
	calc(num);
	for(int i=0;i<6;i++)printf("num[%d]=%lf",i,num[i]);
	return 0;
}

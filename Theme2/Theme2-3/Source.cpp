#include <stdio.h>

void calc(double* num){
	num[2]=num[0]+num[1];
	num[3]=num[0]-num[1];
	num[4]=num[0]*num[1];
	num[5]=num[0]/num[1];
	return;
}

int main(){
	double num[6]={8,4};
	calc(num);
	for(int i=0;i<6;i++)printf("num[%d]=%d",i,num[i]);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>

void calc(double* num){
	if(num[1]==0.0)exit(1);
	num[2]=num[0]+num[1];
	num[3]=num[0]-num[1];
	num[4]=num[0]*num[1];
	num[5]=num[0]/num[1];
	return;
}

int main(){
	double num[6]={8,5};
	calc(num);
	for(int i=0;i<6;i++)printf("num[%d]=%lf\n",i,num[i]);
	return 0;
}
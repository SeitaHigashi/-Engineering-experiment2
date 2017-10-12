#include <stdio.h>

int main(){
	int j,i=0;
	char c[21];//={NULL};
	for(j=i=0;i<10;i++,j++){
		scanf("%s%*c",&c[j]);
		if(c[j+1]!=NULL)j++;
		printf("%s\n",c);
	}
	return 0;
}
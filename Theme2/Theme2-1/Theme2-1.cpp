#include <stdio.h>

void scanprint(){
	char str[30]={NULL};
	while(scanf("%s",str)!=EOF)printf("%s\t(END=>CTRL+Z)\n",str);
	return;
}

int main(){
	scanprint();
	return 0;
}
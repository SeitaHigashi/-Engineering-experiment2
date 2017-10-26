#include <stdio.h>

void print(const char* str){
	printf("%s\n",str);
	return;
}

int main(){
	char str[30];
	scanf("%s",str);
	print(str);
	return 0;
}
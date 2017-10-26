#include <stdio.h>

#define NUM 13

int main(){
	_int64 dest=1;
	for(int i=2;i<=NUM;i++)dest*=i;
	printf("%I64llu\n",dest);
	return 0;
}
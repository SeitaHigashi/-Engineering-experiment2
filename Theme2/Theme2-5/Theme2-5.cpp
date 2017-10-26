#include <stdio.h>

_int64 Factorial(_int64 i){return (i==0)?1:i*Factorial(i-1);}

int main(){
	printf("%I64llu\n",Factorial(13));
	return 0;
}
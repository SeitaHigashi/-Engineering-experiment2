#include <stdio.h>

int main(int argv,char* argc[]){
	for(int i=0;i<argv;i++)printf("%s\n",argc[i]);
		return 0;
}
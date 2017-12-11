#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

int main(int argc,char* argv[]){
    FILE *read_p,*write_p;
    char str[SIZE];
    int i,string=0;
    if(!(read_p=fopen("Theme4-3Ex.cpp","r")))exit(1);
    if(!(write_p=fopen("Theme4-3Ex.txt","w")))exit(1);
    for(i=0;fgets(str,SIZE,read_p)!=NULL;i++){
        fprintf(stdout,"%s",str);
        fprintf(write_p,"%3d:%s",i,str);
		string+=strlen(str);
	}
	fprintf(stdout,"%d\n",string);
	fclose(read_p);
	fclose(write_p);
	getchar();
    return 0;
}

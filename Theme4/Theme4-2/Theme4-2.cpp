#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[]){
    FILE *read_p,*write_p;
    char c;
	int i;
	int count=0;
    if(!(read_p=fopen("Theme4-2.cpp","r")))exit(1);
    if(!(write_p=fopen("Theme4-2.txt","w")))exit(1);
    for(i=0;(c=fgetc(read_p)) != EOF;i++){
        fprintf(stdout,"%c",c);
        fputc(c,write_p);
    }
	fprintf(stdout,"\n%d\n",i);
	fclose(read_p);
    fclose(write_p);
	getchar();
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[]){
    FILE *read_p,*write_p;
    char c;
	int i;
	int count=0;
    if(!(read_p=fopen("Theme4-2Ex.cpp","r")))exit(1);
    if(!(write_p=fopen("Theme4-2Ex.txt","w")))exit(1);
    for(i=0;(c=fgetc(read_p)) != EOF;i++){
        fprintf(stdout,"%c",c);
        fputc(c,write_p);
		if(c!='\n')count++;
    }
	fprintf(stdout,"\n%d\n",i);
	fprintf(stdout,"count:%d\n",count);
	fclose(read_p);
    fclose(write_p);
	getchar();
    return 0;
}
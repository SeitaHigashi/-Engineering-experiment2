#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[]){
    FILE *read_p,*write_p;
    char c;
    if(!(read_p=fopen("Theme4-2.cpp","rb")))exit(1);
    if(!(write_p=fopen("Theme4-2.txt","w")))exit(1);
    while((c=fgetc(read_p)) != EOF){
        fprintf(stdout,"%c",c);
        fprintf(write_p,"%c",c);
    }
    fclose(read_p);
    fclose(write_p);
    return 0;
}
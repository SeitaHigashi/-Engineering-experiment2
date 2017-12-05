#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[]){
    FILE *fp;
    char c;
    int i;
    if(!(fp=fopen("Theme4-4.cpp","rb")))exit(1);
    fread(&c,sizeof(char),(size_t)1,fp);
    while(feof(fp)==0){
        printf("%c",c);
        fread(&c,sizeof(char),(size_t)1,fp);
    }
    return 0;
}

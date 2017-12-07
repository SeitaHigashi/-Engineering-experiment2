#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int main(int argc,char* argv[]){
    FILE *read_p,*write_p;
    char str[SIZE];
    int i;
    if(!(read_p=fopen("Theme4-3.cpp","r")))exit(1);
    if(!(write_p=fopen("Theme4-3.txt","w")))exit(1);
    for(i=1;fgets(str,SIZE,read_p)!=NULL;i++){
        fprintf(stdout,"%s",str);
        fprintf(write_p,"%d:%s",i,str);
    }
    fclose(read_p);
    fclose(write_p);
    return 0;
}

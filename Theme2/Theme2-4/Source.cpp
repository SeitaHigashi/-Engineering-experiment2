#include <stdio.h>
#include <stdlib.h>

char* Combining(char*,char*);

int main(void){
    char* str;
    str=Combining("Hello ","World!");
    puts(str);
    free(str);
    return 0;
}

char* Combining(char* str1,char* str2){
    int i,j;
    char *dest;
    for(i=0;str1[i]!='\0';i++);
    for(j=0;str2[j]!='\0';j++);
    dest = (char*)calloc(i+j+1,sizeof(char));
    if(dest == NULL)exit(0);
    for(i=0;str1[i]!='\0';i++)dest[i]=str1[i];
    for(j=0;str2[j]!='\0';j++)dest[i+j]=str2[j];
    dest[i+j+1]='\0';
    return dest;
}

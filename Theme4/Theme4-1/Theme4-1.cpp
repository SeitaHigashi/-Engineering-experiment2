#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[]){
    int data;
    FILE* fp;
    scanf("%d",&data);
    if(!(fp=fopen("print_text.txt","w"))) exit(1);
    fprintf(fp,"%d",data);
    fclose(fp);
    if(!(fp=fopen("print_binary.binaly","wb"))) exit(1);
    fwrite(&data,sizeof(int),(size_t)1,fp);
    fclose(fp);
    return 0;
}

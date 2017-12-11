#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[]){
    FILE *fp,*write_p;
    char c;
    int i=0;
	if(!(fp=fopen("Picture/75cdc7843f030e4dc0f112d6d74dff47.jpg","rb"))){fprintf(stderr,"error");exit(1);}
    if(!(write_p=fopen("Theme4-5.jpg","wb")))exit(1);
    fread(&c,sizeof(char),(size_t)1,fp);
    while(feof(fp)==0){
        fprintf(write_p,"%c",c);
        fread(&c,sizeof(char),(size_t)1,fp);
        i++;
    }
    printf("%d\n",i);
    fclose(fp);
    fclose(write_p);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int main(int argc,char* argv[]){
    FILE *fp;
    char c;
    char filename[SIZE];
    char writemode[SIZE];
    printf("filename:");
    scanf("%s",filename);
    printf("writemode(w/a):");
    scanf("%s%*c",writemode);
    while(writemode[1]!= '\0' || ( writemode[0]!='w' && writemode[0]!='a')){
    printf("retype writemode(w/a):");
    scanf("%s%*c",writemode);
    }
    if(!(fp=fopen(filename,writemode)))exit(1);
    puts("start writting(END(CTRL-Z))");
    while((c=fgetc(stdin)) != EOF){
        fprintf(fp,"%c",c);
    }
    fclose(fp);
    return 0;
}

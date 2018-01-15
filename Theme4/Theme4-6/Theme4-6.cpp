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
    while(!(writemode[1]== '\0' || writemode[1]=='b' || writemode[1]=='t') || ( writemode[0]!='w' && writemode[0]!='a')){
    printf("retype writemode(w/a):");
    scanf("%s%*c",writemode);
    }
    if(!(fp=fopen(filename,writemode)))exit(1);
    puts("start writting(END(CTRL-Z))");
    if(writemode[1]=='b'){
		fread(&c,sizeof(char),(size_t)1,stdin);
        while(c != EOF){
            fwrite(&c,sizeof(char),(size_t)1,fp);
		    fread(&c,sizeof(char),(size_t)1,stdin);
		}
	}else{
        while((c=fgetc(stdin)) != EOF){
            fprintf(fp,"%c",c);
        }
	}
    fclose(fp);
    return 0;
}

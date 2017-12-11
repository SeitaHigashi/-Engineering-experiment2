#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100
#define YSIZE 100
#define XSIZE 100

char* strcharcat(char,char*);

int main(int argc,char* argv[]){
    FILE *fp;
    char c;
    char filename[SIZE];
    char writemode[SIZE];
	char readstring[YSIZE][XSIZE];
	int i,j;

	//Initialize
	for(j=0;j<YSIZE;j++){
		for(i=0;i<XSIZE;i++){
			readstring[j][i]=NULL;
		}
	}

	//FileSelect
    printf("filename:");
    scanf("%s%*c",filename);
    printf("writemode(w/a):");
    scanf("%s%*c",writemode);
    while(writemode[1]!= '\0' || ( writemode[0]!='w' && writemode[0]!='a')){
    printf("retype writemode(w/a):");
    scanf("%s%*c",writemode);
    }

	//FileOpen
    if(!(fp=fopen(filename,"a")))exit(1);
	fclose(fp);
    if(!(fp=fopen(filename,"r")))exit(1);
	for(i=0;i<YSIZE;i++){
	if(writemode[0] == 'a')if(fgets(readstring[i],XSIZE,fp)==NULL)readstring[i][0]='\n';
	if(writemode[0] == 'w')readstring[i][0]='\n';
	}
	fclose(fp);
    if(!(fp=fopen(filename,"w")))exit(1);

	//WriteStart
    puts("start writting(END(CTRL-Z))");
    for(i=0;(c=fgetc(stdin)) != EOF;i++){
		if(c=='\n'){
			for(j=i;j<YSIZE;j++){
				strcharcat(' ',readstring[j]);
			}
			i=-1;
		}else{
			strcharcat(c,readstring[i]);
		}
    }

	for(i=0;i<YSIZE;i++){
		fprintf(fp,"%s",readstring[i]);
	}
	//FileClose
    fclose(fp);
    return 0;
}

char *strcharcat(char c,char* str){
	char s[XSIZE+1]={NULL};
	int i;
	s[0]=c;
	strcat(s,str);
	for(i=0;i<XSIZE;i++)str[i]=s[i];
	return str;
}
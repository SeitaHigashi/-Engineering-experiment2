#include <stdio.h>
#include <stdlib.h>

#define STRING_MAX 50
#define DATA_MAX 100

typedef char string[STRING_MAX];
typedef char human_data[4][STRING_MAX];

int now_number(human_data**);
void new_data(human_data**);
void list_data(human_data**);
void print_data(human_data*);

int main(int argc,char* argv[]){
    human_data* data[100]={NULL};
    char c[10];
    while(1){
        puts("Plese select operation for data\n1:Add 2:View_all_data 3:Exit");
        scanf("%s",c);
        switch(c[0]){
            case '1':new_data(data);break;
            case '2':list_data(data);break;
            case '3':exit(1);
default: puts("Type it again");break;
        }
    }
	return 0;
}

int now_number(human_data** data){
    int i=0;
    for(i=0; (i<DATA_MAX) && (*data[i]!=NULL);i++);
    return i;
}

void new_data(human_data** data){
    human_data* ptr;
    if((ptr = (human_data*)calloc((size_t)1,sizeof(human_data)))==NULL){puts("Memory Error");exit(1);}
    puts("Set Name");
    scanf("%s",(*ptr)[0]);
    puts("Set Grade");
    scanf("%s",(*ptr)[1]);
    puts("Set Class");
    scanf("%s",(*ptr)[2]);
    puts("Set Number");
    scanf("%s",(*ptr)[3]);
    data[now_number(data)]=ptr;
}

void list_data(human_data** data){
    int i=0;
    int now=now_number(data);
    puts("--DATA LIST--");
    for(i=0;i<now;i++){
        printf("%d:\n",i);
        print_data(data[i]);
    }
}

void print_data(human_data* data){
    printf("Name:%s\n",(*data)[0]);
    printf("Grade:%s\n",(*data)[1]);
    printf("Class:%s\n",(*data)[2]);
    printf("Number:%s\n",(*data)[3]);
}

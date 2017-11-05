#include <stdio.h>

void print(char*,int,char,int);

int main(int argc,char* argv[]){
    char name_data[60];
    int grade_data;
    char class_data;
    int number_data;
    scanf("%s %d %c %d",name_data,&grade_data,&class_data,&number_data);
    print(name_data,grade_data,class_data,number_data);
    return 0;
}

void print(char* name_data,int grade_data,char class_data,int number_data){
    printf("Name:%s\n",name_data);
    printf("Grade:%d\n",grade_data);
    printf("Class:%c\n",class_data);
    printf("Number:%d\n",number_data);
    return;
}

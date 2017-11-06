#include <stdio.h>

#define NAME_SIZE 60

typedef struct {
    char name_data[NAME_SIZE];
    int grade_data;
    char class_data;
    int number_data;
} Human;

void input(Human*);
void print(Human);

int main(int argc,char* argv[]){
    Human human;
    input(&human);
    print(human);
    return 0;
}

void input(Human* human){
    scanf("%s %d %c %d",human->name_data,&(human->grade_data),&(human->class_data),&(human->number_data));
}

void print(Human human){
    printf("Name:%s\n",human.name_data);
    printf("Grade:%d\n",human.grade_data);
    printf("Class:%c\n",human.class_data);
    printf("Number:%d\n",human.number_data);
    return;
}

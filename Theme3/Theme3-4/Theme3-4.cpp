#include <stdio.h>

#define NAME_SIZE 64

typedef struct {
    char name_data[NAME_SIZE];
    int grade_data;
    char class_data;
    int number_data;
} Human;

void print(Human);

int main(int argc,char* argv[]){
    Human human; 

    printf("human:%d\n",sizeof(human));
    printf("human.name_data:%d\n",sizeof(human.name_data));
    printf("human.grade_data:%d\n",sizeof(human.grade_data));
    printf("human.class_data:%d\n",sizeof(human.class_data));
    printf("human.number_data:%d\n",sizeof(human.number_data));
   
    printf("member_all:%d\n",sizeof(human.name_data)+sizeof(human.grade_data)+sizeof(human.class_data)+sizeof(human.number_data));

    return 0;
}


void print(Human human){
    printf("Name:%s\n",human.name_data);
    printf("Grade:%d\n",human.grade_data);
    printf("Class:%c\n",human.class_data);
    printf("Number:%d\n",human.number_data);
    return;
}

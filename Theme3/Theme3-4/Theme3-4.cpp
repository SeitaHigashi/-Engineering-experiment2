#include <stdio.h>

#define NAME_SIZE 60

typedef struct {
    char name_data[NAME_SIZE];
    int grade_data;
    char class_data;
    int number_data;
} Human;

Human input();
void print(Human);

int main(int argc,char* argv[]){
    Human human = input();
    print(human);

    printf("human:%d\n",sizeof(human));
    printf("human.name_data:%d\n",sizeof(human.name_data));
    printf("human.grade_data:%d\n",sizeof(human.grade_data));
    printf("human.class_data:%d\n",sizeof(human.class_data));
    printf("human.number_data:%d\n",sizeof(human.number_data));
   
    printf("menber_all:%d\n",sizeof(human.name_data)+sizeof(human.grade_data)+sizeof(human.class_data)+sizeof(human.number_data));

    return 0;
}

Human input(){
    Human human;
    char name_data[NAME_SIZE];
    int grade_data;
    char class_data;
    int number_data;
    scanf("%s %d %c %d",name_data,&grade_data,&class_data,&number_data);
    for(int i=0;i<NAME_SIZE;i++)human.name_data[i]=name_data[i];
    human.grade_data=grade_data;
    human.class_data=class_data;
    human.number_data=number_data;
    return human;
}

void print(Human human){
    printf("Name:%s\n",human.name_data);
    printf("Grade:%d\n",human.grade_data);
    printf("Class:%c\n",human.class_data);
    printf("Number:%d\n",human.number_data);
    return;
}

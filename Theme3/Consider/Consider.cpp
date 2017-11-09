#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENT 10

typedef struct{
	char name_data[100];
	int grade_data;
	char class_data[10];
	int number_data;
} Student;

void add_student(Student* data[]);
void print_student(Student* data[]);
void delete_student(Student* data[]);

int main(int argc,char* argv[]){
	Student* data[MAX_STUDENT]={NULL};
	char select;
	while(1){
		printf("1:add 2:print 3:delete 4:exit\n");
		scanf("%c%*c",&select);
		switch (select)
		{
		case '1':add_student(data);break;
		case '2':print_student(data);break;
		case '3':delete_student(data);break;
		case '4':exit(1);
		default:
			break;
		}
	}
	return 0;
}

void add_student(Student* data[]){
	Student* newdata;
	int i;
	newdata = (Student*)calloc(1,sizeof(Student));
	printf("Name:");
	scanf("%s",newdata->name_data);
	printf("Grade:");
	scanf("%d",&(newdata->grade_data));
	printf("Class:");
	scanf("%s",newdata->class_data);
	printf("Number:");
	scanf("%d",&(newdata->number_data));
	for(i=0;i<=MAX_STUDENT;i++){
		if(i!=MAX_STUDENT && data[i]==NULL){
			data[i]=newdata;
			return;
		}else if(i==MAX_STUDENT){
			puts("data of max");
			return;
		}
	}
}

void print_student(Student* data[]){
	int i;
	for(i=0;i<MAX_STUDENT && data[i]!=NULL;i++){
		printf("%d:\tName:%s\n",i+1,data[i]->name_data);
		printf("\tGrade:%d\n",data[i]->grade_data);
		printf("\tClass:%s\n",data[i]->class_data);
		printf("\tNumber:%d\n",data[i]->number_data);
	}
	return;
}

void delete_student(Student* data[]){
	int i;
	puts("number of delete");
	scanf("%d",&i);
	i--;
	free(data[i]);
	data[i]=NULL;
	for(;data[i+1]!=NULL;i++){
		data[i]=data[i+1];
	}
	data[i]=NULL;
	return;
}
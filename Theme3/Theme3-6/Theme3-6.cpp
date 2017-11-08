#include <stdio.h>

typedef struct {
    int total = 94;
    int general = 58;
    int special = 28;
} credit_type;

typedef struct {
    int grade = 3;
    char classroom = 'I';
    char name[15]= {'T','a','k','u','m','i','F','u','k','u','m','o','t','o','\0'};
    //char *name = "TakumiFukumoto";
    int number = 39;
    credit_type credit;
} Human;

int main(int argc,char* argv[]){
    Human takumi;
    printf("grade:\t%d\n",takumi.grade);
    printf("classroom:\t%c\n",takumi.classroom);
    printf("name:\t%s\n",takumi.name);
    printf("number\t%d\n",takumi.number);
    printf("credit.total:\t%d\n",takumi.credit.total);
    printf("credit.general:\t%d\n",takumi.credit.general);
    printf("credit.special:\t%d\n",takumi.credit.special);
    return 0;
}

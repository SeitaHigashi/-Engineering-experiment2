#include <stdio.h>

typedef struct {
    int total;
    int general;
    int special;
} credit_type;

typedef struct {
    int grade;
    char classroom;
    char name[15];
    int number;
    credit_type credit;
} Human;

int main(int argc,char* argv[]){
	Human takumi = {3,'I',"TakumiFukumoto",39,{94,58,28}};
    printf("grade:\t%d\n",takumi.grade);
    printf("classroom:\t%c\n",takumi.classroom);
    printf("name:\t%s\n",takumi.name);
    printf("number\t%d\n",takumi.number);
    printf("credit.total:\t%d\n",takumi.credit.total);
    printf("credit.general:\t%d\n",takumi.credit.general);
    printf("credit.special:\t%d\n",takumi.credit.special);
    return 0;
}

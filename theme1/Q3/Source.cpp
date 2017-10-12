#include <stdio.h>

int main(){
    char str[50]={};
    char *point;
    int i;

    scanf("%s",str);
    scanf("%d",&i);

    str[i+4]='\0';
    point=&str[i-1];

    printf("%s\n",point);

    return 0;
}
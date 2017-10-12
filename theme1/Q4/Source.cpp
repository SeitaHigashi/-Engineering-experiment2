#include <stdio.h>

typedef struct{
    double add,sub,multi,div,avg;
}Anser;

Anser calc(double x,double y){
    Anser ans;
    ans.add=x+y;
    ans.sub=x-y;
    ans.multi=x*y;
    ans.div=(y!=0)?x/y:NULL;
    ans.avg=(x+y)/2;
    return ans;
}

int main(){
    Anser ans;
    double x,y;
    scanf("%lf %lf",&x,&y);
    ans=calc(x,y);
    printf("add:%lf\n",ans.add);
    printf("sub:%lf\n",ans.sub);
    printf("multi:%lf\n",ans.multi);
    printf("div:%lf\n",ans.div);
    printf("avg:%lf\n",ans.avg);
    return 0;
}
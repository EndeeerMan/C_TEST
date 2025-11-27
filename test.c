#include <stdio.h>
#include <stdlib.h>

enum DAY{MON = 1,TUE,WED,THU,FRI,SAT,SUN};

int main(){
    enum DAY day;
    int x;
    scanf("%d",&x);
    day = (enum DAY)x;
    printf("%d\n",day);
}
#include <stdio.h>

struct Player{
    int FC;
    int AP;
    float Score;
    int Rating;
};

void updatescore(struct Player *p){
    scanf("%d %d %f %d",&p->FC,&p->AP,&p->Score,&p->Rating);
}

int main(){
    struct Player loogbee[5];
    for(int i=0;i<=4;i++){
        scanf("%d %d %f %d",&loogbee[i].FC,&loogbee[i].AP,&loogbee[i].Score,&loogbee[i].Rating);
    }
    int sw = 0;
    scanf("%d",&sw);
    updatescore(&loogbee[sw]);

    printf("%d %d %.4f %d",loogbee[sw].FC,loogbee[sw].AP,loogbee[sw].Score,loogbee[sw].Rating);
}
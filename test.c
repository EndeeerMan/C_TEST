#include <stdio.h>
# define N 50
# define M 11

void fun(int *a, int *b)
{



}

double rnd( )
{
    static t=29,c=217,m=1024,r=0;
    r=(r*t+c)%m;
    return((double) r/m);
}

void main( )
{
    int age[N], i,d[M];
    for(i=0;i<N;i++)
        age[i]=(int)(115*rnd( ));
    /* 产生一个随机的年龄数组 */
    printf("The original data:\n");
    for(i=0;i<N;i++)
        printf((i+1)%10==0? "%4d\n":"%4d", age[i]); /* 每行输出 10 个数 */
    printf("\n\n");
    
    fun(age,d);
    
    for(i=0;i<10;i++)
        printf("%4d-%4d:%4d\n", i*10, i*10+9,d[i]);
    printf("Over 100:%4d\n",d[10]);
}
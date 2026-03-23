#include <stdio.h>
#include <string.h>

void fun(char *s, char t[])
{
    int i,j=0;
    for(i=0;i<=99,j<=99;i++,j++){
        if(s[j] == '\0' || s[j] == '\n'){
            t[i] = '\0';
            return;
        }
        if(s[j] % 2 == 0 && !(s[j] == 0)){
            t[i] = s[j];
            continue;
        }else{
            continue;
        }
    }    
    t[i] = '\0';
}

int main()
{
    char s[100], t[100];
    
    printf("\nPlease enter string s:");
    scanf("%s", s);
    
    fun(s, t);
    
    printf("\nThe result is:%s\n", t);
}
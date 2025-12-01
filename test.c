#include <stdio.h>
#include <stdlib.h>

void modify(char **arr,int m,int n){
    int counter = 0;
    for(int i=0;i<=m-1;i++){
        for(int r=0;r<n-1;r++){
            if(arr[i][r] == '*') continue;
            if(i == 0){
                if(r == 0){//贴左上角的，有3格
                    if(arr[i][r+1] == '*') counter++;
                    if(arr[i+1][r] == '*') counter++;
                    if(arr[i+1][r+1] == '*') counter++;
                    arr[i][r] == counter + '0';
                    counter = 0;
                }else if(r == n-1){//贴右上角的，有3格
                    if(arr[i][r-1] == '*') counter++;
                    if(arr[i+1][r] == '*') counter++;
                    if(arr[i+1][r-1] == '*') counter++;
                    arr[i][r] = counter + '0';
                    counter = 0;
                }else{//贴上边界的，有5格
                    if(arr[i][r-1] == '*') counter++;
                    if(arr[i][r+1] == '*') counter++;
                    if(arr[i+1][r-1] == '*') counter++;
                    if(arr[i+1][r] == '*') counter++;
                    if(arr[i+1][r+1] == '*') counter++;
                    arr[i][r] = counter + '0';
                    counter = 0;
                }
            }else if(i == m-1){
                if(r == 0){//贴左下角的
                    if(arr[i+1][r] == '*') counter++;
                    if(arr[i+1][r+1] == '*') counter++;
                    if(arr[i][r+1] == '*') counter++;
                    arr[i][r] = counter + '0';
                    counter = 0;
                }else if(r == n-1){//贴右下角的
                    if(arr[i-1][r-1] == '*') counter++;
                    if(arr[i-1][r] == '*') counter++;
                    if(arr[i][r-1] == '*') counter++;
                    arr[i][r] = counter + '0';
                    counter = 0;
                }else{//贴下边界的
                    if(arr[i-1][r-1] == '*') counter++;
                    if(arr[i-1][r] == '*') counter++;
                    if(arr[i-1][r+1] == '*') counter++;
                    if(arr[i][r-1] == '*') counter++;
                    if(arr[i][r+1] == '*') counter++;
                    arr[i][r] = counter + '0';
                    counter = 0;
                }
            }else{
                if(r == 0){//贴左边界的
                    if(arr[i-1][r] == '*') counter++;
                    if(arr[i-1][r+1] == '*') counter++;
                    if(arr[i][r+1] == '*') counter++;
                    if(arr[i+1][r] == '*') counter++;
                    if(arr[i+1][r+1] == '*') counter++;
                    arr[i][r] = counter + '0';
                    counter = 0;
                }else if(r == n-1){//贴右边界的
                    if(arr[i-1][r-1] == '*') counter++;
                    if(arr[i-1][r] == '*') counter++;
                    if(arr[i][r-1] == '*') counter++;
                    if(arr[i+1][r-1] == '*') counter++;
                    if(arr[i+1][r] == '*') counter++;
                    arr[i][r] = counter + '0';
                    counter = 0;
                }else{//没贴边的，有8格
                    if(arr[i-1][r-1] == '*') counter++;
                    if(arr[i-1][r] == '*') counter++;
                    if(arr[i-1][r+1] == '*') counter++;
                    if(arr[i][r-1] == '*') counter++;
                    if(arr[i][r+1] == '*') counter++;
                    if(arr[i+1][r-1] == '*') counter++;
                    if(arr[i+1][r] == '*') counter++;
                    if(arr[i+1][r+1] == '*') counter++;
                    arr[i][r] = counter + '0';
                    counter = 0;
                }
            }
        }
    }
}

int main(){
    int m,n,k;
    scanf("%d %d %d",&m,&n,&k);
    char arr[m][n+1];
    int x,y;
    for(int i=1;i<=k;i++){
        scanf("%d %d",&x,&y);
        arr[x-1][y-1] = '*';
    }
    
}
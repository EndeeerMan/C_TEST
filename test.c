/*
扫雷图表生成代码
先输入 行数 列数 地雷数量（小于等于总区块数量）
再循环读入用户输入的各个地雷坐标
最后输出地雷分布表
*/
#include <stdio.h>
#include <stdlib.h>

int judgement(char **arr,int x,int y){
    if(arr[x][y] == '*') return 1;
    return 0;
}

void modify(char **arr,int m,int n){
    for(int i=0;i<=m-1;i++){
        for(int r=0;r<=n-1;r++){
            if(arr[i][r] != '*'){
                int counter = 0;
                if(i-1 >= 0 && r-1 >= 0){//左上角
                    if(judgement(arr,i-1,r-1)) counter++;
                }
                if(i+1 <= m-1 && r+1 <= n-1){//右下角
                    if(judgement(arr,i+1,r+1)) counter++;
                }
                if(i-1 >= 0 && r+1 <= n-1){//右上角
                    if(judgement(arr,i-1,r+1)) counter++;
                }
                if(i+1 <= m-1 && r-1 >= 0){//左下角
                    if(judgement(arr,i+1,r-1)) counter++;
                }
                if(i-1 >= 0){//上
                    if(judgement(arr,i-1,r)) counter++;
                }
                if(r-1 >= 0){//左
                    if(judgement(arr,i,r-1)) counter++;
                }
                if(i+1 <= m-1){//右
                    if(judgement(arr,i+1,r)) counter++;
                }
                if(r+1 <= n-1){//下
                    if(judgement(arr,i,r+1)) counter++;
                }
                arr[i][r] += counter;
            }
        }
    }
}

char** mineswp(int m,int n,int k){
        char **arr = NULL;
        arr = malloc(m*sizeof(char*));//分配行
        if(arr == NULL) exit(1);//检查空指针风险
        if(k > m*n) exit(1);
        for(int i=0;i<=m-1;i++){
            arr[i] = malloc((n+1)*sizeof(char));//分配所有列（+1为'\0'空位）
            for(int r=0;r<=n-1;r++) arr[i][r] = '0';//先全写上'0'
            arr[i][n] = '\0';
            if(arr[i] == NULL) exit(1);//检查空指针风险
        }
        int x,y;//存储地雷坐标
        for(int i=1;i<=k;i++){
            scanf("%d %d",&x,&y);
            arr[x][y] = '*';
        }

        modify(arr,m,n);
        return arr;
        /*for(int i=0;i<=m-1;i++){
            printf("%s\n",arr[i]);
            free(arr[i]);//回收列
        }
        free(arr);//回收行 
        */
}

int main(){
    char **arr = NULL;//二维数组，每行存储一串字符串
    int m,n,k;//横纵规模、地雷数量（k <= m * n)
    while(scanf("%d %d %d",&m,&n,&k)){

    }
}
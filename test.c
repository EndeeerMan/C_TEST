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
                for(int j=-1;j<=1;j++){
                    for(int k=-1;k<=1;k++){
                        if(i+j <= m-1 && i+j >= 0 && r+k <= n-1 && r+k >= 0 && (j != 0 || k != 0)){
                            if(judgement(arr,i+j,r+k)) counter++;
                        }
                    }
                }
                arr[i][r] += counter;
            }
        }
    }
}

int main(){
    char **arr = NULL;//二维数组，每行存储一串字符串
    int m,n,k;//横纵规模、地雷数量（k <= m * n)
    scanf("%d %d %d",&m,&n,&k);
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
        arr[x-1][y-1] = '*';
    }

    modify(arr,m,n);
    for(int i=0;i<=m-1;i++){
        printf("%s\n",arr[i]);
        free(arr[i]);//回收列
    }
    free(arr);//回收行 
}
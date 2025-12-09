#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int Scan_Surroundings(char **mine_grid,int x,int y,int m,int n){
    int counter = 0;
    for(int i=-1;i<=1;i++){ //行扫描
        for(int r=-1;r<=1;r++){ //列扫描
            if(x+i >= 0 && x+i <= m-1 && y+r >= 0 && y+r <= n-1){ //避免非法访问
                if(mine_grid[x+i][y+r] == '*') counter++;
            }
        }
    }
    return counter;
}

void Generate(char **mine_grid,int m,int n){ //原始的雷区，行数，列数
    for(int i=0;i<=m-1;i++){ //行扫描
        for(int r=0;r<=n-1;r++){ //列扫描
            if(mine_grid[i][r] != '*'){
                mine_grid[i][r] = Scan_Surroundings(mine_grid,i,r,m,n) + '0';
            }
        }
    }
}

int Write_Output_Context(char **output_context,char **mine_grid,int m,int n,int last_row){ //输出字符串，雷区，雷区行数，雷区列数，上一次写入的行数。
    int returning_row = last_row+1;
    for(int i=0;i<=m-1;i++){ //雷区行扫描
        for(int r=last_row+1;r<=last_row+1+m;r++){ //输出内容行扫描
            output_context = realloc(output_context,r*sizeof(char*));
            if(output_context == NULL) exit(1);
            output_context[r] = malloc((n+1)*sizeof(char));
            if(output_context[r] == NULL) exit(1);
            memcpy(output_context[r],mine_grid[i],(n)*sizeof(char));
            output_context[r][n] = '\0'; //写入字符串终止转义符
            returning_row++;
            free(mine_grid[i]);
        }
    }
    free(mine_grid);
    return returning_row;
}

int main(){
    int last_row = 0;
    char **output_context = NULL;
    char **mine_grid = NULL;
    int m,n,k; //雷区行数、列数、雷数
    int x,y; //雷点
    while(scanf("%d %d %d",&m,&n,&k) == 3){
        assert(k <= m*n);
        mine_grid = malloc(m*sizeof(char*));
        if(mine_grid == NULL) exit(1);
        for(int i=0;i<=m-1;i++){
            mine_grid[i] = malloc((n+1)*sizeof(char)); //每行分配 n+1 个字符空间（+1 为 '\0'）
            if(mine_grid[i] == NULL) exit(1);
            for(int r=0;r<=n-1;r++){
                mine_grid[i][r] = '0';
            }
            mine_grid[i][n] = '\0';
        }
        for(int i=1;i<=k;i++){ //输入k个雷点
            scanf("%d %d",&x,&y);
            mine_grid[x-1][y-1] = '*';
        }
        Generate(mine_grid,m,n);
        last_row = Write_Output_Context(output_context,mine_grid,m,n,last_row);
    }
    for(int i=0;i<=last_row-1;i++){
        printf("%s\n",output_context[i]);
        free(output_context[i]);
    }
    free(output_context);
}
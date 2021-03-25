/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int vector[8][2] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
int dfs(int** land, int landSize, int landColsize, int **visited, int x, int y);
int compare1(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}
int* pondSizes(int** land, int landSize, int* landColSize, int* returnSize){
    int result[1000000]={0};
    int size = 0;
    int **visited = (int **)malloc(sizeof(int *) * landSize);
    for(int i = 0; i < landSize; i++){
        visited[i] = (int *)malloc(sizeof(int) * landColSize[i]);
        memset(visited[i],0,sizeof(int)*landColSize[i]);
    }
    for(int i = 0; i < landSize; i++){
        for(int j = 0; j <landColSize[i]; j++){
            if(land[i][j] == 0 && !visited[i][j]){
                visited[i][j] = 1;
                result[size++]=dfs(land,landSize,*landColSize,visited,i,j)+1;
            }
        }
    }
    *returnSize = size;
    int *a = malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++){
        a[i] = result[i];
    }
    qsort(a,size,sizeof(int),compare1);
    return a;
}

int dfs(int** land, int landSize, int landColSize, int **visited, int x, int y){
    int size = 0;
    for(int i = 0; i < 8; i++){
        int dx = x + vector[i][0];
        int dy = y + vector[i][1];
        if(dx>=0 && dx <landSize && dy >= 0 && dy < landColSize && land[dx][dy] == 0 && !visited[dx][dy]){
            visited[dx][dy] = 1;
            //printf("%d\t%d\t%d\n",dx,dy,visited[dx][dy]);
            size = size + dfs(land,landSize,landColSize,visited,dx,dy) + 1;
        }
        //printf("%d\n",size);
    }
    return size;
}
//说是my.c，结果dfs的全部思想都是网上嫖来的……无论是建立[8][2]的二维数组vector，还说一系列的判断条件，都是没写过的……
//不过还是挺满意的，感觉自己起码这道题吃透了，除了返回值size坑了蛮长时间以外，都理解的挺多了
//明天看看别人用C怎么开数组，直接开一百万未免太大了些……
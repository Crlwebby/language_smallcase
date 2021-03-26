/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int vector[8][2] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
//8个方向的向量，就是上下左右对角线
int dfs(int** land, int landSize, int landColsize, int **visited, int x, int y);
int compare1(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}
//C语言没有自带排序函数，网上抄了一个compare，带入qsort去用了……
int* pondSizes(int** land, int landSize, int* landColSize, int* returnSize){
    int result[1000000]={0};
    //result数组，用于存每个水域的大小，开小了可能水域太多，直接溢出了……
    int size = 0;//size用于标记水域的个数，result[size++]把一个个水域大小给存起来
    int **visited = (int **)malloc(sizeof(int *) * landSize);
    for(int i = 0; i < landSize; i++){
        visited[i] = (int *)malloc(sizeof(int) * landColSize[i]);
        memset(visited[i],0,sizeof(int)*landColSize[i]);
    }
    //visited数组，标准操作
    for(int i = 0; i < landSize; i++){
        for(int j = 0; j <landColSize[i]; j++){
            if(land[i][j] == 0 && !visited[i][j]){
                //筛选条件，把剩下的没找出来的水域给找出来
                visited[i][j] = 1;
                result[size++]=dfs(land,landSize,*landColSize,visited,i,j)+1;
                //因为visited[i][j]设为1，因而是水域的子水域大小+1
            }
        }
    }
    *returnSize = size;
    int *a = malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++){
        a[i] = result[i];
    }//定义一个结果数组a，把水域的值全部迁移过来，确实挺麻烦……但是为了返回标准大小才这样玩的，不然printf肯定不这样干
    qsort(a,size,sizeof(int),compare1);
    //从小到大排序
    return a;
}

int dfs(int** land, int landSize, int landColSize, int **visited, int x, int y){
    int size = 0;
    for(int i = 0; i < 8; i++){
        int dx = x + vector[i][0];
        int dy = y + vector[i][1];
        //这里是一个自己挖的坑，进来不先设置本水域visited[x][y]为1，可能会出现比较严重的bug
        if(dx>=0 && dx <landSize && dy >= 0 && dy < landColSize && land[dx][dy] == 0 && !visited[dx][dy]){
            //dfs入口条件，前四个保证不访问越界，后面保证是未访问过的水域
            visited[dx][dy] = 1;
            //printf("%d\t%d\t%d\n",dx,dy,visited[dx][dy]);
            size = size + dfs(land,landSize,landColSize,visited,dx,dy) + 1;
            //size这里比较难理解，主要是多个dfs往下延申的时候，要保存若干个分支的大小
            //dfs返回的（假定是子水域的大小），那么现在的就要额外+1，所有的就要加上原来的size
        }
        //printf("%d\n",size);
    }
    return size;
}
//说是my.c，结果dfs的全部思想都是网上嫖来的……无论是建立[8][2]的二维数组vector，还说一系列的判断条件，都是没写过的……
//不过还是挺满意的，感觉自己起码这道题吃透了，除了返回值size坑了蛮长时间以外，都理解的挺多了
//明天看看别人用C怎么开数组，直接开一百万未免太大了些……
void dfs(int** isConnected, int node, int *visited, int isConnectedSize){
    for(int i = 1; i < isConnectedSize; i++){
        if(isConnected[node][i]){
            if(visited[i]){
                continue;
            }
            visited[i] = 1;
            dfs(isConnected, i, visited, isConnectedSize);
        }
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize){
    int flag = 0;
    int visited[isConnectedSize];
    for(int i = 0; i < isConnectedSize; i++){
        visited[i] = 0;
    }
    for(int i = 0; i < isConnectedSize; i++){
        if(!visited[i]){
            flag++;
            dfs(isConnected, i, visited, isConnectedSize);
        }
    }
    return flag;
}

//第一个dfs自己做出来的题，值得纪念一下……虽然效率属实有点低下，但是没有问题，千里之行始于足下，冲冲冲！
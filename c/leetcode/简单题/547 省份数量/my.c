void dfs(int** isConnected, int node, int *visited, int isConnectedSize){
    for(int i = 1; i < isConnectedSize; i++){
        if(isConnected[node][i]){
            //dfs入口条件
            if(visited[i]){
                //标准dfs判断，未访问过的节点继续走dfs，访问过了就继续遍历下一个
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
    //visited数组，必备
    for(int i = 0; i < isConnectedSize; i++){//初始化
        visited[i] = 0;
    }
    for(int i = 0; i < isConnectedSize; i++){
        if(!visited[i]){
            //flag标记省份数量，总共i个结点，第一轮把与1相连的省份遍历一遍，后面如果有遗漏的孤立节点，就遍历出来再继续走
            flag++;
            dfs(isConnected, i, visited, isConnectedSize);
        }
    }
    return flag;
}

//第一个dfs自己做出来的题，值得纪念一下……虽然效率属实有点低下，但是没有问题，千里之行始于足下，冲冲冲！
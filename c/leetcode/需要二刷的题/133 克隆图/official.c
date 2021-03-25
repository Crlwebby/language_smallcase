/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */

struct Node **visited;

struct Node *dfs(struct Node *s){
    if(s == NULL)
        return NULL;
    if(visited[s->val])
        return visited[s->val];
    struct Node* temp = malloc(sizeof(struct Node));
    temp->val = s->val;
    temp->numNeighbors = s->numNeighbors;
    visited[temp->val] = temp;
    temp->neighbors = (struct Node **)malloc(sizeof(struct Node *) * s->numNeighbors);
    for(int i = 0; i < temp->numNeighbors; i++){
        temp->neighbors[i] = dfs(s->neighbors[i]);
    }
    return temp;
}

struct Node *cloneGraph(struct Node *s) {
    visited = (struct Node**)malloc(sizeof(struct Node *) * 101);
    memset(visited, 0, sizeof(struct Node*) * 101);
    return dfs(s);
}

//真的是……一到图，一点自信都没了，完全不会做啊啊啊啊啊啊，最简单的DFS都走的举步维艰，更别说其它还要进行抽象的题目了
//记录一下，回头好好研究一下DFS，本质确实还是递归没错
typedef struct {
    int **  result;
    int matrixSize;
} NumMatrix;


NumMatrix* numMatrixCreate(int** matrix, int matrixSize, int* matrixColSize){
    if(matrixSize == 0){
        return NULL;
    }
    NumMatrix *temp = (NumMatrix *)malloc(sizeof(NumMatrix));
    int colsize = *matrixColSize;
    temp->result = (int **)malloc(sizeof(int*) * matrixSize);
    for(int i = 0; i < matrixSize; i++){
        temp->result[i] = (int *)malloc(sizeof(int) * colsize);
        memset(temp->result[i],0,sizeof(int) * colsize);
    }
    temp->matrixSize = matrixSize;
    temp->result[0][0]=matrix[0][0];
    for(int i = 1; i < matrixSize; i++){
        temp->result[i][0] = matrix[i][0] + temp->result[i-1][0];
    }
    for(int j = 1; j < colsize; j++){
        temp->result[0][j] = matrix[0][j] + temp->result[0][j-1];
    }
    for(int i = 1; i < matrixSize; i++){
        for(int j = 1; j < colsize; j++){
            temp->result[i][j] = matrix[i][j] + temp->result[i][j-1] + temp->result[i-1][j] - temp->result[i-1][j-1];
        }
    }
    return temp;
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2) {
    if(row1 == 0 && col1 == 0){
        return obj->result[row2][col2];
    }
    if(row1 == 0)
        return obj->result[row2][col2] - obj->result[row2][col1-1];
    else if(col1 == 0)
        return obj->result[row2][col2] - obj->result[row1-1][col2];
    else
        return obj->result[row2][col2] - obj->result[row2][col1 - 1] - obj->result[row1 - 1][col2] + obj->result[row1 - 1][col1 - 1];
}

void numMatrixFree(NumMatrix* obj) {
    if(obj != NULL){
        for(int i = 0; i<obj->matrixSize;i++)
            free(obj->result[i]);
        free(obj->result);
    }
}

/**
 * Your NumMatrix struct will be instantiated and called as such:
 * NumMatrix* obj = numMatrixCreate(matrix, matrixSize, matrixColSize);
 * int param_1 = numMatrixSumRegion(obj, row1, col1, row2, col2);
 
 * numMatrixFree(obj);
*/

//用C写这种东西真的头痛……看这一堆密密麻麻的条件设置和参数变化就知道什么个情况了……
//之前看大佬有说，leetcode面向样例编程会很蠢，我觉得我这个就是这样
//思路还是比较清晰的，但是由于DP写的很少，所以颇有波折吧。总体来说还是303的思路来写的，效果也还可以
//看看大佬如何进行进一步的优化吧，反正思路是类似的，但是别人写的估计更加轻松惬意~
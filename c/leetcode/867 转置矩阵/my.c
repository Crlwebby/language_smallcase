int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes){
    int row = matrixSize;
    int column = matrixColSize[0];
    *returnSize = column;
    *returnColumnSizes = malloc(sizeof(int) * column);
    int **result = (int **)malloc(sizeof(int*) * column);
    for(int i = 0; i < column; i++){
        result[i] = (int*)malloc(sizeof(int) * row);
        (*returnColumnSizes)[i] = row;
    }
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            result[j][i] = matrix[i][j];
        }
    }
    return result;
}

//每次做二维数组就很难受，不知道他这个 int** returnColumnSizes到底想干嘛……
//于是各种segment fault或者address saniter之类的，整麻了
//当然，也是自己指针用的还不是很熟练的缘故

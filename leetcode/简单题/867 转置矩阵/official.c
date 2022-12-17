int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) 
{
    int m = matrixSize, n = matrixColSize[0];
    int** ret_matri = malloc(sizeof(int*) * n);
    *returnSize = n;
    *returnColumnSizes = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        ret_matri[i] = malloc(sizeof(int) * m);
        (*returnColumnSizes)[i] = m;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            ret_matri[j][i] = matrix[i][j];
        }
    }
    return ret_matri;
}
//这leetcode真的是……明明24ms样例给的是这个代码，跑起来44ms，下次我不参考运行时间了，只看算法……
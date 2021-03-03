typedef struct {
    int** sums;
    int sumsSize;
} NumMatrix;

NumMatrix* numMatrixCreate(int** matrix, int matrixSize, int* matrixColSize) {
    NumMatrix* ret = malloc(sizeof(NumMatrix));
    ret->sums = malloc(sizeof(int*) * matrixSize);
    ret->sumsSize = matrixSize;
    for (int i = 0; i < matrixSize; i++) {
        ret->sums[i] = malloc(sizeof(int) * (matrixColSize[i] + 1));
        ret->sums[i][0] = 0;
        for (int j = 0; j < matrixColSize[i]; j++) {
            ret->sums[i][j + 1] = ret->sums[i][j] + matrix[i][j];
        }
    }
    return ret;
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2) {
    int sum = 0;
    for (int i = row1; i <= row2; i++) {
        sum += obj->sums[i][col2 + 1] - obj->sums[i][col1];
    }
    return sum;
}

void numMatrixFree(NumMatrix* obj) {
    for (int i = 0; i < obj->sumsSize; i++) {
        free(obj->sums[i]);
    }
    free(obj->sums);
}

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/range-sum-query-2d-immutable/solution/er-wei-qu-yu-he-jian-suo-ju-zhen-bu-ke-b-2z5n/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

//官方的做法和我思考的差不多，也和上次的303一样，就是把数组扩大一维，从而不必考虑边界点的问题
//代码优化的确实很干净，尤其是在分配内存的同时进行前缀和的求解之类的，直接比我少了将近20行代码……
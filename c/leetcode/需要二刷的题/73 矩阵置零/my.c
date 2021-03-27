void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    if(matrixSize == 0)
        return ;
    int row = matrixSize;
    int column = *matrixColSize;
    int a[row],b[column];
    memset(a,0,sizeof(int) * row);
    memset(b,0,sizeof(int) * column);
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            if(matrix[i][j] == 0){
                a[i] = 1;
                b[j] = 1;
            }
        }
    }
    for(int i = 0; i < row; i++){
        if(a[i] == 1){
            for(int j = 0; j < column; j++){
                matrix[i][j] = 0;
            }
        }
    }
    for(int j = 0; j < column; j++){
        if(b[j] == 1){
            for(int i = 0; i < row; i++)
                matrix[i][j] = 0;
        }
    }
}

//题目要求原地算法，我没能实现……有提示的，三种方法分别是O(mn),O(m+n)和O(1)，但是不会O(1)，只用了O(m+n)实现
//O(m+n)的思路还是比较清楚的，如果矩阵某个位置有零，就把对应的行号和列号标记一下，遍历完所有的零后开始置零
//确实想一想有很多冗余的代码，或者说，一个矩阵好多地方都遍历了N次，但是想不到怎么优化……
//因为如果读到零就把对应行列置零的话，很有可能会把其它原本的零覆盖掉，就很麻烦……
void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize;
    int n = matrixColSize[0];
    int flag_col0 = false, flag_row0 = false;
    for (int i = 0; i < m; i++) {
        if (!matrix[i][0]) {
            flag_col0 = true;
        }
    }
    for (int j = 0; j < n; j++) {
        if (!matrix[0][j]) {
            flag_row0 = true;
        }
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (!matrix[i][j]) {
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (!matrix[i][0] || !matrix[0][j]) {
                matrix[i][j] = 0;
            }
        }
    }
    //这里设置i,j从1开始，不仅仅是有简单的优化，第一行和第一列下面都是分别进行处理的
    //而且，第一行和第一列是标记，是在处理完其它行之前不能动的！动了就会影响最后的结果
    if (flag_col0) {
        for (int i = 0; i < m; i++) {
            matrix[i][0] = 0;
        }
    }
    if (flag_row0) {
        for (int j = 0; j < n; j++) {
            matrix[0][j] = 0;
        }
    }
}

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/set-matrix-zeroes/solution/ju-zhen-zhi-ling-by-leetcode-solution-9ll7/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

//原来如此……原理还是比较类似的，但是很巧妙，就是用给定数组的第一行和第一列来当作标记，然后第一行和第一列额外处理就行，妙啊，
//当然典型时间换空间……多了两个行列遍历，少用了m+n的空间，孰优孰劣见仁见智……只是一个很好的思路
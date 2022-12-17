int** flipAndInvertImage(int** A, int ASize, int* AColSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = ASize;
    *returnColumnSizes = AColSize;
    int n = ASize;
    for (int i = 0; i < n; i++) {
        int left = 0, right = n - 1;
        while (left < right) {
            if (A[i][left] == A[i][right]) {
                A[i][left] ^= 1;
                A[i][right] ^= 1;
            }
            left++;
            right--;
        }
        if (left == right) {
            A[i][left] ^= 1;
        }
    }
    return A;
}

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/flipping-an-image/solution/fan-zhuan-tu-xiang-by-leetcode-solution-yljd/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
//很帅，实现需求的时候果然还是应该对需求进行分析
//这道题而言，由于是01序列，两个数交换满打满算也就4种情况，再配上异或，就简洁了很多。
//分析都在官方题解里有，关键就是不需要真的执行反转这一操作即可得到反转的结果。
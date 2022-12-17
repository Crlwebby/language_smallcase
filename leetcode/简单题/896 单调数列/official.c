bool isMonotonic(int* A, int ASize) {
    bool inc = true, dec = true;
    int n = ASize;
    for (int i = 0; i < n - 1; ++i) {
        if (A[i] > A[i + 1]) {
            inc = false;
        }
        if (A[i] < A[i + 1]) {
            dec = false;
        }
    }
    return inc || dec;
}
//全相等就是俩true
作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/monotonic-array/solution/dan-diao-shu-lie-by-leetcode-solution-ysex/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
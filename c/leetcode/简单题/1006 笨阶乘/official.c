int clumsy(int N) {
    if (N == 1) {
        return 1;
    } else if (N == 2) {
        return 2;
    } else if (N == 3) {
        return 6;
    } else if (N == 4) {
        return 7;
    }

    if (N % 4 == 0) {
        return N + 1;
    } else if (N % 4 <= 2) {
        return N + 2;
    } else {
        return N - 1;
    }
}

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/clumsy-factorial/solution/ben-jie-cheng-by-leetcode-solution-deh2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

//额，这官方用一套数学组合拳，把我打的有点点懵逼……
//用数学思考，弄成双O(1)的这种，体现出威力来了
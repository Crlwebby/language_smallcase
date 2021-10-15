class Solution {
    public int longestPalindrome(String s) {
        int[] count = new int[128];
        int length = s.length();
        for (int i = 0; i < length; ++i) {
            char c = s.charAt(i);
            count[c]++;
        }

        int ans = 0;
        for (int v: count) {
            ans += v / 2 * 2;
            if (v % 2 == 1 && ans % 2 == 0) {
                ans++;
            }
        }
        return ans;
    }
}

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/longest-palindrome/solution/zui-chang-hui-wen-chuan-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

//还可以，起码看得懂……
//这里没用map，因为是字符串序列，用个128的数组可能效率更高，不需要哈希的计算，可以直接随机索引。
//下面那段代码的意思是,v/2先取对半，然后再乘2，取全部的，这样统一处理，奇数也是一样的处理方法，就不用单独判断奇偶性了。
//然后v如果是奇数，那可以取一个；但最初ans是偶数，因为每次取两个；如果取了一次单个的数，那就不再取了。
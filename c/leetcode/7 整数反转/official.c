int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;

作者：LeetCode
链接：https://leetcode-cn.com/problems/reverse-integer/solution/zheng-shu-fan-zhuan-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

//关键在于如何用int类型判断溢出，rev * 10 + pop > INTMAX会溢出，就利用这个做文章
//在此种情况下，rev > (INTMAX - pop) / 10 ，  0 <= pop <= 9
//可见，如果rev > INTMAX/10 一定会溢出，
//如果rev == INTMAX/10 ，INTMAX=2147483647，INTMIN=-2147483648
//此时pop > 7 或 pop < -8，都会导致溢出，也就是官方回答的代码了。

bool isPalindrome(int x){
    if(x < 0)
        return false;
    int length = 0;
    int a[12] = {0};
    while(x != 0){
        a[length] = x % 10;
        x = x / 10;
        length += 1;
    }
    int temp,b[12];
    for(int i = 0; i < length; i++){
        b[length - i - 1] = a[i];
    }
    for(int i = 0; i < length; i++){
        if(a[i] != b[i])
            return false;
    }
    return true;
}
//我用的方法是将整数分割成数组，然后逆序数组……空间复杂度O(2n)，时间复杂度也差不多O(2n)，好处是不需要调外部函数
bool isPalindrome(int x){
    if(x<0) return false;

    int num=x;
    long res=0;
    
    for(;x!=0;x/=10){
        res=x%10+10*res;
    }

    if(res==num) return true;
    return false;
}
作者：ji-ke-5k
链接：https://leetcode-cn.com/problems/palindrome-number/solution/hui-wen-shu-by-ji-ke-5k-nq1y/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
//大佬方法，当然应该也是很合理的方法……我怎么就忘了逐个整除来求回文数呢？笨！

bool isPalindrome(int x) {
        // 特殊情况：
        // 如上所述，当 x < 0 时，x 不是回文数。
        // 同样地，如果数字的最后一位是 0，为了使该数字为回文，
        // 则其第一位数字也应该是 0
        // 只有 0 满足这一属性
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }
        // 当数字长度为奇数时，我们可以通过 revertedNumber/10 去除处于中位的数字。
        // 例如，当输入为 12321 时，在 while 循环的末尾我们可以得到 x = 12，revertedNumber = 123，
        // 由于处于中位的数字不影响回文（它总是与自己相等），所以我们可以简单地将其去除。
        return x == revertedNumber || x == revertedNumber / 10;
    }

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/palindrome-number/solution/hui-wen-shu-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
//这是更高级的做法，通过做数学分析得到的结果，注释已经很清楚了，看也看得懂，业务实现肯定不搞这种骚操作，过一段时间肯定看不懂了
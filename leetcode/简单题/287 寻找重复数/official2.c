//位运算的骚操作，这个办法是真有点……怎么说呢，技巧性太高了，感觉不具有普遍性和学习价值……
//详细的算法思路说明题解里都有了，我只说说感想
//由于数组为n+1，数的范围是1-n,必然有一个重复数字，那么重复数字为1的位可以决定这个数字
//然后通过数学归纳法，证明有三个数字重复时的普遍性规律，然后可以扩展到n个数字，从而证明定理。。。

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        // 确定二进制下最高位是多少
        int bit_max = 31;           //假设是4字节32位，右移32位肯定是0，所以从31位开始
        while (!((n - 1) >> bit_max)) {     //如果右移这么多位变成0了，说明这个数最高位在右边，bit_max--
            bit_max -= 1;
        }
        for (int bit = 0; bit <= bit_max; ++bit) {  //按位进行x和y的比较
            int x = 0, y = 0;
            for (int i = 0; i < n; ++i) {   //同时计算x和y，这个应该是哪里见过的
                if (nums[i] & (1 << bit)) {     //将1进行左移，实现精准按位判断是否为1
                    x += 1;
                }
                if (i >= 1 && (i & (1 << bit))) {   //同上，但是数字范围是1-n，所以排除一下0
                    y += 1;
                }
            }
            if (x > y) {    //不用傻傻的相加*2这种用位计算十进制值了23333，直接把对应的位用按位|加上去
                ans |= 1 << bit;
            }
        }
        return ans;
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/find-the-duplicate-number/solution/xun-zhao-zhong-fu-shu-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
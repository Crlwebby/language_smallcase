class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //根据cnt数组，如果没有重复数字，那么cnt[i] <= i，
        //其中cnt[i]表示从cnt[0]-cnt[i-1]中小于等于cnt[i]的数字个数
        int n = nums.size();
        int l = 1, r = n - 1, ans = -1; //题目数据是1 <= nums[i] <= n, 因此查找数据用1开始，但n-1和n都是可以的……不懂为什么
        while (l <= r) {
            int mid = (l + r) >> 1;     //头加尾除2，取中间，二分
            int cnt = 0;
            for (int i = 0; i < n; ++i) {   //遍历整个数组进行cnt计算（即小于等于mid的数）
                cnt += nums[i] <= mid;
            }
            if (cnt <= mid) {   //证明这个数据符合要求，那么这个数之前的数也必然符合要求（注意，这里指的是l和r，并不是真正的数组下标元素！，数组是无序的)
                l = mid + 1;
            } else {
                r = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/find-the-duplicate-number/solution/xun-zhao-zhong-fu-shu-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
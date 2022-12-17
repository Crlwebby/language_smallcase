//这就是位运算找数字吗，原来如此……不过只是单纯的是用异或的性质罢了

class Solution {
    public int missingNumber(int[] nums) {
        int missing = nums.length;          //数据范围是0-n，由于数组下标到n-1，所以需要额外补充一下n
        for (int i = 0; i < nums.length; i++) {
            missing ^= i ^ nums[i];         //把所有数组元素的下标和它的值异或在一起，总有重复的，就可以消掉
        }
        return missing;
    }
}

作者：LeetCode
链接：https://leetcode-cn.com/problems/missing-number/solution/que-shi-shu-zi-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
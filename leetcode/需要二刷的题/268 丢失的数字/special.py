class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        return sum(list(range(len(nums) + 1))) - sum(nums)

'''作者：JonnyHuang
链接：https://leetcode-cn.com/problems/missing-number/solution/python3-yi-xing-dai-ma-ji-bai-999-by-jon-ooip/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。'''

#人傻了……这就是py吗，不过好像确实是绝佳的思路？可以直接通过sum判断缺少的数字呀！这不就是题目暗示的O(n)方法和O(1)空间吗
func findMin(nums []int) int {
    low, high := 0, len(nums) - 1
    for low < high {
        pivot := low + (high - low) / 2
        if nums[pivot] < nums[high] {
            high = pivot
        } else {
            low = pivot + 1
        }
    }
    return nums[low]
}

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/solution/xun-zhao-xuan-zhuan-pai-xu-shu-zu-zhong-5irwp/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

//果然是官方的题解，性质利用的更加完善，代码简洁易懂，要达到这个水准我还需要多加训练；
//左右代表两个界限，要找的最小值在数组的中间位置。那么最小值-区间最右边的值肯定小于区间最右边的值；区间最左边的值-最小值肯定大于区间最右边的值
//因此可以利用这个性质，来不断地更新low跟high
//这代码越看越简洁，跟普通二分没差别……好强呀
func minSubArrayLen(target int, nums []int) int {
	length := len(nums)
	ans := length
	flag := 0
	temp_sum := nums[0]
	for i, j := 0, 0; i < length && j < length; {
		if temp_sum < target {
			j++
			if j < length {
				temp_sum += nums[j]
			}
		}
		if temp_sum >= target {
			temp := j - i + 1
			flag = 1
			ans = min(ans, temp)
			temp_sum -= nums[i]
			i++
		}
	}
	if flag == 0 {
		return 0
	}
	return ans
}

//=.= 对于边界问题的处理，还是逊的不行啊，强行加一个flag，用于判断整个数组和等于target的情况，low啊
//其它还好，就是什么时候滑动窗口需要思考一下，不是很难的题
//噢，其实这个边界问题和官方的处理思路是一致的啊，只不过官方用MaxInt32，这保证了样例数据不会和这个数字重叠
//这就很像字符串输入截断中，选一个特别不常用的字符赋予其特殊的意义一样，是个很普遍的思想啊。
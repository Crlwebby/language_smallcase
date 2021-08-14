func rob(nums []int) int {
	dp := make([]int, 2)
	flag := make([]int, 2)
	len := len(nums)
	//作为标记，看当前的最大金额是否包含头第一个房屋
	if len == 1 {
		return nums[0]
	} else if len == 2 {
		return max(nums[0], nums[1])
	} else {
		dp[0] = nums[0]
		flag[0] = 1
		//flag=1代表包含第一个房屋
		dp[1] = max(nums[0], nums[1])
		if dp[1] == nums[0] {
			flag[1] = 1
		} else {
			flag[1] = 0
		}
	}
	for i := 2; i < len; i++ {
		temp := max(nums[i]+dp[i-2], dp[i-1])
		if temp == dp[i-1] {
			flag = append(flag, flag[i-1])
		} else {
			flag = append(flag, flag[i-2])
		}
		dp = append(dp, temp)
	}
	//fmt.Println(dp)
	//fmt.Println(flag)
	if dp[len-1] == dp[len-2] {
		return dp[len-1]
	}
	if flag[len-1] == 0 {
		return dp[len-1]
	}
	a := dp[len-1] - nums[0]
	b := dp[len-1] - nums[len-1]
	c := 0
	for i := len - 1; i > 0; i-- {
		if flag[i] == 0 {
			c = dp[i]
			break
		}
	}
	return max(max(a, b), c)

}

func max(a int, b int) int {
	if a < b {
		return b
	}
	return a
}

//朴素想法，加一个标志位，用于表明当前最大值是否包括第一个房子
//然后就陷入了无限的细节，被边界搞得心态爆炸，代码又臭又长缝缝补补的，直接寄！
//学学人家怎么写动态方程的！
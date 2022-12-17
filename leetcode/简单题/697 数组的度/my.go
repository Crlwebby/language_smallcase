func findShortestSubArray(nums []int) int {
	dp := make(map[int][]int)
	len := len(nums)
	for i := 0; i < len; i++ {
		//第一次遍历,统计所有数字的度\第一次出现位置\最后一次出现位置
		if dp[nums[i]] == nil {
			dp[nums[i]] = append(dp[nums[i]], 1)
			//第一次遇见某个数字,记录度为1
			dp[nums[i]] = append(dp[nums[i]], i)
			//记录开始位置
			dp[nums[i]] = append(dp[nums[i]], i)
			//记录结束位置
		} else {
			//第二次遇见,更新度和结束位置
			dp[nums[i]][0]++
			dp[nums[i]][2] = i
		}
	}
	max := 1
	//度最小为1
	res := 50000
	for _, v := range dp {
		if v[0] >= max {
			//遇见更大的度了,更新一下值
			temp := v[2] - v[1] + 1
			if v[0] > max {
				//v[0]>max时 无脑更新就是了
				res = temp
			} else if res > temp {
				//v[0]=max,两个度相同时,取更小的那个区间长度
				res = temp
			}
			max = v[0]
		}
	}
	return res
}

//只能说是醍醐灌顶吧，看了题解，然后想通了怎么搞
//原本还一直担心着是不是太多的使用语言特性而忽略底层了，现在想想好像用结构体也是可以的，就保存三个元素，数字出现个数、元素第一次出现和最后一次出现位置
//唯一的问题是C语言哈希表要怎么实现？如何做到出现一个数字就对应一个？或者说动态扩容的问题
//感觉真不太像动态规划，莫名其妙的……就遍历一圈完事儿了，辣鸡力扣题目关联
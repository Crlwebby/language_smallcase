func jump(nums []int) int {
	res := 0
	len := len(nums)
	rightmost := nums[0]
	end := 0
	for i := 0; i < len-1; i++ {
		rightmost = max(rightmost, nums[i]+i)
		if i == end {
			end = rightmost
			res++
		}
	}
	return res
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

//这题真的，做到现在还是模模糊糊的，感觉想得不是很清楚明朗，把自己思路卡住了。
//回顾一下伪代码思路吧。当前是第一步的位置，然后往后跳，第一次跳的最远距离是固定的。肯定是nums[0]
//然后在到最远距离之间的距离，就0-nums[0]这段区间里，找更远的rightmost，因为是要为了下一步跳得更远。
//为什么找最远就一定能保证最后跳到终点呢？因为这道题的跳远，是连续的。也就是说，你跳得最远，然后跳得比你近的点你都可以到达，能跳最远的点肯定能到达其它的可能点
//O(N)遍历所有的点，每次按区间进行划分，每次划分的依据就是上一次的最远点，在最远点之前的区间遍历，找到下一次的最远点。
//当你区间遍历完后，也就知道下一次能跳多远了，也就可以把这一步跳出去，就是res++
//混乱的一批……下次真不知道能不能做出来
func sortColors(nums []int) {
	length := len(nums)
	i, j, k := 0, 0, length-1
	for j <= k {
		if nums[j] == 0 {
			nums[j] = nums[i]
			nums[i] = 0
			i++
			j++
		} else if nums[j] == 2 {
			nums[j] = nums[k]
			nums[k] = 2
			k--
		} else {
			j++
		}
	}
}

//笑死，题目都是做过的=。= 这个数据结构的计划开了又做不完，做不完又开，来来回回做同样的前几天的题目，麻了……
//这次一定要全部做掉啊兄弟！
//回到本题，我用了三个变量来记录分隔点的位置，用来保存0、1、2，写的时候发现刚开始最不好搞，就是i、j重合的时候
//不过自己画几个样例就行了，不算很复杂。样例：2 0 2 1 1 0 0 1 1 2 0 1 0 ，可以手动模拟试试看
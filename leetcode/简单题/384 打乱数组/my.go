import "math/rand"

type Solution struct {
	len    int
	origin []int
	dst    []int
}

func Constructor(nums []int) Solution {
	var temp Solution
	temp.origin = append(temp.origin, nums...)
	temp.len = len(nums)
	return temp
}

func (this *Solution) Reset() []int {
	return this.origin
}

func (this *Solution) Shuffle() []int {
	if len(this.dst) > 0 {
		this.dst = this.dst[len(this.dst):]
	}
	var mask [8]int
	for i := 0; i < this.len; {
		t := rand.Intn(this.len)
		if mask[t/32]&(1<<(31-t%32)) == 0 {
			mask[t/32] |= 1 << (31 - t%32)
			this.dst = append(this.dst, this.origin[t])
			i++
		}
	}
	return this.dst
}

/**
 * Your Solution object will be instantiated and called as such:
 * obj := Constructor(nums);
 * param_1 := obj.Reset();
 * param_2 := obj.Shuffle();
 */
//做得怪怪的hhhhhh，感觉不是典型的算法题，更像是娱乐题。
//就是让你实现一个随机数一样的东西吧。反正数字量也不是很大，用用位运算保存flag，感觉还行。
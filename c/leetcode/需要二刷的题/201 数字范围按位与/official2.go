func rangeBitwiseAnd(left int, right int) int {
	for right > left {
		right &= (right - 1)
	}
	return right
}

//这题我是真的被折服了，完全没有思路，但是题解就是异常简单，再次让我看见了位运算的魅力
//我是有想到过前缀匹配，但是不知道怎么去实现
//然后发现这个算法， a & (a - 1)能够消除a最右边的1，然后不断进行这个过程，直到大的数小于等于小的数，这不就前缀匹配上了嘛！
//太强了真的
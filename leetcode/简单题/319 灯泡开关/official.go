import "math"

func bulbSwitch(n int) int {
	return int(math.Sqrt(float64(n)))
}

//……这题怎么说呢，挺有意思的，虽然标准代码短的可怜……
//是啊，我咋没想到，一个数字的因子都是成对出现的，只有完全平方数才有奇数个因子。
//更妙的是n以内的完全平方数的个数就是根号n向下取整。这个说不清是什么道理，但是仔细一想就特别有道理233333，因为更小的数字都遍历过了（大概这个意思……
func backspaceCompare(s string, t string) bool {
	skipS, skipT := 0, 0
	p1, p2 := len(s)-1, len(t)-1
	for p1 >= 0 || p2 >= 0 { //让这一切在循环里毁灭吧，出了循环的都是自家人，统统是true
		//为什么用或呢？因为下面的代码决定的。下面的代码考虑到了一个小于零一个不小于零返回false的情况，因而要在这里用或把这种情况包含进去
		for p1 >= 0 {
			//p1 < 0会炸，加个限定条件先
			if s[p1] == '#' {
				//如果是退格，那就退格计数+1
				skipS++
				p1--
			} else {
				if skipS != 0 {
					//如果还有退格在缓冲区，那就退格
					skipS--
					p1--
				} else {
					//否则这个字符是确定的字符，可以进行比较了
					break
				}
			}
		}
		for p2 >= 0 {
			if t[p2] == '#' {
				skipT++
				p2--
			} else {
				if skipT != 0 {
					skipT--
					p2--
				} else {
					break
				}
			}
		}
		if p1 >= 0 && p2 >= 0 {
			//两者都不断退格，只有还有字符残留才能比较
			if s[p1] != t[p2] {
				return false
			}
		} else if p1 >= 0 || p2 >= 0 {
			//如果一个字符串空了，另一个还有，那肯定是不匹配的
			return false
		}
		p1--
		p2--
	}

	return true
}

//说实话，这个思路我并没有很理解。虽然看了题解，但是题解语焉不详，只有看代码才能看得出细节来。
//细节是魔鬼，关于如果处理指针小于零、在何时进行退格计数、如何进行比较、如何判断字符串不相等等情况下，把我绕晕了
//这可太难了。我读懂了思路，但是自己写代码很头疼，写不出来；看着官方的才一步步写出来的，这题想标记一下，感觉必须再做一遍才能掌握

//前面两段for xxx >= 0 , 都是为了遍历字符串，找到一个实际的字符；因为有可能找不到，所以把xxx限定>=0，然后同样的，下面作比较时也提前限定一下
//
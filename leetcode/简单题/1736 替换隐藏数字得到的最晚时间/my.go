func maximumTime(time string) string {
	result := []byte(time)
	for i := 0; i < 5; i++ {
		if result[i] == '?' {
			switch i {
			case 0:
				fmt.Printf("%c", result[1])
				if result[1] >= '4' && result[1] <= '9' {
					result[0] = '1'
				} else {
					result[0] = '2'
				}
			case 1:
				if result[0] == '2' {
					result[1] = '3'
				} else {
					result[1] = '9'
				}
			case 3:
				result[3] = '5'
			case 4:
				result[4] = '9'
			}
		}
	}
	return string(result)
}

//不得不说SB Golang语言 真的，既要动态又要静态，搞得自己四不像，像个小丑=。=
//也可以说自己golang还不精通吧 但是真的 语法细节有点繁琐了 远没有C语言那样简单干净啊
//害 可能这就是现代语言必须有的东西吧，还是自己太菜了，见识过的语言太少，简单题wa了两次 做了半个多小时……
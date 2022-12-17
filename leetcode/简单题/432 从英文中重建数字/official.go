func originalDigits(s string) string {
	dict := make(map[rune]int)
	for _, ch := range s {
		dict[ch]++
	}

	cnt := [10]int{}
	cnt[0] = dict['z']
	cnt[2] = dict['w']
	cnt[4] = dict['u']
	cnt[6] = dict['x']
	cnt[8] = dict['g']

	cnt[3] = dict['h'] - cnt[8]
	cnt[5] = dict['f'] - cnt[4]
	cnt[7] = dict['s'] - cnt[6]

	cnt[1] = dict['o'] - cnt[0] - cnt[2] - cnt[4]
	cnt[9] = dict['i'] - cnt[5] - cnt[6] - cnt[8]

	ans := []byte{}
	for i, c := range cnt {
		ans = append(ans, bytes.Repeat([]byte{byte('0' + i)}, c)...)
	}

	return string(ans)
}

//抄了一道题=。= 不是很有意义的题，找规律，强行搞的题目吧只能说
//
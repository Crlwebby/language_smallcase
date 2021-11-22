package main

import "fmt"

func main() {
	src := "abc123ABCAB"
	match := "AB"
	replace := "abc"
	fmt.Println(FindAndReplace(src, match, replace))
}

func FindAndReplace(src string, match string, replace string) string {
	dest := []byte(src)
	len_src := len(dest)
	len_match := len(match)
	replace_byte := []byte(replace)
	for i := 0; i < len_src; i++ {
		if dest[i] == match[0] {
			j := 1
			for j < len_match {
				if dest[i+j] != match[j] {
					break
				}
				j++
			}
			if j == len_match {
				var after []byte
				after = append(after, dest[i+len_match:]...)
				dest = dest[0:i]
				dest = append(dest, replace_byte...)
				dest = append(dest, after...)
				len_src = len_src + len(replace_byte) - len_match
				i = i + len(replace_byte) - 1
			}
		}
	}
	return string(dest)
}

package main

import "fmt"

func main() {
	a := map[string]int{}
	a["1"] = 1
	a["2"] = 2
	a["3"] = 3
	fmt.Println(a["5"])
	for i, v := range a {
		fmt.Println(i, v)
	}
	key, value := a["5"]
	fmt.Println(key, value)
	key, value = a["3"]
	fmt.Println(key, value)
}

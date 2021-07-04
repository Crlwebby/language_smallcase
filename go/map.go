package main

import "fmt"

func main() {
	var map_first map[string]string
	map_first = map[string]string{"lover": "zfy", "another": "cby"}
	fmt.Printf("Map first at \"lover\" is:%s\n", map_first["lover"])

	fmt.Println(map_first["another"])
	fmt.Println(map_first["lover"])
	map_first["second"] = "hello"
	fmt.Printf("second is %s \n", map_first["second"])
}

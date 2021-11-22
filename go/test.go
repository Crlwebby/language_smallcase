package main

import (
	"fmt"
)

func main() {
	str := "Aliceadf"
	func(name string) {
		fmt.Println("Your name is", name)
	}(str)
}

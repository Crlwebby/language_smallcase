package main

import (
	"fmt"

	"greetings"

	"rsc.io/quote"
)

func main() {
	fmt.Println(quote.Go())

	message := greetings.Hello("Gladys")
	fmt.Println(message)
}

// go mod tidy will add module to go.mod automatically
// go run . will compile the program and run it

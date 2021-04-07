package main

import (
	"fmt"
	"log"

	"example/greetings"
)

func main() {
	//fmt.Println(quote.Go())

	log.SetPrefix("greetings: ")
	log.SetFlags(0)

	message, err := greetings.Hello("sweet")

	if err != nil {
		log.Fatal(err)
	}

	fmt.Println(message)
}

// go mod tidy will add module to go.mod automatically
// go run . will compile the program and run it

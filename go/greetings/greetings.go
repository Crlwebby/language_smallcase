package greetings

import (
	"errors"
	"fmt"
	"math/rand"
	"time"
)

func Hello(name string) (string, error) {

	// If no name was given, return an error with a message.
	if name == "" {
		return "", errors.New("empty name")
	}

	message := fmt.Sprintf(randomFormat(), name)
	return message, nil
}

//Go executes init functions automatically at program startup, after global variables have been initialized.

func init() {
	rand.Seed(time.Now().UnixNano())
}

//note that randomFormat starts with a lowercase letter, making it accessible only to code in its own package
func randomFormat() string {
	formats := []string{
		"Hi,%v. Welcome!",
		"Great to see you, %v!",
		"Hail, %v! Well met!",
	}
	return formats[rand.Intn(len(formats))]
}

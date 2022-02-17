package main

import "fmt"

type Interface interface {
	Len() int
	Less(i, j int) bool
	Swap(i, j int)
}

type Reverse struct {
	Interface
}

const (
	Man   int = 0
	Woman int = 1
)

type people struct {
	Name string
	Sex  int
}
type People []*people

func (a People) Len() int {
	return len(a)
}

func (a People) Swap(i, j int) {
	a[i], a[j] = a[j], a[i]
}

func (a People) Less(i, j int) bool {
	return a[i].Name < a[j].Name
}

func main() {
	boy := People{
		&people{"a", Man},
		&people{"b", Woman},
		&people{"c", Man},
	}
	temp := Reverse{boy}
	fmt.Println(temp)
}

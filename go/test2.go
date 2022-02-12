package main

import (
	"fmt"
	"sort"
)

type lovekind int

const (
	enemy lovekind = iota - 2
	boring
	stranger
	like
	love
	family
)

type Wife struct {
	Name   string
	degree lovekind
}

type Wifes []*Wife

func (k Wifes) Len() int {
	return len(k)
}

func (k Wifes) Less(i, j int) bool {
	if k[i].degree == k[j].degree {
		return k[i].Name < k[j].Name
	} else {
		return k[i].degree < k[j].degree
	}
}

func (k Wifes) Swap(i, j int) {
	k[i], k[j] = k[j], k[i]
}
func main() {
	mywife := Wifes{
		&Wife{"陈冰萸", enemy},
		&Wife{"倪姝南伶", love},
		&Wife{"倪佳雯", like},
		&Wife{"周凡驭", family},
		&Wife{"王书凡", stranger},
		&Wife{"曾个个", like},
	}
	sort.Sort(mywife)
	for _, v := range mywife {
		fmt.Println(v.Name, v.degree)
	}

	sort.Sort(sort.Reverse(mywife))
	fmt.Println("=====================")
	for _, v := range mywife {
		fmt.Println(v.Name, v.degree)
	}
}

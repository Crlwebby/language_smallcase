package main

import (
	"fmt"
	"time"
)

func running() {

	var times int
	fmt.Println(times)
	// 构建一个无限循环
	for {
		times++
		fmt.Println("tick", times)

		// 延时1秒
		time.Sleep(time.Second)
		if times > 10 {
			break
		}
	}
	return
}

func main() {

	// 并发执行程序
	go running()

	// 接受命令行输入, 不做任何事情
	var input string
	fmt.Scanln(&input)
}

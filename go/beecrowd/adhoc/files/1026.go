package main

import (
	"fmt"
)

func main() {
	var a,b int

	for {
		n, _ := fmt.Scanln(&a, &b)
		if n == 0 {
			break
		}
		a = a ^ b

		fmt.Println(a)
	}
}

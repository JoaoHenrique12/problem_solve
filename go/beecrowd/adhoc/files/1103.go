package main

import (
	"fmt"
)

func main() {
	var x1, y1, x2, y2 int

	for {
		fmt.Scanln(&x1, &y1, &x2, &y2)
		if x1 + x2 + y1 + y2 == 0 {
			break
		}
		hour := (x2 - x1 + 24) % 24
		minute := y2 - y1 + hour * 60

		if minute < 0 {
			minute += 24 * 60
		}

		fmt.Println(minute)

	}
}

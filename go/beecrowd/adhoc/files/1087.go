package main

import (
	"fmt"
)

func check_diagonals(x1, y1, x2, y2 int) bool{
	found := false
	for v := 1; v <= 8; v++{
		// main diagonal
		found = found || (x1 + v == x2 && y1 + v == y2)
		found = found || (x1 - v == x2 && y1 - v == y2)
		// secondary diagonal
		found = found || (x1 + v == x2 && y1 - v == y2)
		found = found || (x1 - v == x2 && y1 + v == y2)
	}
	return found
}

func main() {
	var x1, y1, x2, y2 int

	for {
		fmt.Scanln(&x1, &y1, &x2, &y2)
		if x1 + x2 + y1 + y2 == 0 {
			break
		}

		// check queen is above
		if x1 == x2 && y1 == y2 {
			fmt.Println(0)

		// check row, colum, diagonals
		}else if x1 == x2 || y1 == y2 || check_diagonals(x1, y1, x2, y2){
			fmt.Println(1)

		// any other case it takes 2 steps
		} else {
			fmt.Println(2)
		}


	}
}

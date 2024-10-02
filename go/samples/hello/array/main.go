package main

import (
	"fmt"
)

var x[5] int

func main() {
  x[0] = 33
  fmt.Println(x)

  y := [5]int{ 1,2,3,4,3 }
  fmt.Println(y)


  slice := []int{ 1,2,3,4,3 }

  slice = append(slice, 33,44)
  fmt.Println(slice)
}

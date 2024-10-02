package main

import (
	"fmt"
)

func main() {
  a := 10
  b := 100
  
  sum := func (x, y int) int {
    return x + y
  }

  fmt.Println(sum(a,b))
}

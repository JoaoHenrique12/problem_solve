package main

import (
	"fmt"
)

func main() {
  a := 10
  b := 100
  
  sum := rtr()
  
  fmt.Println(sum(a,b))
  fmt.Println(rtr()(a,b))
}

func rtr() (func(int, int) int)  {
  return func (x, y int) int {
    return x + y
  }
}

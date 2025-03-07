package main

import (
	"fmt"
)

func makeRange(min, max int) []int {
    a := make([]int, max-min+1)
    for i := range a {
        a[i] = min + i
    }
    return a
}

func sum(x... int) int {
  sum := 0
  for _, v := range x {
    sum += v
  }
  return sum
}

func remove_odd(f func(x... int)(int), values... int) int {
  var filtered []int
  for _, v := range values {
    if v % 2 == 0 {
      filtered = append(filtered, v)
    }
  }

  return f(filtered...)
}

// A callback function is a function passed into another function as an argument,
// which is then invoked inside the outer function to complete some kind of routine or action.
// 
// sum is the callback function in this case.

func main() {
  a := makeRange(0,10)
  fmt.Println(a)

  
  fmt.Println(remove_odd(sum, a...))
}

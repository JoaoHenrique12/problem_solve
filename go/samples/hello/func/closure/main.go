package main

import (
	"fmt"
)

func closure() (func() int) {
  sum := 0

  return func () (int) { sum++; return sum }
}

func main() {
  a := closure()

  fmt.Println(a())
  fmt.Println(a())
  fmt.Println(a())

  fmt.Println("---------------------------------")

  b := closure()

  fmt.Println(b())
  fmt.Println(b())
  fmt.Println(b())
}

package main

import (
	"fmt"
)


func main() {
  fmt.Println(soma(3,4))
  fmt.Println(soma_v(3,4,7,6))

  deferido()
}

func deferido() () {
  fmt.Println("Open file 1")
  defer fmt.Println("Close file 1")

  fmt.Println("Open file 2")
  defer fmt.Println("Close file 2")
}

func soma(x,y int) int {
  return x + y
}

func soma_v(x... int) (int, int) {
  soma := 0

  for _, v := range x {
    soma += v
  }
  return soma, len(x)
}

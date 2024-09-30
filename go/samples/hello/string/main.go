package main

import (
	"fmt"
)

const (
    a = iota
    b 
    x
    y
    z
)

func main() {
  s := "Hello, batman"
  sb := []byte(s)

  for _, v := range sb {
    fmt.Printf("%03d %T - %#U %#x\n", v, v, v, v)
  }

  for i := 0; i < len(sb); i++ {
    fmt.Printf("%03d %T - %#U %#x\n", sb[i], sb[i], sb[i], sb[i])
  }

  fmt.Printf("\n%d %b %x\n", 10, 10, 10)

  fmt.Printf("\n")
  fmt.Printf("%d %d %d %d %d\n", a, b, x, y, z)

  fmt.Printf("--------------------------\n")
  if x := 10; x > 10 {
    fmt.Printf("x > 10\n")
  } else if x < -1 {
    fmt.Printf("x < -1\n")
  } else {
    fmt.Printf("else\n")
  }

}

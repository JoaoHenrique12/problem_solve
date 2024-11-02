package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
  canal := converge(trabalho("XXXX"), trabalho("YYYY"))

  for i := 0; i < 16; i++ {
    fmt.Println(<-canal)
  }
}

func trabalho(s string) chan string {
  canal := make(chan string)

  go func (c chan string, s string) {
    for i := 0; ; i++ {
      time.Sleep(time.Duration(rand.Intn(3)))
      c<- fmt.Sprintf("funcao %v diz %v", s, i)
    }
  }(canal, s)

  return canal
}

func converge(c1, c2 chan string) chan string {
  novo := make(chan string)
  go func() {
    for {
      novo<- <-c1
    }
  }()

  go func() {
    for {
      novo<- <-c2
    }
  }()

  return novo
}

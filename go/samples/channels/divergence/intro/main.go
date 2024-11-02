package main

import (
	"fmt"
	"math/rand"
	"sync"
	"time"
)

func main() {
  c1 := make(chan int)
  c2 := make(chan int)
  go manda(c1, 2000000)
  go diverge(c1, c2)

  for v := range c2 {
    fmt.Println(v)
  }
}

func manda(c chan int, n int) {
  for i := 0; i < n; i++ {
    c<- i
  }
  close(c)
}

func diverge(c1, c2 chan int) {
  var wg sync.WaitGroup

  for v := range c1 {
    wg.Add(1)
    go func (x int)  {
      c2<- x
      wg.Done()
    }(v)
    wg.Wait()
  }
  close(c2)
}


func trabalho(n int) int {
  time.Sleep(time.Duration(rand.Intn(3)))
  return n * 3
}

package main

import (
	"fmt"
	"runtime"
	"sync"
)

var wg sync.WaitGroup

func main() {
  wg.Add(2)

  fmt.Println(runtime.NumCPU())
  fmt.Println("goroutines:",runtime.NumGoroutine())

  go func1()
  go func2()
  fmt.Println("goroutines:",runtime.NumGoroutine())

  wg.Wait()
}

func func1()  {
  for i := 0; i < 100; i++ {
    fmt.Println("Func 1 executing", i)
  }
  wg.Done()
}

func func2()  {
  for i := 0; i < 100; i++ {
    fmt.Println("Func 2 executing", i)
  }
  wg.Done()
}


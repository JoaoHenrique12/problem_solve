package main

import (
	"fmt"
	"runtime"
	"sync"
	"sync/atomic"
)

var wg sync.WaitGroup

func main() {
  fmt.Println("CPUS:", runtime.NumCPU())
  fmt.Println("Go routines:", runtime.NumGoroutine())
  var contador int32 = 0
  goroutines_size := 100

  var wg sync.WaitGroup
  // var mutex sync.Mutex
  
  wg.Add(goroutines_size)
  for i := 0; i < goroutines_size; i++ {
    go func()  {
      atomic.AddInt32(&contador, 1)
      runtime.Gosched()
      wg.Done()
    }()
  }

  wg.Wait()

  fmt.Println("contador:", contador)
}


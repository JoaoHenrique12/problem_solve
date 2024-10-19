package main

import (
	"fmt"
	"runtime"
	"sync"
)

var wg sync.WaitGroup

func main() {
  fmt.Println("CPUS:", runtime.NumCPU())
  fmt.Println("Go routines:", runtime.NumGoroutine())
  contador := 0
  goroutines_size := 100

  var wg sync.WaitGroup
  // var mutex sync.Mutex
  
  wg.Add(goroutines_size)
  for i := 0; i < goroutines_size; i++ {
    go func()  {
      // mutex.Lock()
      v := contador
      runtime.Gosched()
      v++
      contador = v
      // mutex.Unlock()
      wg.Done()
    }()
  }

  wg.Wait()

  fmt.Println("contador:", contador)
}


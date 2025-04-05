package main

import (
	"fmt"
	"log"
	"os"
)
// Defers will be executed when a program panics, but calling os.Exit exits immediately, and deferred functions can't be run.
func main()  {
  f, err := os.Create("log.txt")
  if err != nil {
    fmt.Println("error creating log file")
  }
  defer f.Close()
  log.SetOutput(f)

  f2, err2 := os.Open("undefined_file.txt")
  if err2 != nil {
    // execute OS.exit and get out
    // log.Fatalln(err2)

    // Execute defers
    log.Panicln(err2)
  }
  var b []byte
  f2.Read(b)
  fmt.Println(b)
}

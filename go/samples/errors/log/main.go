package main

import (
	"fmt"
	"log"
	"os"
)

func main()  {
  f, err := os.Create("log.txt")
  if err != nil {
    fmt.Println("error creating log file")
  }
  defer f.Close()
  log.SetOutput(f)

  f2, err2 := os.Open("undefined_file.txt")
  if err2 != nil {
    // log.Fatalln(err2)
    log.Panicln(err2)
  }
  var b []byte
  f2.Read(b)
  fmt.Println(b)
}

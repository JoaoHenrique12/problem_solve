package main

import (
	"fmt"
	"os"
)

func main()  {
  f, err := os.Open("undefined_file.txt")
  if err != nil {
    panic("Error opening unexistent file !")
  }
  var b []byte = []byte("abc")
  f.Read(b)
  fmt.Println(b)
}

package main

import (
	"errors"
	"log"
)

var ErrorSqrt = errors.New("could not calculate sqrt for negative number")

func main()  {
  _, err := sqrt(-3)
  if err != nil {
    log.Fatalln(err)
  }
}

func sqrt(x float64) (float64, error) {
  if x < 0 {
    return 0, ErrorSqrt
  }
  return 42, nil
}

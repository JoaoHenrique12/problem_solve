package main

import (
	"fmt"
	"log"
)

type mathError struct {
  info string
  err error
}

func (e mathError) Error() string{
  return fmt.Sprintf("a math error occurred (info, error): (%v, %v)", e.info, e.err)
}

func main()  {
  _, err := sqrt(-3)
  if err != nil {
    log.Fatalln(err)
  }
}

func sqrt(x float64) (float64, error) {
  if x < 0 {
    sqrt_error := mathError{
      info: fmt.Sprintf("input value: %v", x),
      err: fmt.Errorf("could not calculate a value for negative value"),
    }
    return 0, sqrt_error
  }
  return 42, nil
}

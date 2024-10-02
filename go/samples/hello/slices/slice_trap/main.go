package main

import "fmt"

// a surpresa do array subjacente
func main()  {
  slc := []int{1,2,3,4,5}
  fmt.Printf("%v\n", slc)

  scd := append(slc[:2], slc[4:]...)
  fmt.Printf("%v\n", scd)

  fmt.Printf("%v\n", slc)
}

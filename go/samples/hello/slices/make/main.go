package main

import "fmt"

func main()  {
  slc := []int{1,2,3,4}

  fmt.Printf("len, capacity: %v %v\n", len(slc), cap(slc))

  //                len, cap
  slc2 := make([]int, 4, 8)
  fmt.Printf("len, capacity: %v %v\n", len(slc2), cap(slc2))
  fmt.Printf("%v\n", slc2)
}

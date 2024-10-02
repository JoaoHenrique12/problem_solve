package main

import "fmt"

// a surpresa do array subjacente
func main()  {
  mp := map[string]int{
    "a":1,
    "b":2,
    "c":3,
  }

  mp["d"] = 4

  fmt.Println(mp)

  if value, ok := mp["x"]; ok {
    fmt.Println(value)
  }else {
    fmt.Println("Not found key.")
  }

  delete(mp, "d")

  for key, value := range mp {
    fmt.Println(key, value)
  }
}

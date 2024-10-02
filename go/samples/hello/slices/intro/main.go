package main

import "fmt"

func main()  {
  str_slice := []string{"abc", "kty", "itc"}

  str_slice = append(str_slice, "ubt")

  for index, value := range str_slice {
    fmt.Printf("(index, value): (%v, %v)\n", index, value)
  }

  fmt.Print("----------------------------------------\n")

  var slc []string = str_slice[:3]

  for index, value := range slc {
    fmt.Printf("(index, value): (%v, %v)\n", index, value)
  }


  fmt.Print("----------------------------------------\n")

  slc = append(str_slice, "a", "b", "c")

  for index, value := range slc {
    fmt.Printf("(index, value): (%v, %v)\n", index, value)
  }

  fmt.Print("----------------------------------------\n")

  slc = append(str_slice[:2], str_slice[3:]...)

  for index, value := range slc {
    fmt.Printf("(index, value): (%v, %v)\n", index, value)
  }
}

package main

import "fmt"

var global_in_package string = "eita"

var global_in_package_raw string = `"eita\n\t"`

type hotdog int

var abc hotdog

// 0, false, "", nil

func main() {
  bytes, _ := fmt.Println("hello world", "abc", 100, 3.14159)

  a := true  // Operador curto, atribui valor e tipo a variavel.
  a = false

  a, z := true, 15

  fmt.Println(bytes, a)
  fmt.Printf("(value, type): (%v, %T)\n", a, a)
  fmt.Printf("(value, type): (%v, %T)\n", z, z)

  fmt.Printf("(value, type): (%v, %T)\n", global_in_package, global_in_package)
  fmt.Printf("(value, type): (%v, %T)\n", global_in_package_raw, global_in_package_raw)

  str := fmt.Sprint("a", ",", "k")

  fmt.Printf(str)
  fmt.Println()

  fmt.Printf("(value, type): (%v, %T)\n", abc, abc)

  x := int(abc)

  fmt.Printf("(value, type): (%v, %T)\n", x, x)

}

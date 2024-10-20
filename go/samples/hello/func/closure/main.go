package main

import (
	"fmt"
)

// Uma closure é a combinação de uma função com as referências ao estado que a circunda (o ambiente léxico).
// Em outras palavras, uma closure lhe dá acesso ao escopo de uma função externa a partir de uma função interna.

func closure() (func() int) {
  sum := 0

  return func () (int) { sum++; return sum }
}

func main() {
  a := closure()

  fmt.Println(a())
  fmt.Println(a())
  fmt.Println(a())

  fmt.Println("---------------------------------")

  b := closure()

  fmt.Println(b())
  fmt.Println(b())
  fmt.Println(b())
}

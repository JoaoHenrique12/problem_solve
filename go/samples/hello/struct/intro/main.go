package main

import (
	"fmt"
)

type cliente struct {
  nome    string
  idade   int
  fumante bool
}

type pessoa struct {
  nome    string
  idade   int
}

type profissional struct {
  p pessoa
  salario int
  titulo string
}

func main() {

  joao := cliente{
    nome: "Joao",
    idade: 10,
    fumante: true,
  }

  maria := cliente{ "maria", 20, false, }

  fmt.Println(joao, maria)

  fmt.Println("----------------------------------------")
  p1 := pessoa{"andre", 14}
  p2 := profissional{p1, 1000, "camareiro"}

  fmt.Println(p1, p2)

  fmt.Println("----------------------------------------")
  anom := struct {nome string; cansado bool}{"anom", true}

  fmt.Println(anom)
}

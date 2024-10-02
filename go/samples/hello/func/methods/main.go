package main

import (
	"fmt"
)

type pessoa struct {
  nome string
  idade int
}

func (p pessoa) bomdia() () {
  fmt.Println("Bom dia advindo do", p.nome)
}

func main() {
  var marco pessoa = pessoa{"marco", 10}
  marco.bomdia()
}

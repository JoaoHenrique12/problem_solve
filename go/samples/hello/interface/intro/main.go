package main

import (
	"fmt"
)

type pessoa struct {
  nome string
  idade int
}

type dentista struct {
  p pessoa
  dentes_arrancados int
}

type arquiteto struct {
  p pessoa
  percentual_loucura int
}

func (p dentista) oibomdia()  {
  fmt.Println("Ola, sou um dentista que arrancou ", p.dentes_arrancados ,"dentes" )
}

func (p arquiteto) oibomdia()  {
  fmt.Println("Ola, sou um arquiteto com grau de loucura ", p.percentual_loucura ,"%" )
}

type gente interface {
  oibomdia()
}

func gente_oibomdia(g gente)  {
  g.oibomdia()
  switch g.(type) {
    case dentista:
      fmt.Println("Ola, eu sou o dentista fera")
    case arquiteto:
      fmt.Println("Ola, eu sou o arquiteto sera")
  }
}

func main() {
  var dentista_marco dentista = dentista{p : pessoa{"marco", 10}, dentes_arrancados: 11}
  arquiteto_marco := arquiteto{p: pessoa{"marco", 10},percentual_loucura: 50}

  gente_oibomdia(dentista_marco)
  fmt.Println()
  gente_oibomdia(arquiteto_marco)
}

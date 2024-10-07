package main

import "fmt"

type pessoa struct {
  nome string
  idade int
}

func soma_idade(p *pessoa) {
  (*p).idade++
}

func main(){
  x := 10
  var y *int = &x
  reference(y)
  fmt.Println(x, y)

  fmt.Println("----------------------------------------")

  gerd := pessoa{"gerd", 60}
  soma_idade(&gerd)

  fmt.Println(gerd)

}

func reference(x *int)  {
  *x++
}

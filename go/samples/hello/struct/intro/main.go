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
        p       pessoa
        salario int
        titulo  string
}

func main() {
        // Creating cliente objects in different ways:

        // 1. Using named fields:
        joao := cliente{
                nome:    "Joao",
                idade:   10,
                fumante: true,
        }

        // 2. Using positional fields (order matters):
        maria := cliente{"maria", 20, false}

        // 3. Using a combination of named and positional fields (not recommended for clarity):
        //   It is generally best to stick to one style or the other.
        //   Example (not recommended):
        //   cliente{"bob", idade: 30, true} // This is valid, but confusing.

        // 4. Creating an empty struct and then assigning values:
        pedro := cliente{}
        pedro.nome = "Pedro"
        pedro.idade = 25
        pedro.fumante = false

        fmt.Println(joao, maria, pedro)

        fmt.Println("----------------------------------------")

        // Creating pessoa and profissional objects:

        // 1. Creating pessoa directly:
        p1 := pessoa{"andre", 14}

        // 2. Creating profissional with an embedded pessoa:
        p2 := profissional{p1, 1000, "camareiro"}

        // 3. Creating profissional with an anonymous pessoa:
        p3 := profissional{
                p:       pessoa{nome: "ana", idade: 30},
                salario: 2000,
                titulo:  "developer",
        }

        // 4. Creating profissional by assigning values after creation:
        p4 := profissional{}
        p4.p.nome = "carlos"
        p4.p.idade = 40
        p4.salario = 3000
        p4.titulo = "manager"

        fmt.Println(p1, p2, p3, p4)

        fmt.Println("----------------------------------------")

        // Creating an anonymous struct:

        // 1. Creating an anonymous struct with initialization:
        anom := struct {
                nome    string
                cansado bool
        }{"anom", true}

        // 2. Creating an anonymous struct and then assigning values:
        anom2 := struct {
                nome    string
                cansado bool
        }{}
        anom2.nome = "another"
        anom2.cansado = false

        fmt.Println(anom, anom2)
}

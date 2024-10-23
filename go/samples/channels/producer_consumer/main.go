package main

import "fmt"


func main() {

    var canal chan int = make(chan int)

    go send(canal, 10)
    receive(canal)
}


func send(s chan<- int, count int)  {
    for i := 0; i <= count; i++ {
        s<- i*i
    }

    close(s)
}


func receive(s <-chan int)  {
    for v := range s {
        fmt.Println("Valor recebido do canal:", v)
    }
}

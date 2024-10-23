package main

import "fmt"

// Generally buffers are not used, they said

func main() {

    var canal chan int = make(chan int)

    // var canal_send chan<- int = make(chan<- int)
    // var canal_receive <-chan int = make(<-chan int)

    go send(canal)
    receive(canal)
}


func send(s chan<- int)  {
   s<- 42
}

func receive(s <-chan int)  {
    fmt.Printf("Received number: %v\n", <-s)
}

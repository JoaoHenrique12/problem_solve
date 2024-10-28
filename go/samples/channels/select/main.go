package main

import "fmt"

// Generally buffers are not used, they said

func main() {

    var canal1 chan int = make(chan int)
    var canal2 chan int = make(chan int)

    x := 500

    go func (x int)  {
        for i := 0; i < x; i++{
            canal1<- i
        }
    }(x/2)

    go func (x int)  {
        for i := 0; i < x; i++{
            canal2<- i
        }
    }(x/2)

    for i := 0; i < x; i++ {
        select {
        case v := <-canal1:
            fmt.Println("Canal A:", v)
        case v := <-canal2:
            fmt.Println("Canal B:", v)
        }
    }
}

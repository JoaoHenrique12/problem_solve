package main

import "fmt"


func main() {

    var canal1 chan int = make(chan int)
    var canal2 chan int = make(chan int)

    x := 10

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
		// The select statement allows the goroutine to wait on multiple
		// communication operations. It will execute the first case that
		// is ready to communicate.
        select {
        case v := <-canal1:
            fmt.Println("Canal A:", v)
        case v := <-canal2:
            fmt.Println("Canal B:", v)
        }
    }
}

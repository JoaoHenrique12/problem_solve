package main

import "fmt"

// Generally buffers are not used, they said

func main() {

    var messages chan string = make(chan string, 1) // Buffer

    messages <- "ping"
    // messages <- "pong"

    msg := <-messages
    fmt.Println(msg)
}

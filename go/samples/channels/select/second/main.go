package main

import "fmt"

func main() {
	canal := make(chan int)
	quit := make(chan int)

	go ask_for_consume_then_send_quit(canal, quit)
	produce_until_receive_quit(canal, quit)
}

func ask_for_consume_then_send_quit(canal, quit chan int) {
	for i := 0; i < 50; i++ {
		fmt.Println("recebido:", <-canal)
	}
	quit <- 0
}

func produce_until_receive_quit(canal, quit chan int) {
	dunno := 1
	for {
		select {
		case canal <- dunno:
			dunno++
		case <-quit:
			return
		}
	}
}

package main

import "fmt"

func main() {
	canal := make(chan int)
	quit := make(chan int)

	go getquit(canal, quit)
	sendchannel(canal, quit)
}

func getquit(canal, quit chan int) {
	for i := 0; i < 50; i++ {
		fmt.Println("recebido:", <-canal)
	}
	quit <- 0
}

func sendchannel(canal, quit chan int) {
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

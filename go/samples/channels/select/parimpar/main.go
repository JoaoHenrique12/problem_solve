package main

import "fmt"

func main() {
	par := make(chan int)
	impar := make(chan int)
	quit := make(chan bool)

	go produce(par, impar, quit)
	consume(par, impar, quit)
}

func produce(par, impar chan int, quit chan bool) {
	for i := 0; i < 50; i++ {
		if i % 2 == 0 {
			par<- i
		}else {
			impar<- i
		}
	}
	quit<- true
}

func consume(par, impar chan int, quit chan bool) {
	for {
		select {
		case v := <-par:
		fmt.Println("O valor", v, "é par")
		case v := <-impar:
		fmt.Println("O valor", v, "é impar")
		case <-quit:
			return
		}
	}
}

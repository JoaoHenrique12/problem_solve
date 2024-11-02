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
	// ao fechar estes canais o consumidor printa 0, isto e resolvido com um if e comma ok
	// se nao fechar estes canais o erro tambem desaparece
	close(par)
	close(impar)
	quit<- true
}

func consume(par, impar chan int, quit chan bool) {
	for {
		select {
		case v, ok := <-par:
			if ok {
				fmt.Println("O valor", v, "é par")
			}
		case v, ok := <-impar:
			if ok {
		fmt.Println("O valor", v, "é impar")
			}
		case <-quit:
			return
		}
	}
}

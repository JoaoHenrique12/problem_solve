package main

import (
	"fmt"
	"sync"
)

func main() {
	par := make(chan int)
	impar := make(chan int)
	converge := make(chan int)

	go produce(par, impar)
	go consume(par, impar, converge)

	for v := range converge {
		fmt.Println(v)
	}

}

func produce(par, impar chan int) {
	for i := 0; i < 50; i++ {
		if i % 2 == 0 {
			par<- i
		}else {
			impar<- i
		}
	}
	close(par)
	close(impar)
}

func consume(par, impar chan int, converge chan int) {
	var wg sync.WaitGroup
	wg.Add(2)

	go func (){
		for v := range par {
			converge <- v
		}
		wg.Done()
	}()

	go func (){
		for v := range impar {
			converge <- v
		}
		wg.Done()
	}()

	wg.Wait()
	close(converge)
}

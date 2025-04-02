package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scanln(&n)

	var tmp int
	aparicoes := map[int]int{}
	for n != 0 {
		fmt.Scanln(&tmp)

		if _, ok := aparicoes[tmp]; ok {
			aparicoes[tmp]++
		}else{
			aparicoes[tmp] = 1
		}

		n--
	}

	sorted_keys := make([]int, 0, len(aparicoes))
	for key := range aparicoes {
		sorted_keys = append(sorted_keys, key)
	}

	sort.Ints(sorted_keys)

	for _, key := range sorted_keys{
		fmt.Printf("%v aparece %v vez(es)\n", key, aparicoes[key])
	}
}

package main

func main()  {
  println(soma(1,2,3,4))
}

func soma(lst ...int) int {
  total := 0

  for _, v := range lst {
    total += v
  }

  return total
}

func multiplica(lst ...int) int {
  total := 1

  for _, v := range lst {
    total *= v
  }

  return total
}

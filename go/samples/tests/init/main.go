package main

func main()  {
  println(Soma(1,2,3,4))
}

func Soma(lst ...int) int {
  total := 0

  for _, v := range lst {
    total += v
  }

  return total
}

func Multiplica(lst ...int) int {
  total := 1

  for _, v := range lst {
    total *= v
  }

  return total
}

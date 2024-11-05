package main

import (
	"fmt"
	"testing"
)

func ExampleSoma() {
  fmt.Println(Soma(1,2,3,4))
  fmt.Println(Soma(1,2,3,5))
  fmt.Println(Soma(1,2,3,6))
  // Output:
  // 10
  // 11
  // 12
}


func TestSoma(t *testing.T){
  expected := 6
  output := Soma(1,2,3)

  if expected != output {
    t.Error("Expected:", expected, "Got:", output)
  }
}

type parammultiply struct {
  input []int
  expected int
}
func TestMultiplica(t *testing.T){
  testset := []parammultiply{
    {input: []int{1, 2, 4}, expected: 8},
    {[]int{1, 2, 3}, 6},
  }

  for _, v := range testset {
    output := Multiplica(v.input...)
    if v.expected != output {
      t.Error("Expected:", v.expected, "Got:", output)
    }
  }

}

func BenchmarkSoma(b *testing.B){
  for i := 0; i < b.N; i++ {
    Soma(1,2,3,4)
  }
}

func BenchmarkMultiplica(b *testing.B){
  for i := 0; i < b.N; i++ {
    Multiplica(1,2,3,4)
  }
}

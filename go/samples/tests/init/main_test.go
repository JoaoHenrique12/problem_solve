package main

import "testing"

func TestSoma(t *testing.T){
  expected := 6
  output := soma(1,2,3)

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
    output := multiplica(v.input...)
    if v.expected != output {
      t.Error("Expected:", v.expected, "Got:", output)
    }
  }

}

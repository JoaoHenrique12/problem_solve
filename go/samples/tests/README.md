# Tests


## Context
```bash
# run tests
go test -v

# run all test in this folder and it's child
go test ./...
```

- There is no parametrized tests, people use for loop

## ExampleFunctionName

Is possible create sample tests wich is show on documentation.

```go
func ExampleSoma() {
  fmt.Println(Soma(1,2,3,4))
  fmt.Println(Soma(1,2,3,5))
  fmt.Println(Soma(1,2,3,6))
  // Output:
  // 10
  // 11
  // 12
}
```

## BenchmarkFunctionName

```bash
go test -bench .
# go test -benchmem .
```

## Coverage
```bash
go test -cover
go test -coverprofile c.out

go tool cover -html=c.out
go tool cover -h
```

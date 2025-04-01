# GO

[traps](https://go-traps.appspot.com/#overview)

[stylish](https://rakyll.org/style-packages/)

[go get X go install](https://medium.com/@chaewonkong/difference-between-go-get-and-go-install-in-go-a076d7352186)

[read ways in GO](https://gosamples.dev/read-user-input/)

- go get  == pip install

## Rename package

```go
import (
    gourl "net/url"

    "myother.com/url"
)
```


## Env vars

```bash
go env
```

## cross compiling

```bash
# windows
GOOS=windows GOARCH=amd64 go build main.go
# mac
GOOS=darwin GOARCH=amd64 go build main.go
```

## Execute

```bash
# Execute go code
go run main.go
go build main.go
```

## GO mod

O arquivo go.sum é o que armazena os hashes das libs. Ele é gerado automaticamente.

### Init
```bash
go mod init github.com/seu-usuario/seu-projeto
```

### Adiciona dependencia

```bash
go get github.com/novo/pacote
```

### Atualiza dependencia

```bash
go get -u
```

### Verifica dependencia

```bash
go list -m all
```

### Remove dependencia

```bash
go mod tidy
```

## [Module organizing](https://go.dev/doc/modules/layout#server-project)

### Basic

The “main” file can also be called modname.go

```
project-root-directory/
  go.mod
  modname.go
  modname_test.go
```

```
project-root-directory/
  go.mod
  auth.go
  auth_test.go
  client.go
  main.go
```

The directory named [internal](https://pkg.go.dev/cmd/go#hdr-Internal_Directories) prevent to show internal dependencies.
```
project-root-directory/
  internal/
    auth/
      auth.go
      auth_test.go
    hash/
      hash.go
      hash_test.go
  go.mod
  modname.go
  modname_test.go

```


## Constantes

O tipo de uma constante é definido no uso

```go
const (
    x = 10
    y = 20
)
```

```go
const (
    a = iota
    b = iota
    x = iota
    y = iota
    z = iota
)
```

## defer

```go
func deferido() () {
  fmt.Println("Open file 1")
  defer fmt.Println("Close file 1")

  fmt.Println("Open file 2")
  defer fmt.Println("Close file 2")
}

// Funciona como uma pilha
```

## Export | Import

Para deixar publico em GO, tem que comecar com letra maiuscula

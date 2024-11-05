# GoLang

## Tools

```bash

go help testflag

```

### gofmt
```bash
# Formatar o codigo
gofmt ./... -w
```

### go vet

Vet examines Go source code and reports suspicious constructs, such as Printf calls whose arguments do not align with the format string.
Vet uses heuristics that do not guarantee all reports are genuine problems, but it can find errors not caught by the compilers.

```bash
go vet ./... -w
```

### golint

```bash
golint ./... -w
```

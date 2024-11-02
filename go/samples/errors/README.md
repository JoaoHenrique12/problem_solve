# Errors

O tratamento de erros em GoLang é diferente do usado por outras linguagens, não existe try-except-finally.
[Type error](https://go.dev/blog/error-handling-and-go).

- panic -> executa os defer
- fatal -> https://pkg.go.dev/log#Fatal

Função recover do package built in [recover](https://www.youtube.com/watch?v=pKh7ApRSDXk&list=PLCKpcjBB_VlBsxJ9IseNxFllf-UFEXOdg&index=164&ab_channel=AprendaGo)

Errors value in go aren't special, they are values like any other.

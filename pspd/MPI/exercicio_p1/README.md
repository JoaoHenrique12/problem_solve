# Exercícios PSPD

## Alunos

João Henrique Paulino - 180033620
Júlio Cesar -

## Sobre os exercícios

As questões 1 e 2 foram atualizadas com relação a sua condição
de parada, gerando assim os arquivos oficiais, que são o v2_main.c

Sobre a questão 3: a pesar do que foi dito na referencia do [stackoverflow](https://stackoverflow.com/questions/1716296/why-does-printf-not-flush-after-the-call-unless-a-newline-is-in-the-format-strin)
e da aplicação correta do round robin a saida ainda não estava sendo formatada corretamente, o que forçou o uso do usleep(1), corrigindo
a formatação da mensagem.

```c
// A pesar do programa imprimir colaborativamente e fprintf na stderr já fazer o flush da mensagem, 
// o texto ainda saia desorganizado. Com este usleep(1) ele organiza a saida perfeitamente.
// A principal diferença deste programa para os anteriores é que o token daqui representa 2 variáveis
// do programa original: token[0] == cont e token[1] é o indice.
//
// O esquema de colaboração round-robin/token-ring daqui é idêntico ao dos exercícios anteriores.
```

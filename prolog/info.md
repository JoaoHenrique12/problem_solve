# Prolog

## Comandos

- Interpretador: swipl

- Compilando o código: ?- consult('main.pl'). 

- write('Olá mundo'), nl, write('Lá vem o batman').

- read(X).
- get(Z). Pega só um char.
- put(Z). Printa o char.

- format('Avo de ~w ~s ~w ~n', [X,"é ",K]). var, str, var, newline.


- trace. -> debug.
- notrace. -> desativa debug.

## Notações

- Fim de comando tem '.'
- Pedir nova iteração ';'
- AND ','
- OR ';'
- NOT \==
- Lê como se fosse um se ':-'.
- The underscores _ just indicate that there is a value in that position, but we don't care about it.

- ~2f -> flotat com 2 casas.

- estrutura: data(5, setembro, 2022).

## Operadores lógicos e aritméticos

- 3 >= 15.
- \\+ ( alice = bob ).
- alice = alice.
- 2\*\*3 = 8
- 5 // 3 = 1

## Cut, se.

### SE

(X > 10 -> Y is X - 1; Y is X + 1),

### CUT

'!'

### if else

ifelse(X,Y,\_) :- X,!,Y.
ifelse(\_,\_,Z) :- Z.

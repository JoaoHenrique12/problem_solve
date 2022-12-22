% Fatos

gerou(kelly, maria).
gerou(cleber, maria).
gerou(cleber, bruna).
gerou(maria, julia).
gerou(maria, pedro).
gerou(pedro, lucas).

feminino(maria).
feminino(kelly).
feminino(bruna).
feminino(julia).

% Regras.

% :- lê como se fosse um se.

masculino(X) :- not(feminino(X)).
filho(X,Y) :- gerou(Y,X).
avos(X,K) :-
  gerou(K,Y),
  gerou(Y,X),
  format('Avo de ~w ~s ~w ~n', [X,"é ",K]).

ancestral(X,Y) :-
  gerou(Y,X),
  format('~w ~n',[Y]),
  ancestral(Y,Z).

irmaos(X,Y) :-
  gerou(K,X),
  gerou(K,Y),
  (X \== Y).


ifelse(X,Y,_) :- X,!,Y.
ifelse(_,_,Z) :- Z.

% Filhos de A: , ';' é usado para perguntar se tem mais 'filhos'.

% gerou(maria, X).
% gerou(maria, X);

% Irmãos de A, a vírgula funciona como se fosse um and:
% gerou(X,pedro), gerou(X,Y).

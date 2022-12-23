% Adiciona e remove fatos dinamicamente.
% retractall(pessoa(_,_,30)). // Remove todas as pessoas de 30 anos.
% assertz(pessoa(cleiton,brasil,23)). // Adiciona uma pessoa.
:- dynamic pessoa/3.


% Base de dados 1
gosta(maria,cafe).
gosta(jose,cha).
gosta(ana,guarana).
gosta(pedro,vinho).
gosta(jose,coca).
gosta(maria,vinho).

% Base de dados 2

pessoa(joao,itau,30).
pessoa(jose,nacional,35).
pessoa(maria,real,30).


% findall(Idade/Quem,pessoa(Quem,_,Idade),L).


% bagof(Y,gosta(X,Y),L).
% retorna em X as pessoas e em Y as bebidas.
%
% setof(Y,gosta(X,Y),L).

suspeito(fred).
suspeito(mary).
suspeito(jane).
suspeito(george).

crime(roubo,jhon,terca,parque).
crime(roubo,robin,terca,bar).
crime(assalto,jim,quarta,bar).

estava(fred,terca,parque).

inveja(fred,jhon).

tem_motivo(Pessoa,Vitima) :-
  inveja(Pessoa,Vitima).

principal_suspeito(Pessoa,Crime) :-
  crime(Crime,Vitima,Dia,Lugar),
  suspeito(Pessoa),
  estava(Pessoa,Dia,Lugar),
  tem_motivo(Pessoa,Vitima).

% Fornece a saida: Desconhecido.
% Se este trecho ficar acima da regra principala suspeito
% ele retorna desconhecido e depois a lista de suspeitos.
principal_suspeito(desconhecido,Crime).

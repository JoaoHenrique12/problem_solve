dances(alice).

does_alice_dance :- 
  dances(alice),
  write('When Alice is happy she dances.').

what_grade(5) :-
  write('Go to kindergarten').

what_grade(6) :-
  write('Go to first grade').

what_grade(Other) :-
  Grade is Other - 3,
  format('Go to grade ~w', [Grade]).

count_ten(10) :- write(10),nl.

count_ten(X) :- 
  write(X),nl,
  (X > 10 -> Y is X - 1; Y is X + 1),
  count_ten(Y).

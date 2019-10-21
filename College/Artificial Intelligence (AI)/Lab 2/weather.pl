weather(kathmandu, summer, warm).
weather(nepalgunj, summer, hot).
weather(sagarmatha, summer, cold).

warmer_than(A, B):-
    weather(A, summer, hot),
    weather(B, summer, warm);
    weather(B, summer, cold),
    write(A), write(' is warmer than '), write(B).

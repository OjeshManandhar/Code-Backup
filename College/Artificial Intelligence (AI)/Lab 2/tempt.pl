WeatherFtemp(Kathmandu, 90).
weather_ftemp(pokhara, 100).

weather_ctemp(C1, Ctemp):-
    weather_ftemp(C1, Ftemp),
    Ctemp is ((Ftemp - 32)*(5/9)).

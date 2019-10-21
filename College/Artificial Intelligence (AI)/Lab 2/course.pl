Course(
    ai,
    day(monday, wednesday),
    time(11, 1),
    teacher(sujan),
    complexity(mid)
).

lecturer(Subject, D1, D2, Teacher):-
    course(Subject, day(D1, D2), _, Teacher, _).

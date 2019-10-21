likes(X, fish) :- cat(X).
cat(mani).
eats(X, Y) :- cat(X), likes(X, Y).

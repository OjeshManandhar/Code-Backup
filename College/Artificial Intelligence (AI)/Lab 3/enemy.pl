enemyofa(nono).
weapon(missile).
american(colonel).
missile(X) :- has(nono, X),  has(colonel, X).
sell(colonel, nono, X) :- missile(X), has(colonel,X).

criminal(X) :- weapon(Z), american(X), enemyofa(Y), sell(X, Y, Z).

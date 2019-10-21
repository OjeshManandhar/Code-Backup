boy(hoston).
boy(edmure).
boy(richard).
boy(ned).
boy(benjen).
boy(madking).
boy(reghar).
boy(rob).
boy(bran).
boy(rickon).
boy(jon).

girl(lysa).
girl(catalyn).
girl(lyana).
girl(sansa).
girl(arya).

father(hoston, lysa).
father(hoston, edmure).
father(hoston, catalyn).
father(richard, ned).
father(richard, benjen).
father(richard, lyana).
father(madking, reghar).
father(ned, rob).
father(ned, sansa).
father(ned, bran).
father(ned, arya).
father(ned, rickon).
father(reghar, jon).

mother(catalyn, rob).
mother(catalyn, sansa).
mother(catalyn, bran).
mother(catalyn, arya).
mother(catalyn, rickon).
mother(lyana, jon).

parent(X, Y):- father(X, Y); mother(X, Y).

grandparent(X, Y):- parent(X, Z), parent(Z, Y).

grandfather(X, Y):- grandparent(X, Y), boy(X).

grandmother(X, Y):- grandparent(X, Y), girl(X).

siblings(X, Y):- parent(Z, X), parent(Z, Y).

brothers(X, Y):- siblings(X, Y), boy(X), boy(Y).

sisters(X, Y):- siblings(X, Y), girl(X), girl(Y).

husband_wife(X, Y):- parent(X, Z), parent(Y, Z).

uncle(X, Y):- siblings(X, Z), parent(Z, Y), boy(X).

aunt(X, Y):- siblings(X, Z), parent(Z, Y), girl(X).
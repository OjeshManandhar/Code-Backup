#define SQPERI(l,p) (p=l*4)

#define SQAREA(l,a) (a=l*l)

#define TRIPERI(a,b,c,pt) (pt=a+b+c)

#define TRIAREA(a,b,c,at,s) {\
                                s=(a+b+c)/2.0;\
                                at=s*(s-a)*(s-b)*(s-c);\
                                at=pow(at,0.5);\
                            }

#define CRIPERI(r,pc) (pc=2*3.14*r)

#define CRIAREA(r,ac) (ac=3.14*r*r)

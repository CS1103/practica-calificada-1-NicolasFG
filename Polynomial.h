#ifndef POLINOMIO_POLINOMIO_H
#define POLINOMIO_POLINOMIO_H
#include <vector>
using namespace std;

typedef struct nodoPoly *POLY;

class Polynomial {

private:
    POLY primero;
    POLY ultimo;
public:
    Polynomial() = default;
    ~Polynomial();

    void creaPoly();
    void creaNodoPoly(double co, int ex);
    Polynomial const_mult_poly(float);
    void printPoly();
    Polynomial sumaPoly( Polynomial a, Polynomial b );
    Polynomial potenciaPoly(Polynomial a);



};

#endif //POLINOMIO_POLINOMIO_H

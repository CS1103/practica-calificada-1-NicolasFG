#include <stdexcept>
#include <iostream>
#include "Polynomial.h"


struct nodoPoly{
    float coeficiente;
    int exponente;
    struct nodoPoly *sig;
};

//Listo crear nodo de polinomio
void Polynomial::creaNodoPoly(double co, int ex) {

    POLY t;
    t = new nodoPoly;
    t->coeficiente = co;
    t->exponente = ex;
    t->sig = NULL;
    if (ultimo == NULL)
        primero = t;
    else
        ultimo->sig = t;
    ultimo = t;
}


//Listo crear Polinomio
void Polynomial::creaPoly() {
    float coeficiente;
    int exponente, n;
    ultimo = NULL;
    cout<<"Ingrese numero de terminos del polinomio: ";
    cin>>n;
    for (int i = 0; i<n; i++)
    { cout<<"\nIngrese coeficiente: "; cin>>coeficiente;
        cout<<"Ingrese exponente: "; cin>>exponente;
        creaNodoPoly(coeficiente, exponente);
    }

}

void Polynomial::printPoly()
{
    POLY actual;
    actual = primero;
    cout<<"\nP(x) = ";

    while( actual != NULL)
    { if (actual -> exponente == 0) // ultimo termino
            cout<<actual->coeficiente;
        else // otro termino
            cout<<actual->coeficiente<<"X^"<<actual->exponente<<" + ";
        actual = actual->sig;
    }
    cout<<endl;
}

Polynomial Polynomial::const_mult_poly( float con )
{
    float c;
    POLY p;
    p = primero;
    ultimo = NULL;
    while (p != NULL)
    { c = con * p->coeficiente;
        if (c != 0)
            creaNodoPoly(c, p->exponente);
        p = p->sig;
    }
    return *this;
}

Polynomial Polynomial::sumaPoly( Polynomial a, Polynomial b )
{
    float c;
    POLY p, q;
    p = a.primero;
    q = b.primero;
    ultimo = NULL;
    while (p != NULL && q != NULL)
    { if (p->exponente == q->exponente)
        { c = p->coeficiente + q->coeficiente;
            if (c != 0)
                creaNodoPoly(c,p->exponente);
            p = p->sig;
            q = q->sig;
        }else
        if (p->exponente > q->exponente)
        { creaNodoPoly(p->coeficiente, p->exponente);
            p = p->sig;
        }
        else {
            creaNodoPoly(q->coeficiente, q->exponente);
            q = q->sig;
        }
    }
    while( p != NULL)
    { creaNodoPoly(p->coeficiente, p->exponente);
        p = p->sig;
    }
    while( q != NULL)
    { creaNodoPoly(q->coeficiente, q->exponente);
        q = q->sig;
    }
    return *this;
}

//Falta implementar
Polynomial::~Polynomial() {

}

//Falta implementar
Polynomial Polynomial::potenciaPoly(Polynomial a) {
    return Polynomial();
}






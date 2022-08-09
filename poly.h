//
// Created by arwal on 1/26/2020.
//Anna Waldron
//1/27/2020

#ifndef POLYNOMIAL_POLY_H
#define POLYNOMIAL_POLY_H


#include <string>
#include <iostream>
using namespace std;

class Poly {
    int sizeOfArray;
    int * polyarray;
public:
    Poly();

    Poly(int coeff);

    Poly(int coeff, int power);

    Poly(const Poly &other);

    ~Poly();

    int getCoeff(int x) const;

    void setCoeff(int coef, int expo);

    friend std::ostream &operator <<(std::ostream &stream, const Poly &polynomial){
        for(int i = polynomial.sizeOfArray - 1; i >= 0; i--){
            if(polynomial.polyarray[i] != 0){
                if(polynomial.polyarray[i] > 0 && i > 1){
                    stream << " +" << polynomial.polyarray[i] << "x^" << i;
                }else if (i > 1){
                    stream << " " << polynomial.polyarray[i] << "x^" << i;
                }else if (i == 1 && polynomial.polyarray[i] > 0){
                    stream<< " +" << polynomial.polyarray[i] << "x";
                }else if(i == 1 && polynomial.polyarray[i] < 0){
                    stream << " " << polynomial.polyarray[i] << "x";
                }else if(i == 0 && polynomial.polyarray[i] > 0){
                    stream << " +" << polynomial.polyarray[i];
                }else if(i == 0 && polynomial.polyarray[i] < 0){
                    stream << " " << polynomial.polyarray[i];
                }
            }
        }
        return stream;
    }
    Poly operator+(const Poly &polynomial);

    Poly operator-(const Poly &polynomial);

    Poly operator*(const Poly &polynomial);

    Poly operator=(const Poly &polynomial);

    Poly operator+=(const Poly &polynomial);

    Poly operator -=(const Poly &polynomial);

    Poly operator *=(const Poly &polynomial);

    friend std::istream &operator>>(std::istream &stream, Poly &polynomial){
        int coeff, exp;
        while( stream >> coeff && stream >> exp){
            if(exp < 0 ){break;}
            polynomial.polyarray[exp] = coeff;
        }
        return stream;
    }

    bool operator ==(const Poly& polynomial);

    bool operator !=(const Poly &polynomial);


    };


#endif //POLYNOMIAL_POLY_H
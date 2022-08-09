//
// Created by arwal on 1/27/2020.
//Anna Waldron
//1/27/2020

#include "poly.h"
/*
 * default constructor sets array to size one.
 */
Poly::Poly(){
    sizeOfArray = 1;
    polyarray = new int[1];
    polyarray[0] = 0;
}
/*
 * one argument constructor that takes in a coefficient for the polynomial.
 */
Poly::Poly(int coeff) {
    sizeOfArray = 1;
    polyarray = new int[1];
    polyarray[0] = coeff;
}
/*
 * two argument constructor  that takes a coefficient and power parameter
 */

Poly::Poly(int coeff, int power){
    sizeOfArray = power + 1;
    polyarray = new int[power + 1];
    for(int i = 0; i <= power; i++){
        polyarray[i] = 0;
    }
    polyarray[power] = coeff;
}
/*
 * copy constructor that returns a deep copy of object including array
 */

Poly::Poly(const Poly &other){
    sizeOfArray = other.sizeOfArray;
    polyarray = new int[other.sizeOfArray];
    for(int i = 0; i < other.sizeOfArray; i++){
        polyarray[i] = other.polyarray[i];
    }
}
/*
 * destructor that deletes the array contents
 */
Poly::~Poly(){
    sizeOfArray = 0;
    delete[] polyarray;
}
/*
 * Function to get the coefficient of the input exponent. Returns zero if
 * the exponent is negative or out of the array bounds
 */
int Poly::getCoeff(int x) const {
    if(x < 0 || x >= sizeOfArray){
        return 0;
    }
    else {
        return polyarray[x];
    }
}
/*
 * Function that sets the coefficient of the element with the input exponent. Returns zero if the exponent
 * is negative
 */
void Poly::setCoeff(int coef, int expo){
    if(expo < 0){
        return;
    }
    if(expo > sizeOfArray){
        Poly temp(*(this));
        delete[] polyarray;
        sizeOfArray = expo + 1;
        polyarray = new int[sizeOfArray];
        for(int j = 0; j < temp.sizeOfArray; j++){

            polyarray[j] = temp.polyarray[j];
        }

    }
    polyarray[expo] = coef;

}

/*
 * Overload function of the addition operator using two for loops to create a seperate object
 * to add together the two object array polynomials. Returns the new object
 */

Poly Poly::operator+(const Poly &polynomial){
    int larger = 0;
    int smaller = 0;

    if(this->sizeOfArray >= polynomial.sizeOfArray){
        larger = this->sizeOfArray;
        smaller = polynomial.sizeOfArray;
    }else if (this->sizeOfArray < polynomial.sizeOfArray){
        larger = polynomial.sizeOfArray;
        smaller = this->sizeOfArray;
    }
    Poly sum(0, larger - 1);
    for(int i = 0; i < smaller; i++){
        sum.polyarray[i] = this->getCoeff(i) + polynomial.getCoeff(i);
    }
    for(int j = smaller; j < larger; j++){
        sum.polyarray[j] = this->getCoeff(j) + polynomial.getCoeff(j);
    }
    return sum;
}
/*
 * Overload function of subtraction operator which creates a new object to then call
 * the add method and returns it
 */
Poly Poly::operator -(const Poly &polynomial){
    Poly temp(polynomial);
    for(int i = 0; i < temp.sizeOfArray; i++){
        temp.polyarray[i] = -1 * temp.polyarray[i];
    }

    return (*(this)+temp);
}
/*
 * Overload function of multiplication which creates a new object and adds the products of the
 * two polynomial objects and returns it
 */
Poly Poly::operator*(const Poly &polynomial){

    Poly product(0, (this->sizeOfArray + polynomial.sizeOfArray) -1);
    for(int i = 0; i < this->sizeOfArray; i++){
        for(int j = 0; j < polynomial.sizeOfArray; j++){
            product.polyarray[i + j] += this->polyarray[i] * polynomial.polyarray[j];

        }
    }
    return product;

}
/*
 * Overload assignment operator that creates a copy of the array and sets the values of the
 * assigned object and returns it
 */
Poly Poly::operator=(const Poly &polynomial){
    int * copy = new int[polynomial.sizeOfArray];
    for (int i = 0; i < polynomial.sizeOfArray; i++) {
        copy[i] = polynomial.polyarray[i];
    }
    delete[] this->polyarray;
    this->sizeOfArray = polynomial.sizeOfArray;
    this->polyarray = copy;

    return *this;
}

/*
 * Overload += function that adds two polynomials and sets one equal to it and returns it
 */

Poly Poly::operator+=(const Poly &polynomial){
    *(this) = *(this) + polynomial;
    return *this;
}
/*
 * overload -= function which does the same as the previous function
 */
Poly Poly::operator -=(const Poly &polynomial){
    *(this) = *(this) - polynomial;
    return *this;
}
/*
 * overload *= function which does the same as the previous function
 */
Poly Poly::operator *=(const Poly &polynomial){
    *(this) = *(this) * polynomial;
    return *this;
}
/*
 * overload equality function that tells if the contents of the obects are the same
 */
bool Poly::operator ==(const Poly& polynomial) {
    if (this->sizeOfArray != polynomial.sizeOfArray) {
        return false;
    }
    for (int i = 0; i < this->sizeOfArray; i++) {
        if (this->polyarray[i] != polynomial.polyarray[i]) {
            return false;
        }
    }
    return true;
}
/*
 * Overload inquality function that tells if the contents of the objects are not the same
 */
bool Poly::operator !=(const Poly &polynomial){
    if (this->sizeOfArray != polynomial.sizeOfArray) {
        return true;
    }
    for (int i = 0; i < this->sizeOfArray; i++) {
        if (this->polyarray[i] != polynomial.polyarray[i]) {
            return true;
        }
    }
    return false;
}



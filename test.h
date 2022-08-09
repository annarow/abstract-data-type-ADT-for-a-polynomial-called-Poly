//
// Created by arwal on 1/17/2020.
//

#ifndef UNTITLED3_TEST_H
#define UNTITLED3_TEST_H

#include "iostream"
#include "poly.h"

class testClass {

public:
    void helloThere(){
        std::cout << "Hello there!" << std::endl;
    }

    void check(){
        Poly A = Poly(5, 7);
        std::cout << "A: " << A << std::endl;
        Poly B = Poly(4, 4);
       // std::cout << A + B << endl;
        std::cout << A - B << std::endl;
        //std::cout << A.getCoeff(7) << std::endl;
        //A = B;
        //std::cout << A;
        A -= B;
        std::cout << A;
        Poly C(B);
        std::cout << B;
        std::cout << C << std::endl;
        bool test = B == C;
        std::cout << test << std::endl;
        test = A == B;
        std::cout << test << std::endl;

    }

};


#endif //UNTITLED3_TEST_H
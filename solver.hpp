#pragma once

#include <iostream>
#include <complex>

using namespace std;

namespace solver{
       


        class RealVariable{

            public:
                double x;
                RealVariable(): x(0){};


                friend RealVariable& operator+(RealVariable& r1, const double r);
                friend RealVariable& operator*(RealVariable& r1, const double r);
                friend RealVariable& operator-(RealVariable& r1, const double r);
                friend RealVariable& operator/(RealVariable& r1, const double r);
                friend RealVariable& operator==(RealVariable& r1, const double r);
                friend RealVariable& operator^(RealVariable& r1, const double r);

                friend RealVariable& operator+(RealVariable& r1,RealVariable& r2);
                friend RealVariable& operator*(RealVariable& r1,RealVariable& r2);
                friend RealVariable& operator-(RealVariable& r1, RealVariable& r2);
                friend RealVariable& operator/( RealVariable& r1,  RealVariable& r2);
                friend RealVariable& operator==(RealVariable& r1, RealVariable& r2);
                friend RealVariable& operator^(RealVariable& r1, RealVariable& r);

                friend RealVariable& operator+(double a, RealVariable& r);
                friend RealVariable& operator*(double a, RealVariable& r);
                friend RealVariable& operator-(double a, RealVariable& r);
                friend RealVariable& operator^(double a, RealVariable& r);
                friend RealVariable& operator/(double a, RealVariable& r);
                friend RealVariable& operator==(double a, RealVariable& r);

        };



        class ComplexVariable{

            double re;
            double im;

            public:
                
                ComplexVariable(double re = 0, double im = 0){
                    this->re = re;
                    this->im = im;
                }

                friend ComplexVariable& operator+(ComplexVariable& c, double a);
                friend ComplexVariable& operator*(ComplexVariable& c, double a);
                friend ComplexVariable& operator-(ComplexVariable& c, double a);
                friend ComplexVariable& operator/(ComplexVariable& c, double a);
                friend ComplexVariable& operator==(ComplexVariable& c, double a);
                friend ComplexVariable& operator^(ComplexVariable& c,double a);

                friend ComplexVariable& operator+(ComplexVariable& a,  complex<double> x);
                friend ComplexVariable& operator==(ComplexVariable& a, complex<double> x);

                friend ComplexVariable& operator+(ComplexVariable& c1,ComplexVariable& c2);
                friend ComplexVariable& operator-(ComplexVariable& c1, ComplexVariable& c2);
                friend ComplexVariable& operator*(ComplexVariable& c1, ComplexVariable& c2);
                friend ComplexVariable& operator/(ComplexVariable& c1, ComplexVariable& c2);
                friend ComplexVariable& operator==(ComplexVariable& c1,  ComplexVariable& c2);

                friend ComplexVariable& operator+(double a, ComplexVariable& c);
                friend ComplexVariable& operator*(double a, ComplexVariable& c);
                friend ComplexVariable& operator-(double a, ComplexVariable& c);
                friend ComplexVariable& operator/(double a, ComplexVariable& c);
                friend ComplexVariable& operator==(double a, ComplexVariable& c);

        };

        double solve(RealVariable);
        complex<double> solve(ComplexVariable);
}


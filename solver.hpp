#pragma once

#include <iostream>
#include <complex>

using namespace std;

namespace solver{
       


        class RealVariable{

            public:
                double x;
                RealVariable(): x(0){};


                RealVariable& operator+(const double r);//this+r
                RealVariable& operator*(const double r);//this*r
                RealVariable& operator-(const double r);//this-r
                RealVariable& operator/(const double r);//this/r
                RealVariable& operator==(const double r);//this==r
                RealVariable& operator^(const double r);//this*^r

                RealVariable& operator+(const RealVariable r);
                RealVariable& operator*(const RealVariable r);
                RealVariable& operator-(const RealVariable r);
                RealVariable& operator/(const RealVariable r);
                RealVariable& operator==(const RealVariable r);
                RealVariable& operator^(const RealVariable r);

                friend RealVariable& operator+(double a, RealVariable r);
                friend RealVariable& operator*(double a, RealVariable r);
                friend RealVariable& operator-(double a, RealVariable r);
                friend RealVariable& operator/(double a, RealVariable r);

        };



        class ComplexVariable{

            double re;
            double im;

            public:
                
                ComplexVariable(double re = 0, double im = 0){
                    this->re = re;
                    this->im = im;
                }

                ComplexVariable& operator+(const double c);
                ComplexVariable& operator*(const double c);
                ComplexVariable& operator-(const double c);
                ComplexVariable& operator/(const double c);
                ComplexVariable& operator==(const double c);
                ComplexVariable& operator^(const double c);

                ComplexVariable operator+(const complex<double> x);
                ComplexVariable operator-(const complex<double> x);
                ComplexVariable operator*(const complex<double> x);
                ComplexVariable operator^(const complex<double> x);
                ComplexVariable operator/(const complex<double> x);
                ComplexVariable operator==(const complex<double> x);

                ComplexVariable operator+(const ComplexVariable x);
                ComplexVariable operator-(const ComplexVariable x);
                ComplexVariable operator*(const ComplexVariable x);
                ComplexVariable operator^(const ComplexVariable x);
                ComplexVariable operator/(const ComplexVariable x);
                ComplexVariable operator==(const ComplexVariable x);

                friend ComplexVariable& operator+(double a, ComplexVariable r);
                friend ComplexVariable& operator*(double a, ComplexVariable r);
                friend ComplexVariable& operator-(double a, ComplexVariable r);
                friend ComplexVariable& operator/(double a, ComplexVariable r);
        };

        double solve(RealVariable);
        complex<double> solve(ComplexVariable);
}


#pragma once

#include <iostream>
#include <complex>

using namespace std;

namespace solver{
       


        class RealVariable{

            double a,b,c;

            public:
                RealVariable(double a, double b, double c);
                RealVariable(): a(0), b(1),c(0){};

                const double& getA()const{return a;}
                const double& getB()const{return b;}
                const double& getC()const{return c;}

                friend RealVariable operator+(const RealVariable& r1, const double r);
                friend RealVariable operator*(const RealVariable& r1, const double r);
                friend RealVariable operator-(const RealVariable& r1, const double r);
                friend RealVariable operator/(const RealVariable& r1, const double r);
                friend RealVariable operator==(const RealVariable& r1, const double r);
                friend RealVariable operator^(const RealVariable& r1, double r);

                friend RealVariable operator+(const RealVariable& r1,const RealVariable& r2);
                friend RealVariable operator*(const RealVariable& r1,const RealVariable& r2);
                friend RealVariable operator-(const RealVariable& r1,const RealVariable& r2);
                friend RealVariable operator/( const RealVariable& r1,const RealVariable& r2);
                friend RealVariable operator==(const RealVariable& r1,const RealVariable& r2);
                

                friend RealVariable operator+(const double a,const RealVariable& r);
                friend RealVariable operator*(const double a,const RealVariable& r);
                friend RealVariable operator-(const double a,const RealVariable& r);
                friend RealVariable operator/(const double a,const RealVariable& r);
                friend RealVariable operator==(const double a,const RealVariable& r);

        };



        class ComplexVariable{

            complex<double> a;
            complex<double> b;
            complex<double> c;

            public:
                
                ComplexVariable(): a(0), b(1,0), c(0) {}
                ComplexVariable(complex<double> a, complex<double> b, complex<double> c);
                const complex<double> &getA()const{return a;}
                const complex<double> &getB()const{return b;}
                const complex<double> &getC()const{return c;}

         

                friend ComplexVariable operator+(const ComplexVariable& c,const complex<double> a);
                friend ComplexVariable operator-(const ComplexVariable& c,const complex<double> a);
                friend ComplexVariable operator*(const ComplexVariable& c,const complex<double> a);
                friend ComplexVariable operator/(const ComplexVariable& c,const complex<double> a);
                friend ComplexVariable operator==(const ComplexVariable& c,const complex<double> a);

                friend ComplexVariable operator+(const ComplexVariable& c1,const ComplexVariable& c2);
                friend ComplexVariable operator-(const ComplexVariable& c1,const ComplexVariable& c2);
                friend ComplexVariable operator*(const ComplexVariable& c1,const ComplexVariable& c2);
                friend ComplexVariable operator==(const ComplexVariable& c1,const ComplexVariable& c2);

                friend ComplexVariable operator^(const ComplexVariable& c,const complex<double> a);

                friend ComplexVariable operator+(const complex<double> a,const ComplexVariable& c);
                friend ComplexVariable operator*(const complex<double> a,const ComplexVariable& c);
                friend ComplexVariable operator-(const complex<double> a,const ComplexVariable& c);
                friend ComplexVariable operator/(const complex<double> a,const ComplexVariable& c);
                friend ComplexVariable operator==(const complex<double> a,const ComplexVariable& c);

        };

        double solve(RealVariable);
        complex<double> solve(const ComplexVariable&);
}


#include "solver.hpp"
#include<complex>
using namespace solver;

double solver::solve(RealVariable r){
    return 0;
}

complex<double> solver::solve(ComplexVariable c){
    
    return std::complex<double>(1,2);
}

RealVariable& solver:: operator+( RealVariable& r, const double a){
    
    return r;
}

RealVariable& solver:: operator-(RealVariable& r, const double a){
    
    return r;
}

RealVariable& solver:: operator*(RealVariable& r, const double a){
   
    return r;
}

RealVariable& solver:: operator^(RealVariable& r, const double a){
    
    return r;
}

RealVariable& solver:: operator/(RealVariable& r, const double a){
   
    return r;
}

RealVariable& solver:: operator==(RealVariable& r, const double a){
   
    return r;
}

RealVariable& solver:: operator+(RealVariable& r1, RealVariable& r2){
 
    return r1;
}

RealVariable& solver:: operator-(RealVariable& r1,  RealVariable& r2){
    
    return r1;
}

RealVariable& solver:: operator*(RealVariable& r1, RealVariable& r2){
    
    return r1;
}

RealVariable& solver:: operator^(RealVariable& r1, RealVariable& r2){
  
    return r1;
}

RealVariable& solver:: operator/(RealVariable& r1, RealVariable& r2){
  
    return r1;
}

RealVariable& solver:: operator==(RealVariable& r1,RealVariable& r2){
    
    return r1;
}

RealVariable& solver:: operator+(double a, RealVariable& r){
 
    return r;
}

RealVariable& solver:: operator-(double a, RealVariable& r){
    
    return r;
}

RealVariable& solver:: operator*(double a, RealVariable& r){
    
    return r;
}

RealVariable& solver:: operator^(double a, RealVariable& r){
    
    return r;
}

RealVariable& solver:: operator/(double a, RealVariable& r){
    
    return r;
}

RealVariable& solver:: operator==(double a,RealVariable& r){
   
    return r;
}


ComplexVariable& solver:: operator+(ComplexVariable& c,double a){

    return c;
}

ComplexVariable& solver:: operator-(ComplexVariable& c, double a){
  
    return c;
}

ComplexVariable& solver:: operator*(ComplexVariable& c,double a){
   
    return c;
}

ComplexVariable& solver:: operator^(ComplexVariable& c, double a){
    
    return c;
}

ComplexVariable& solver:: operator/(ComplexVariable& c,double a){
   
    return c;
}

ComplexVariable& solver:: operator==(ComplexVariable& c, double a){
    
    return c;
}

ComplexVariable& solver:: operator+(ComplexVariable& c, complex<double> a){
    
    return c;
}

ComplexVariable& solver:: operator==(ComplexVariable& c, complex<double> a){
    
    return c;
}

ComplexVariable& solver:: operator+(ComplexVariable& c1, ComplexVariable& c2){
   
    return c1;
}

ComplexVariable& solver:: operator-(ComplexVariable& c1, ComplexVariable& c2){
   
    return c1;
}

ComplexVariable& solver:: operator*(ComplexVariable& c1, ComplexVariable& c2){
   
    return c1;
}

ComplexVariable& solver:: operator/(ComplexVariable& c1, ComplexVariable& c2){
    
    return c1;
}

ComplexVariable& solver:: operator==(ComplexVariable& c1, ComplexVariable& c2){
    
    return c1;
}

ComplexVariable& solver:: operator+(double a, ComplexVariable& c){
  
    return c;
}

ComplexVariable& solver:: operator-(double a, ComplexVariable& c){
  
    return c;
}

ComplexVariable& solver:: operator*(double a, ComplexVariable& c){
  
    return c;
}

ComplexVariable& solver:: operator/(double a, ComplexVariable& c){
  
    return c;
}

ComplexVariable& solver:: operator==(double a, ComplexVariable& c){
  
    return c;
}











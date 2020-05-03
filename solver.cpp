#include "solver.hpp"
#include<complex>
using namespace solver;


RealVariable::RealVariable(double a, double b, double c){
    this->a = a;
    this->b = b;
    this->c = c;
}

ComplexVariable::ComplexVariable(complex<double> a, complex<double> b, complex<double> c){
    this->a = complex<double> (a);
    this->b = complex<double> (b);;
    this->c = complex<double> (c);;
}


double solver::solve(RealVariable r){
    double ans;
    double dis = (r.getB() * r.getB()) - (4 * r.getA() * r.getC());
    if(dis < 0)
            throw out_of_range{"there is no result"};
    if(r.getA() == 0)
        ans = (-(r.getC())/r.getB());
    else{
        dis = sqrt(dis);
        ans = (-(r.getB() + dis)/(2 * r.getA()));
    }
        return ans; 
    
}

complex<double> solver::solve(const ComplexVariable& c){
    if(c.getA().real() != 0){
        complex<double> dist = (c.getB() * c.getB()) - (4.0 * c.getA() * c.getC());
        complex<double> ans = ((-c.getB() + sqrt(dist)) / (2.0 * c.getA()));
        return ans;
    }
    else if(c.getB() != complex<double>(0.0,0.0)) return -(c.getC()) / c.getB();
    else{{throw runtime_error("There is no real solution");}} 
}

RealVariable solver:: operator+(const RealVariable& r, const double a){
    
    return RealVariable(r.getA(), r.getB(), r.getC() + a);
}

RealVariable solver:: operator-(const RealVariable& r, const double a){
    
    return RealVariable(r.getA(), r.getB(), r.getC() - a);
}

RealVariable solver:: operator*(const RealVariable& r, const double a){
   
    return RealVariable(r.getA()*a, r.getB()*a, r.getC()*a);
}

RealVariable solver:: operator^(const RealVariable& r, double a){
    if(a == 0)return RealVariable(0,0,1);
    if(a == 1)return r;
    if(a == 2)return RealVariable(r.getA() + (r.getB()*r.getB()),0, r.getC());
    else{throw runtime_error("not more then power 2");}
    
}

RealVariable solver:: operator/(const RealVariable& r, const double a){
   if(a == 0) throw runtime_error("you divide by 0");
   RealVariable x(r.getA(), r.getB(), r.getC());
   if(r.getA() != 0) x.a = r.getA()/a;
   if(r.getB() != 0) x.b = r.getB()/a;
   if(r.getC() != 0) x.c = r.getC()/a;
    return x;
}

RealVariable solver:: operator==(const RealVariable& r, const double a){
  
    return r - a;
}

RealVariable solver:: operator+(const RealVariable& r1,const RealVariable& r2){
 
    return RealVariable(r1.getA() + r2.getA(), r1.getB() + r2.getB(),r1.getC() + r2.getC());
}

RealVariable solver:: operator-(const RealVariable& r1,const RealVariable& r2){
    
    return RealVariable(r1.getA() - r2.getA(), r1.getB() - r2.getB(),r1.getC() - r2.getC());
}

RealVariable solver:: operator*(const RealVariable& r1,const RealVariable& r2){
    
    return RealVariable(r1.getA() * r2.getC() + r1.getC() * r2.getA() + r1.getB() * r2.getB(), r1.getB() * r2.getC() + r1.getC() * r2.getB(),r1.getC() * r2.getC());
}


RealVariable solver:: operator/(const RealVariable& r1,const RealVariable& r2){
   
    return RealVariable(r1.getA() / r2.getA(), r1.getB() / r2.getB(), r1.getC() / r2.getC());
}

RealVariable solver:: operator==(const RealVariable& r1,const RealVariable& r2){

    return r1 - r2;
}

RealVariable solver:: operator+(const double a,const RealVariable& r){
    return r + a;
    
}

RealVariable solver:: operator-(const double a,const RealVariable& r){
    
    return RealVariable(-r.getA(), -r.getB(),a - r.getC());
}

RealVariable solver:: operator*(const double a,const RealVariable& r){
    
    return r * a;
}


RealVariable solver:: operator/(const double a,const RealVariable& r){
    
    return RealVariable(r.getA(), a / r.getB(), a / r.getC());
}

RealVariable solver:: operator==(const double a,const RealVariable& r){
   
    return a - r;
}


ComplexVariable solver:: operator+(const ComplexVariable& c,const complex<double> a){
    
    return ComplexVariable (c.getA(), c.getB(), c.getC() + a);
}

ComplexVariable solver:: operator-(const ComplexVariable& c,const complex<double> a){
    
    return ComplexVariable (c.getA(), c.getB(), c.getC() - a);
}

ComplexVariable solver:: operator*(const ComplexVariable& c,const complex<double> a){
    
    return ComplexVariable (c.getA() * a, c.getB() * a, c.getC() * a);
}

ComplexVariable solver:: operator/(const ComplexVariable& c,const complex<double> a){
    if( a == complex<double> (0.0,0.0)) throw runtime_error("Can't divide by zero");
    
    return ComplexVariable (c.getA() / a, c.getB() / a, c.getC() / a);
}

ComplexVariable solver:: operator==(const ComplexVariable& c,const complex<double> a){
    
    return c - a;
}

ComplexVariable solver:: operator+(const ComplexVariable& c1,const ComplexVariable& c2){
    return ComplexVariable(c1.getA() + c2.getA(), c1.getB() + c2.getB(), c1.getC() + c2.getC());
}

ComplexVariable solver:: operator-(const ComplexVariable& c1,const ComplexVariable& c2){
   
    return ComplexVariable(c1.getA() - c2.getA(), c1.getB() - c2.getB(), c1.getC() - c2.getC());
}

ComplexVariable solver:: operator*(const ComplexVariable& c1,const ComplexVariable& c2){
 
    return ComplexVariable(c1.getA() * c2.getA(), c1.getB() * c2.getB(), c1.getC() * c2.getC());
}


ComplexVariable solver:: operator==(const ComplexVariable& c1,const ComplexVariable& c2){
    
    return c1 - c2;
}

ComplexVariable solver:: operator+(const complex<double> a,const ComplexVariable& c){
    
    return c + a;
}

ComplexVariable solver:: operator-(const complex<double> a,const ComplexVariable& c){
    
    return ComplexVariable(-(c.getA()), -(c.getB()), a - (c.getC()));
}

ComplexVariable solver:: operator*(const complex<double> a,const ComplexVariable& c){
  
    return c * a;
}

ComplexVariable solver:: operator/(const complex<double> a,const ComplexVariable& c){
    
    return ComplexVariable(a / c.getA(), a / c.getB(), a / c.getC());
}

ComplexVariable solver:: operator==(const complex<double> a,const ComplexVariable& c){
  
    return a - c;
}

ComplexVariable solver:: operator^(const ComplexVariable& c,const complex<double> n){
    if(n.real() == 0) return ComplexVariable(0.0, 0.0, 1.0);
    if(n.real() == 1) return c;
    if(n.real() == 2) return ComplexVariable(1.0, 0.0, 0.0);
    else{throw runtime_error("Power is higher");}
    
}











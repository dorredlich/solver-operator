#include "doctest.h"
#include "solver.hpp"
#include <string>
#include<complex>
using namespace solver;
using namespace std;

ComplexVariable c;

TEST_CASE("test for operator +") {
    RealVariable x;
    CHECK(solve(2+x+10 == 10) == -2);
    CHECK(solve(x+20 == 1) == -21);
    CHECK(solve(7+x == 14) == 7);
    CHECK(solve(9.5 == 2.5+x) == 7);
    CHECK(solve(1+x+2 == 8) == 5);
    CHECK(solve(4+4+x == 21) == 13);
    CHECK(solve(x+1+3.5 == 5.5) == 1);
    CHECK(solve(222+x == 2555) == 2333);
    CHECK(solve(x+1.4 == 2.6) == 1.2);
    CHECK(solve(5.88+x == 11.3) == 5.42);
    CHECK(solve(x+2+3 == 4) == -1);
    CHECK(solve(x+2+3.333 == 4.125) == -1.208);   
}

TEST_CASE("test for operator -") {
    RealVariable x;
    CHECK(solve(2-10-x == 20) == -32);
    CHECK(solve(1-x-20 == 1) == -20);
    CHECK(solve(7-x-1 == 14) == -8);
    CHECK(solve(9.5 == 2.5-x) == -7);
    CHECK(solve(1-x-2.1 == 8) == -9.1);
    CHECK(solve(4-4-x == 19.11) == -19.11);
    CHECK(solve(x-1-3.5 == -5.5) == -1);
    CHECK(solve(2212-x == 2.112) == 2209.888);
    CHECK(solve(x-1.444 == 2.6) == 4.044);
    CHECK(solve(5.8-x == 11.3) == -5.5);
    CHECK(solve(x+2+3 == -1) == -6);
    CHECK(solve(x-2.21-3.90 == 2) == 8.11);
}

TEST_CASE("test for operator *") {
    RealVariable x;
    CHECK(solve(10*x == 20) == 2);
    CHECK(solve(x*10 == 1.2) == 0.12);
    CHECK(solve(x*1.3 == 4.3) == 3.3076);
    CHECK(solve(2.5*x == 2.5) == 1);
    CHECK(solve(3.45*x == 8) == 2.3188);
    CHECK(solve(8.38*x*3 == 19.11) == 0.7601);
    CHECK(solve(-3*6*x == -5.5) == 0.3055);
    CHECK(solve(-22.678*x == 2.112) == -0.0931);
}

TEST_CASE("test for operator /") {
    RealVariable x;
    CHECK(solve(0/x == 2) == 0);
    CHECK(solve(22.4/x == 1) == 22.4);
    CHECK(solve(1/4/x == 14) == 0.0178);
    CHECK(solve(x/4.2 == 2.5-x) == 2.0192);
    CHECK(solve(4.387/x == 8) == 0.5483);
    CHECK(solve(x/2/6 == 19.11) == 6.37);
    CHECK(solve(2.99/x == -5.5) == -0.5436);
    CHECK(solve(x/9.987 == 2.112) == 21.0925);
    CHECK_THROWS(solve(x/0 == 2)); 
}

TEST_CASE("test for operator ^") {
    RealVariable x;
    CHECK(solve(x^2 == 2) == 0);
    CHECK(solve(x^2 == 1) == -2);
    CHECK(solve(x^2 == 16) == -2);
    CHECK(solve(8 == x^2) == -2);
    CHECK(solve(25 == x^2) == -2);
    CHECK(solve(x^2 == 0) == 0);
    CHECK_THROWS(solve(-4 == x^2)); 
    CHECK_THROWS(solve(x^2== -16)); 
    CHECK_THROWS(solve(9 == x^3)); 
}

TEST_CASE("test for operators + and -") {
    RealVariable x;
    CHECK(solve(x+2-6 == 2) == 6);
    CHECK(solve(10+x-3 == 1) == -6);
    CHECK(solve(9-5+8-x == 14) == -2);
    CHECK(solve(3+2-9.2 == 21.5-x) == 25.7);
    CHECK(solve(x-41-6-9+20 == 8) == 44);
    CHECK(solve(25+3-x+6 == -19.11) == 53.11);
    CHECK(solve(9 == -5.5+x-8) == 22.5);
    CHECK(solve(45 == x-2.112+67.45) == -20.338);
}


TEST_CASE("test for operators + and *") {
    RealVariable x;
    CHECK(solve(x+2*6 == 2) == -10);
    CHECK(solve(10+x*3 == 1) == -3);
    CHECK(solve(9*5+8*x == 14) == -3.875);
    CHECK(solve(3+2*9.2 == 21.5*x) == 0.9953);
    CHECK(solve(x*6*9+20 == 8) == -18);
    CHECK(solve(25+3*x+6 == 19.11) == -3.9633);
    CHECK(solve(9 == -5.5+x*8) == 1.8125);
    CHECK(solve(45 == x*2.112+67.45) == -10.6297);
}

TEST_CASE("test for operators + and /") {
    RealVariable x;
    CHECK(solve(x+2/6 == 2) == 1.6666);
    CHECK(solve(10+x/3 == 1) == -27);
    CHECK(solve(9-5+8/x == 14) == 0.8);
    CHECK(solve(3+2-9.2 == 21.5/x) == -5.1190);
    CHECK(solve(x/41+6/9+20 == 8) == -519.3333);
    CHECK(solve(25+3/x+6 == -19.11) == -7.4652);
    CHECK(solve(9/3 == 5.5+x/8) == -20);
    CHECK(solve(45 == x/2.112+67.45) == 3130.29);
}


TEST_CASE("test for operators - and /") {
    RealVariable x;
    CHECK(solve(x/2-6 == 2) == -8);
    CHECK(solve(10-x/2 == 1) == 18);
    CHECK(solve(9-8-x/3.66 == 14) == -47.58);
    CHECK(solve(3-9.2 == 21.5-x/5) == 138.5);
    CHECK(solve(41/x-20 == 8) == 25.125);
    CHECK(solve(25-x/45 == -19.11) == 1984.95);
    CHECK(solve(9 == -5.5-67.87/x) == -4.6806);
    CHECK(solve(-45 == -2.112/x-67.45) == 67.4969);
}

TEST_CASE("test for operators - and ^") {
    RealVariable x;
    CHECK((solve((x^2)-6 == 2) == 2.8284 || solve((x^2)-6 == 2) == -2.8284));
    CHECK((solve(10-(x^2) == 1) == 3 || solve(10-(x^2) == 1) == -3));
    CHECK((solve(9-8+(x^2) == 14) == 3.6055 || solve(9-8+(x^2) == 14) == -3.6055));
    CHECK((solve(3-9.2 == 21.5-(x^2)) == 5.2630 || solve(3-9.2 == 21.5-(x^2)) == -5.2630));
    CHECK((solve((x^2)-41-20 == 8) == 8.3066 || solve((x^2)-41-20 == 8) == -8.3066));
    CHECK((solve(25-(x^2) == -19.11) == 6.6415 || solve(25-(x^2) == -19.11) == -6.6415));
    CHECK((solve(-9 == -5.5-(x^2)) == 1.8708 || solve(-9 == -5.5-(x^2)) == -1.8708));
    CHECK((solve(45 == (x^2)-2.112-67.45) == 10.7033 || solve(45 == (x^2)-2.112-67.45) == -10.7033));
}

TEST_CASE("test for operators * and /") {
    RealVariable x;
    CHECK(solve(x*2/6 == 2) == 6);
    CHECK(solve(10/x == 1*10) == 1);
    CHECK(solve(9*8*x/2 == 14) == 0.3888);
    CHECK(solve(3/9.2 == 21.5*x) == 0.0151);
    CHECK(solve(x/41*20 == 8*21) == 344.4);
    CHECK(solve(25/x*2 == 19.11) == 2.6164);
    CHECK(solve(9/0.5 == 5.5*x/2) == 6.5454);
    CHECK(solve(45 == x*2.112/67.45) == 1437.1448);
}


//-----------------------complex variable---------------------------

TEST_CASE("ComplexVariables"){
    CHECK(solve(c+3i==2i) == complex<double> (0.0,-1.0));
    CHECK(solve(2*c+5==4*c-3)==complex<double> (4.0,0.0));
    CHECK((solve((c^2)==16)==complex<double> (4.0,0.0) || solve((c^2)==16)==complex<double> (4.0,0.0)));
    CHECK((solve((c^2)==-16)==complex<double> (0.0,4.0) || solve((c^2)==-16)==complex<double> (0.0,-4.0)));
    CHECK((solve(c*c+4i==5i)==complex<double> (0.0,1.0) || solve(c*c+4i==5i)==complex<double> (0.0,-1.0)));
    CHECK(solve(2*c+4==3*c+2i)==complex<double> (4.0,-2.0));
    CHECK((solve((c^2) + 2*c + 4 == 20 + 6*c/2 - c)==complex<double> (4.0,0.0) || solve((c^2) + 2*c + 4 == 20 + 6*c/2 - c)==complex<double> (-4.0,0.0)));
    CHECK(solve(4*c-c+c==0)==complex<double> (0.0,0.0));
    CHECK(solve(c+2i==2*c-5)==complex<double> (5.0,2.0));
    CHECK(solve(2*c-c+4==-1*c+2i)==complex<double> (-2.0,1.0));

}

TEST_CASE("FALSE ComplexVariable"){
            CHECK_FALSE(solve(c+3i==2i) == complex<double> (3.0,-1.0));
            CHECK_FALSE(solve(2*c+5==4*c-3)==complex<double> (2.0,0.0));
            CHECK_FALSE((solve((c^2)==16)==complex<double> (4.0,1.0) || solve((c^2)==16)==complex<double> (4.0,1.0)));
            CHECK_FALSE((solve((c^2)==-16)==complex<double> (4.0,4.0) || solve((c^2)==-16)==complex<double> (4.0,-4.0)));
            CHECK_FALSE((solve(c*c+4i==5i)==complex<double> (1.0,1.0) || solve(c*c+4i==5i)==complex<double> (1.0,-1.0)));
            CHECK_FALSE(solve(2*c+4==3*c+2i)==complex<double> (4.0,2.0));
            CHECK_FALSE((solve((c^2) + 2*c + 4 == 20 + 6*c/2 - c)==complex<double> (4.0,1.0) || solve((c^2) + 2*c + 4 == 20 + 6*c/2 - c)==complex<double> (-4.0,1.0)));
            CHECK_FALSE(solve(4*c-c+c==0)==complex<double> (1.0,0.0));
            CHECK_FALSE(solve(c+2i==2*c-5)==complex<double> (-5.0,2.0));
            CHECK_FALSE(solve(2*c-c+4==-1*c+2i)==complex<double> (-2.0,-1.0));
}
TEST_CASE("ComplexVariable 2"){
            CHECK(solve(4+c+3i==2i) == complex<double> (-4.0,-1.0));
            CHECK(solve(2*c+2i==4*c-8)==complex<double> (4.0,1.0));
            CHECK((solve((c^2)==4)==complex<double> (2.0,0.0) || solve((c^2)==16)==complex<double> (-2.0,0.0)));
            CHECK((solve((c^2)==-25)==complex<double> (0.0,5.0) || solve((c^2)==-16)==complex<double> (0.0,-5.0)));
            CHECK((solve(c*c+4i==8i)==complex<double> (0.0,2.0) || solve(c*c+4i==5i)==complex<double> (0.0,-2.0)));
            CHECK(solve(2*c+4i==3*c+2i)==complex<double> (0.0,2.0));
            CHECK((solve((c^2) + 2*c + 4 == 20 + 6*c/2 - c)==complex<double> (4.0,0.0) || solve((c^2) + 2*c + 4 == 20 + 6*c/2 - c)==complex<double> (-4.0,0.0)));
            CHECK(solve(4*c-c+c==4)==complex<double> (1.0,0.0));
            CHECK(solve(c+2i==2*c+5i)==complex<double> (0.0,-3.0));
            CHECK(solve(2*c-c+4==-1*c+2i)==complex<double> (-2.0,1.0));
            CHECK(solve(3+c+3i==2i) == complex<double> (-3.0,-1.0));
            CHECK(solve(2*c+2i==4*c-6)==complex<double> (3.0,1.0));

            CHECK(solve(2*c+4==3*c+2)==complex<double> (2.0,0.0));
            CHECK((solve((c^2) + 2*c + 4 == 20 + 6*c/2 - c)==complex<double> (4.0,0.0) || solve((c^2) + 2*c + 4 == 20 + 6*c/2 - c)==complex<double> (-4.0,0.0)));
            CHECK(solve(4*c-c-4*c==4)==complex<double> (-4.0,0.0));
            CHECK(solve(5+c+2i==2*c+5i)==complex<double> (5.0,-3.0));
            CHECK(solve(2*c-c+4==2i)==complex<double> (-4.0,2.0));

            CHECK((solve((c^2)==100)==complex<double> (10.0,0.0) || solve((c^2)==100)==complex<double> (-10.0,0.0)));
            CHECK((solve((c^2)==-64)==complex<double> (0.0,8.0) || solve((c^2)==64)==complex<double> (0.0,-8.0)));
            CHECK((solve(c*c+4i==20i)==complex<double> (0.0,4.0) || solve(c*c+4i==5i)==complex<double> (0.0,-4.0)));
}

TEST_CASE("Another cases"){
             RealVariable x;
            CHECK_THROWS(solve(2*x==2^4));
            CHECK(solve(x*25 == 25)==1);
            CHECK(solve(5*x+x*5 == 20)==2);
            CHECK(solve(3*4*x+1 == 25)==2);
            CHECK(solve((x^2)*4== 100)==-5);
            CHECK(solve(x/2+5*x == 55)==10);
            CHECK(solve(x/0.5 == 4)==solve(x*2 == 4));
            CHECK(solve(x == 1)==1);
            CHECK(solve(2*x==0)==0);
            CHECK(solve(x+x+2*x == 20)==5);
            CHECK(solve(50*x == 100)==2);
            CHECK(solve(x*x+1+1 == 27)==-5);
            CHECK(solve(2.5*x+2.5*x== 100)==20);
}
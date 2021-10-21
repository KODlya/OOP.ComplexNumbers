#include "catch.hpp"
#include "Complex.h"

TEST_CASE( "Complex numbers1", "[lab1]") {
    Complex a;
    REQUIRE(a.GetIm() == 0);
    REQUIRE(a.GetReal() == 0);
    REQUIRE(strcmp("0.0000+0.0000i", a.GetStr()) == 0);
    Complex b(1);
    REQUIRE(b.GetIm() == 0);
    REQUIRE(b.GetReal() == 1);
    REQUIRE(strcmp("1.0000+0.0000i", b.GetStr()) == 0);
    Complex c(1, 2.2345);
    REQUIRE(c.GetIm() == 2.2345);
    REQUIRE(c.GetReal() == 1);
    REQUIRE(strcmp("1.0000+2.2345i", c.GetStr()) == 0);
    Complex d(a);
    REQUIRE(d.GetIm() == 0);
    REQUIRE(d.GetReal() == 0);
    REQUIRE(strcmp("0.0000+0.0000i", d.GetStr()) == 0);
    Complex e = Complex::Sum(b,c);
    REQUIRE(e.GetIm() == 2.2345);
    REQUIRE(e.GetReal() == 2);
    REQUIRE(strcmp("2.0000+2.2345i", e.GetStr()) == 0);
    Complex f = a.Dif(e);
    REQUIRE(f.GetIm() == -2.2345);
    REQUIRE(f.GetReal() == -2);
    REQUIRE(strcmp("-2.0000+(-2.2345)i", f.GetStr()) == 0);
    a.SetReal(3);
    a.SetIm(-2);
    b.SetReal(1);
    b.SetIm(4);
    Complex g = a.Mult(b);
    REQUIRE(g.GetIm() == 10);
    REQUIRE(g.GetReal() == 11);
    REQUIRE(strcmp("11.0000+10.0000i", g.GetStr()) == 0);
    a.SetReal(3);
    a.SetIm(2);
    b.SetReal(2);
    b.SetIm(1);
    Complex h = a.Div(b);
    REQUIRE(h.GetIm() == 0.2);
    REQUIRE(h.GetReal() == 1.6);
    REQUIRE(strcmp("1.6000+0.2000i", h.GetStr()) == 0);
}

TEST_CASE( "Complex numbers2", "[lab2]") {
    Complex a(1,2);
    Complex b(6, 7);
    Complex c;
    c=b=a;
    REQUIRE(strcmp("1.0000+2.0000i", a.GetStr()) == 0);
    REQUIRE(strcmp("1.0000+2.0000i", b.GetStr()) == 0);
    REQUIRE(strcmp("1.0000+2.0000i", c.GetStr()) == 0);
    c.SetIm(6); c.SetIm(7) ;
    REQUIRE((a>b) == false);
    REQUIRE((c>b) == true);
    REQUIRE((a<b) == false);
    REQUIRE((b<c) == true);
    REQUIRE((b==c) == false);
    REQUIRE((b!=c) == true);
    REQUIRE((b==a) == true);
    REQUIRE((b!=a) == false);
    REQUIRE((c>=a) == true);
    REQUIRE((c<=b) == false);
    REQUIRE((a<=b) == true);
    REQUIRE((a>=b) == true);
    a.SetReal(3);
    a.SetIm(2);
    b.SetReal(2);
    b.SetIm(1);
    Complex h = a/b;
    REQUIRE(strcmp("1.6000+0.2000i", h.GetStr()) == 0);
    a.SetReal(3);
    a.SetIm(-2);
    b.SetReal(1);
    b.SetIm(4);
    Complex g = a.Mult(b);
    REQUIRE(strcmp("11.0000+10.0000i", g.GetStr()) == 0);
    char* s = a();
    REQUIRE(strcmp("3.6056*(cos(-0.5880) + isin(-0.5880))", s) == 0);
    char* s2 = b();
    REQUIRE(strcmp("4.1231*(cos(1.3258) + isin(1.3258))", s2) == 0);
    a.SetReal(0);
    a.SetIm(-2);
    char* s3 = a();
    REQUIRE(strcmp("2.0000*(cos(-1.5708) + isin(-1.5708))", s3) == 0);
    a.SetReal(0);
    a.SetIm(2);
    char* s4 = a();
    REQUIRE(strcmp("2.0000*(cos(1.5708) + isin(1.5708))", s4) == 0);
}

TEST_CASE("Complex numbers3", "[lab3]"){
    Complex a(1,2);
    Complex b, c;

    ofstream f("..\\text.txt");
    if(!f.is_open()) {
        cerr << "File open error";
        exit(1);
    }
    f << a;
    f.close();

    ifstream f2("..\\text.txt");
    if(!f2.is_open()) {
        cerr << "File open error";
        exit(1);
    }
    f2 >> b;
    REQUIRE(strcmp(a.GetStr(), b.GetStr())==0);
    REQUIRE(a.GetIm()==b.GetIm());
    REQUIRE(a.GetReal()==b.GetReal());
    ofstream bin("..\\bin.dat");
    if(!bin.is_open()) {
        cerr << "File open error";
        exit(1);
    }
    BinaryIn(bin, a);
    bin.close();
    ifstream bin2("..\\bin.dat");
    if(!bin2.is_open()) {
        cerr << "File open error";
        exit(1);
    }
    BinaryOut(bin2, c);
    bin2.close();
    REQUIRE(strcmp(a.GetStr(), c.GetStr())==0);
}

TEST_CASE("Complex numbers4", "[lab6]") {
    Complex a(1, 2);
    Complex b;

    try {
        a.Div(b);
    }
    catch(const exception &ex) {
        REQUIRE(strcmp(ex.what(), "Division by zero")==0);
    }

    try {
        a / b;
    }
    catch(const exception &ex) {
        REQUIRE(strcmp(ex.what(), "Division by zero")==0);
    }
}
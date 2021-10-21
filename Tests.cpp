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

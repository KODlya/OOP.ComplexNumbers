#include "catch.hpp"
#include "Complex.h"
#include "ComplexWithData.h"
#include "ImprovedComplex.h"
#include "List.h"
TEST_CASE("Complex numbers1", "[lab1]") {
    Complex a;
    REQUIRE(a.GetIm() == 0);
    REQUIRE(a.GetReal() == 0);
    REQUIRE(strcmp("0.0000+0.0000i", a.GetStr()) == 0);
    Complex b(1, 0);
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
    Complex e = Complex::Sum(b, c);
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

TEST_CASE("Complex numbers2", "[lab2]") {
    Complex a(1, 2);
    Complex b(6, 7);
    Complex c;
    c = b = a;
    REQUIRE(strcmp("1.0000+2.0000i", a.GetStr()) == 0);
    REQUIRE(strcmp("1.0000+2.0000i", b.GetStr()) == 0);
    REQUIRE(strcmp("1.0000+2.0000i", c.GetStr()) == 0);
    c.SetIm(6); c.SetIm(7);
    REQUIRE((a > b) == false);
    REQUIRE((c > b) == true);
    REQUIRE((a < b) == false);
    REQUIRE((b < c) == true);
    REQUIRE((b == c) == false);
    REQUIRE((b != c) == true);
    REQUIRE((b == a) == true);
    REQUIRE((b != a) == false);
    REQUIRE((c >= a) == true);
    REQUIRE((c <= b) == false);
    REQUIRE((a <= b) == true);
    REQUIRE((a >= b) == true);
    a.SetReal(3);
    a.SetIm(2);
    b.SetReal(2);
    b.SetIm(1);
    Complex h = a / b;
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

TEST_CASE("Complex numbers3", "[lab3]") {
    Complex a(1, 2);
    Complex b, c;

    ofstream f("..\\text.txt");
    if (!f.is_open()) {
        cerr << "File open error";
        exit(1);
    }
    f << a;
    f.close();

    ifstream f2("..\\text.txt");
    if (!f2.is_open()) {
        cerr << "File open error";
        exit(1);
    }
    f2 >> b;
    REQUIRE(strcmp(a.GetStr(), b.GetStr()) == 0);
    REQUIRE(a.GetIm() == b.GetIm());
    REQUIRE(a.GetReal() == b.GetReal());
    ofstream bin("..\\bin.dat");
    if (!bin.is_open()) {
        cerr << "File open error";
        exit(1);
    }
    BinaryIn(bin, a);
    bin.close();
    ifstream bin2("..\\bin.dat");
    if (!bin2.is_open()) {
        cerr << "File open error";
        exit(1);
    }
    BinaryOut(bin2, c);
    bin2.close();
    REQUIRE(strcmp(a.GetStr(), c.GetStr()) == 0);
}

TEST_CASE("Complex numbers with data", "[lab4]") {
    DataComplex a;
    REQUIRE(strcmp(a.GetStr(), "0.0000+0.0000i") == 0);
    REQUIRE(strcmp(a.GetData(), "12.11.2021") == 0);
    DataComplex b(1, 2);
    REQUIRE(strcmp(b.GetStr(), "1.0000+2.0000i") == 0);
    REQUIRE(strcmp(b.GetData(), "12.11.2021") == 0);
    DataComplex c(b);
    REQUIRE(strcmp(b.GetStr(), c.GetStr()) == 0);
    REQUIRE(strcmp(b.GetData(), c.GetData()) == 0);
    a = c;
    REQUIRE(strcmp(a.GetStr(), c.GetStr()) == 0);
    REQUIRE(strcmp(a.GetData(), c.GetData()) == 0);
    REQUIRE((a > b) == 0);
    REQUIRE((a == b) == 1);
    a.SetReal(5);
    a.SetIm(7);
    REQUIRE((a >= b) == 1);
    REQUIRE((a <= b) == 0);
    REQUIRE((a != b) == 1);
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
    a.SetReal(3);
    a.SetIm(2);
    b.SetReal(2);
    b.SetIm(1);
    Complex h = a.Div(b);
    REQUIRE(strcmp("1.6000+0.2000i", h.GetStr()) == 0);
    a = b = c;
    REQUIRE(strcmp("1.0000+2.0000i", a.GetStr()) == 0);
    REQUIRE(strcmp("1.0000+2.0000i", b.GetStr()) == 0);
    REQUIRE(strcmp("1.0000+2.0000i", a.GetStr()) == 0);
    Complex e = DataComplex::Sum(b, c);
    REQUIRE(strcmp("2.0000+4.0000i", e.GetStr()) == 0);
}

TEST_CASE("Improved complex numbers", "[lab4]") {
    ImprovedComplex a;
    char str[] = "1.3450+2.5678i";
    ImprovedComplex b(str);
    REQUIRE(strcmp(b.GetStr(), "1.3450+2.5678i") == 0);
    REQUIRE(b.GetReal() == 1.345);
    REQUIRE(b.GetIm() == 2.5678);
    char str2[] = "1.3450+-2.5678i";
    ImprovedComplex c(str2);
    REQUIRE(strcmp(c.GetStr(), "1.3450+-2.5678i") == 0);
    REQUIRE(c.GetReal() == 1.345);
    REQUIRE(c.GetIm() == -2.5678);
    ImprovedComplex d = c;
    REQUIRE(strcmp(c.GetStr(), d.GetStr()) == 0);
    ImprovedComplex e(2, 3);
    REQUIRE(strcmp(e.GetStr(), "2.0000+3.0000i") == 0);
    ImprovedComplex f;
    REQUIRE(strcmp(f.GetStr(), "0.0000+0.0000i") == 0);
    a.SetReal(5);
    a.SetIm(7);
    REQUIRE((a >= b) == 1);
    REQUIRE((a <= b) == 0);
    REQUIRE((a != b) == 1);
    c.SetReal(1);
    c.SetIm(2);
    a.SetReal(3);
    a.SetIm(-2);
    b.SetReal(1);
    b.SetIm(4);
    Complex g = a.Mult(b);
    REQUIRE(strcmp("11.0000+10.0000i", g.GetStr()) == 0);
    ImprovedComplex l = a * b;
    REQUIRE(strcmp("11.0000+10.0000i", l.GetStr()) == 0);
    char* s = a();
    REQUIRE(strcmp("3.6056*(cos(-0.5880) + isin(-0.5880))", s) == 0);
    char* s2 = b();
    REQUIRE(strcmp("4.1231*(cos(1.3258) + isin(1.3258))", s2) == 0);
    a.SetReal(3);
    a.SetIm(2);
    b.SetReal(2);
    b.SetIm(1);
    Complex h = a.Div(b);
    REQUIRE(strcmp("1.6000+0.2000i", h.GetStr()) == 0);
    ImprovedComplex z = a / b;
    REQUIRE(strcmp("1.6000+0.2000i", z.GetStr()) == 0);
    a = b = c;
    REQUIRE(strcmp("1.0000+2.0000i", a.GetStr()) == 0);
    REQUIRE(strcmp("1.0000+2.0000i", b.GetStr()) == 0);
    REQUIRE(strcmp("1.0000+2.0000i", a.GetStr()) == 0);
    Complex j = ImprovedComplex::Sum(b, c);
    REQUIRE(strcmp("2.0000+4.0000i", j.GetStr()) == 0);
    a.SetReal(0);
    a.SetIm(0);
    try {
        b / a;
    }
    catch (const exception& ex) {
        REQUIRE(strcmp(ex.what(), "Division by zero") == 0);
    }
    try {
        b.Div(a);
    }
    catch (const exception& ex) {
        REQUIRE(strcmp(ex.what(), "Division by zero") == 0);
    }
}

TEST_CASE("Complex Numbers", "[lab5]"){
    Complex a(1, 2);
    DataComplex b(1, 6);
    ImprovedComplex c(2, 2);
    DataComplex d;
    List list;
    list.Insert(a);
    list.Insert(b);
    list.Insert(c);
    REQUIRE(strcmp(list[0].GetStr(), "2.0000+2.0000i") == 0);
    REQUIRE(strcmp(list[1].GetStr(), "1.0000+6.0000i") == 0);
    REQUIRE(strcmp(list[2].GetStr(), "1.0000+2.0000i") == 0);
    list.InsertByPosition(a, 0);
    REQUIRE(strcmp(list[0].GetStr(), "1.0000+2.0000i") == 0);
    REQUIRE(strcmp(list[1].GetStr(), "2.0000+2.0000i") == 0);
    REQUIRE(strcmp(list[2].GetStr(), "1.0000+6.0000i") == 0);
    REQUIRE(strcmp(list[3].GetStr(), "1.0000+2.0000i") == 0);
    list.InsertByPosition(d, 3);
    REQUIRE(strcmp(list[0].GetStr(), "1.0000+2.0000i") == 0);
    REQUIRE(strcmp(list[1].GetStr(), "2.0000+2.0000i") == 0);
    REQUIRE(strcmp(list[2].GetStr(), "1.0000+6.0000i") == 0);
    REQUIRE(strcmp(list[3].GetStr(), "0.0000+0.0000i") == 0);
    REQUIRE(strcmp(list[4].GetStr(), "1.0000+2.0000i") == 0);
    list.DeleteByPosition(3);
    cout<<"\n";
    REQUIRE(strcmp(list[0].GetStr(), "1.0000+2.0000i") == 0);
    REQUIRE(strcmp(list[1].GetStr(), "2.0000+2.0000i") == 0);
    REQUIRE(strcmp(list[2].GetStr(), "1.0000+6.0000i") == 0);
    REQUIRE(strcmp(list[3].GetStr(), "1.0000+2.0000i") == 0);
    list.DeleteByPosition(3);
    REQUIRE(strcmp(list[0].GetStr(), "1.0000+2.0000i") == 0);
    REQUIRE(strcmp(list[1].GetStr(), "2.0000+2.0000i") == 0);
    REQUIRE(strcmp(list[2].GetStr(), "1.0000+6.0000i") == 0);
    list.DeleteByPosition(0);
    list.DeleteByPosition(0);
    REQUIRE(strcmp(list[0].GetStr(), "1.0000+6.0000i") == 0);
    list.DeleteByPosition(0);
    list.InsertBack(a);
    list.InsertBack(b);
    list.InsertBack(c);
    REQUIRE(strcmp(list[0].GetStr(), "1.0000+2.0000i") == 0);
    REQUIRE(strcmp(list[1].GetStr(), "1.0000+6.0000i") == 0);
    REQUIRE(strcmp(list[2].GetStr(), "2.0000+2.0000i") == 0);
    try {
        list.DeleteByPosition(10);
    }
    catch (const exception& ex) {
        REQUIRE(strcmp(ex.what(), "Out of list range") == 0);
    }
    try {
        list.InsertByPosition(c, 30);
    }
    catch (const exception& ex) {
        REQUIRE(strcmp(ex.what(), "Out of list range") == 0);
    }
    try {
        list[21];
    }
    catch (const exception& ex) {
        REQUIRE(strcmp(ex.what(), "Out of list range") == 0);
    }
}

TEST_CASE("Complex numbers6", "[lab6]") {
    Complex a(1, 2);
    Complex b;

    try {
        a.Div(b);
    }
    catch (const exception& ex) {
        REQUIRE(strcmp(ex.what(), "Division by zero") == 0);
    }

    try {
        a / b;
    }
    catch (const exception& ex) {
        REQUIRE(strcmp(ex.what(), "Division by zero") == 0);
    }
}


#include <iostream>
#include <vector>
class Shape {
protected:
    std::pair<int,int> center;
public:
    Shape():center(0,0) {};
    Shape(int a,int b):center(a,b) {};
    std::pair<int,int> GetCenter() const {return center;}
};

class Ellipse:public Shape {
protected:
    std::pair<int,int> diametres;
public:
    Ellipse():Shape() {
        diametres.first = 0;
        diametres.second = 0;
    }
    Ellipse(int a, int b, int c, int d):Shape(a,b) {
        diametres = {c,d};
    }
    std::pair<int,int> GetDiametres() const { return diametres; }
};

class Circle:public Ellipse {
public:
    Circle():Ellipse(){};
    Circle(int a, int b,int c):Ellipse(a,b,c,c){};

};

class Quadrangle:public Shape {
protected:
    std::vector<int> sides;
public:
    Quadrangle():Shape(0,0) {
        sides = {0,0,0,0};
    }
    Quadrangle(int a,int b,int c,int d,int e,int f):Shape(a,b){
        sides = {c,d,e,f};
    }
    std::vector<int> GetSides() {
        return sides;
    }
};


class Rectangle:public Quadrangle {
public:
    Rectangle():Quadrangle(){};
    Rectangle(int a, int b, int c, int d):Quadrangle(a,b,c,d,c,d){};
};

class Square:public Rectangle {
public:
    Square():Rectangle(){};
    Square(int a, int b, int c):Rectangle(a,b,c,c){};
};

class Triangle:public Shape {
private:
    std::vector<int> angles;
public:
    Triangle():Shape() {
        angles = {0,0,0};
    };
    Triangle(int a,int b, int c, int d, int e):Shape(a,b) {
        angles = {c,d,e};
    }
    const std::vector<int> GetAngles() const {
        return angles;
    }
};
int main() {
    Square a(1,2,3);
    std::cout << a.GetCenter().first << ' ' << a.GetCenter().second;
    for(int b:a.GetSides()) {
        std::cout << b << ' ';
    }
    std::cout << '\n';
    Ellipse b(5,8,2,9);
    std::cout << b.GetCenter().first << ' ' << b.GetCenter().second;
    std::cout << b.GetDiametres().first << ' ' << b.GetDiametres().second;

    return 0;
}

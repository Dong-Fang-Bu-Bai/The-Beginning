#include <cmath>
#include <corecrt_math_defines.h>
#include<iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 基类Shape
class Shape {
public:
    virtual double area() const = 0;      // 计算面积
    virtual double volume() const = 0;   // 计算体积
    virtual string getName() const = 0;   // 获取形状名称
    virtual ~Shape() {}                   // 虚析构函数
};

// 二维形状基类
class TwoDimShape : public Shape {
public:
    double volume() const override { return 0; } // 二维形状体积为0
};

// 三维形状基类
class ThreeDimShape : public Shape {
    // 保留area()和volume()为纯虚函数
};

// 圆形类
class Circle : public TwoDimShape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override { return  M_PI * radius * radius; }
    string getName() const override { return "Circle"; }
};

// 矩形类
class Rectangle : public TwoDimShape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override { return width * height; }
    string getName() const override { return "Rectangle"; }
};

// 三角形类
class Triangle : public TwoDimShape {
private:
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    double area() const override { return 0.5 * base * height; }
    string getName() const override { return "Triangle"; }
};

// 正方形类
class Square : public TwoDimShape {
private:
    double side;
public:
    Square(double s) : side(s) {}
    double area() const override { return side * side; }
    string getName() const override { return "Square"; }
};

// 球体类
class Sphere : public ThreeDimShape {
private:
    double radius;
public:
    Sphere(double r) : radius(r) {}
    double area() const override { return 4 * M_PI * radius * radius; }
    double volume() const override { return (4.0 / 3.0) * M_PI * radius * radius * radius; }
    string getName() const override { return "Sphere"; }
};

// 立方体类
class Cube : public ThreeDimShape {
private:
    double side;
public:
    Cube(double s) : side(s) {}
    double area() const override { return 6 * side * side; }
    double volume() const override { return side * side * side; }
    string getName() const override { return "Cube"; }
};

// 圆柱体类
class Cylinder : public ThreeDimShape {
private:
    double radius, height;
public:
    Cylinder(double r, double h) : radius(r), height(h) {}
    double area() const override { return 2 * M_PI * radius * (radius + height); }
    double volume() const override { return M_PI * radius * radius * height; }
    string getName() const override { return "Cylinder"; }
};

// 金字塔类
class Pyramid : public ThreeDimShape {
private:
    double baseLength, baseWidth, height;
public:
    Pyramid(double bl, double bw, double h) : baseLength(bl), baseWidth(bw), height(h) {}
    double area() const override {
        double slantHeight1 = sqrt(height * height + (baseWidth / 2) * (baseWidth / 2));
        double slantHeight2 = sqrt(height * height + (baseLength / 2) * (baseLength / 2));
        return baseLength * baseWidth + baseLength * slantHeight1 + baseWidth * slantHeight2;
    }
    double volume() const override { return (1.0 / 3.0) * baseLength * baseWidth * height; }
    string getName() const override { return "Pyramid"; }
};

int main() {
    // 创建各种形状对象
    vector<Shape*> shapes = {
        new Circle(5.0),
        new Rectangle(4.0, 6.0),
        new Triangle(3.0, 4.0),
        new Square(5.0),
        new Sphere(3.0),
        new Cube(4.0),
        new Cylinder(2.0, 5.0),
        new Pyramid(4.0, 4.0, 6.0)
    };

    // 输出每个形状的信息
    cout << "形状信息表:\n";
    cout << "--------------------------------------------\n";
    cout << "名称\t\t面积\t\t体积\n";
    cout << "--------------------------------------------\n";

    for (const auto& shape : shapes) 
    {
        cout <<left<<setfill(' ') <<setw(10)  <<shape->getName() << "\t";
        cout << shape->area() << "\t\t";
        cout << shape->volume() << endl;
    }
    cout << "--------------------------------------------\n";

    // 释放内存
    for (const auto& shape : shapes) {
        delete shape;
    }

    system("pause");
    return 0;
}
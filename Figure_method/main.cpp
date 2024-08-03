//
//  main.cpp
//  Figure_method
//
//  Created by Александр Нестеров on 8/3/24.
//

#include <iostream>
#include <string>

class Figure {
protected:
    std::string name;
    int sides_count;

    Figure(std::string name, int sides_count) : name(name), sides_count(sides_count) {}

public:
    Figure() : Figure("Фигура", 0) {}

    virtual void print_info() const {
        std::cout << name << ":\n";
        std::cout << (check() ? "Правильная\n" : "Неправильная\n");
        std::cout << "Количество сторон: " << sides_count << "\n";
    }

    virtual bool check() const {
        return sides_count == 0;
    }

    std::string get_name() const { return name; }
    int get_sides_count() const { return sides_count; }
};

class Triangle : public Figure {
protected:
    double a, b, c;
    double A, B, C;

    Triangle(std::string name, double a, double b, double c, double A, double B, double C)
        : Figure(name, 3), a(a), b(b), c(c), A(A), B(B), C(C) {}

public:
    void print_info() const override {
        Figure::print_info();
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n";
    }

    bool check() const override {
        return (A + B + C == 180);
    }
};

class SimpleTriangle : public Triangle {
public:
    SimpleTriangle(double a, double b, double c, double A, double B, double C)
        : Triangle("Треугольник", a, b, c, A, B, C) {}
};

class RightTriangle : public Triangle {
public:
    RightTriangle(double a, double b, double c, double A, double B)
        : Triangle("Прямоугольный треугольник", a, b, c, A, B, 90.0) {}

    bool check() const override {
        return Triangle::check() && (C == 90);
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(double a, double b, double A, double B)
        : Triangle("Равнобедренный треугольник", a, b, a, A, B, A) {}

    bool check() const override {
        return Triangle::check() && (a == c) && (A == C);
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double side)
        : Triangle("Равносторонний треугольник", side, side, side, 60.0, 60.0, 60.0) {}

    bool check() const override {
        return Triangle::check() && (a == b && b == c) && (A == 60 && B == 60 && C == 60);
    }
};

class Quadrangle : public Figure {
protected:
    double a, b, c, d;
    double A, B, C, D;

    Quadrangle(std::string name, double a, double b, double c, double d, double A, double B, double C, double D)
        : Figure(name, 4), a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {}

public:
    void print_info() const override {
        Figure::print_info();
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n";
    }

    bool check() const override {
        return (A + B + C + D == 360);
    }
};

class SimpleQuadrangle : public Quadrangle {
public:
    SimpleQuadrangle(double a, double b, double c, double d, double A, double B, double C, double D)
        : Quadrangle("Четырёхугольник", a, b, c, d, A, B, C, D) {}
};

class Rectangle : public Quadrangle {
public:
    Rectangle(double a, double b)
        : Quadrangle("Прямоугольник", a, b, a, b, 90.0, 90.0, 90.0, 90.0) {}

    bool check() const override {
        return Quadrangle::check() && (a == c) && (b == d) && (A == 90 && B == 90 && C == 90 && D == 90);
    }
};

class Square : public Quadrangle {
public:
    Square(double side)
        : Quadrangle("Квадрат", side, side, side, side, 90.0, 90.0, 90.0, 90.0) {}

    bool check() const override {
        return Quadrangle::check() && (a == b && b == c && c == d) && (A == 90 && B == 90 && C == 90 && D == 90);
    }
};

class Parallelogram : public Quadrangle {
public:
    Parallelogram(double a, double b, double A, double B)
        : Quadrangle("Параллелограмм", a, b, a, b, A, B, A, B) {}

    bool check() const override {
        return Quadrangle::check() && (a == c) && (b == d) && (A == C) && (B == D);
    }
};

class Rhombus : public Quadrangle {
public:
    Rhombus(double side, double A, double B)
        : Quadrangle("Ромб", side, side, side, side, A, B, A, B) {}

    bool check() const override {
        return Quadrangle::check() && (a == b && b == c && c == d) && (A == C) && (B == D);
    }
};

void print_info(const Figure* figure) {
    figure->print_info();
    std::cout << "\n";
}

int main() {
    Figure base_figure;
    SimpleTriangle triangle(10, 20, 30, 50, 60, 70);
    RightTriangle rightTriangle(10, 20, 30, 50, 60);
    RightTriangle correctRightTriangle(10, 20, 30, 50, 40);
    IsoscelesTriangle isoscelesTriangle(10, 20, 50, 60);
    EquilateralTriangle equilateralTriangle(30);

    SimpleQuadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle rectangle(10, 20);
    Square square(20);
    Parallelogram parallelogram(20, 30, 30, 40);
    Rhombus rhombus(30, 30, 40);

    print_info(&base_figure);
    print_info(&triangle);
    print_info(&rightTriangle);
    print_info(&correctRightTriangle);
    print_info(&isoscelesTriangle);
    print_info(&equilateralTriangle);

    print_info(&quadrangle);
    print_info(&rectangle);
    print_info(&square);
    print_info(&parallelogram);
    print_info(&rhombus);

    return 0;
}


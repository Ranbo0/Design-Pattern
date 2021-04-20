/********************************************************************************
 *
 * @author: Cao Xingyu
 * @date: 2021-04-04
 * @description: Abstract Factory Pattern
 * @version: 1.0
 * @conditions: The products of the system have more than one product family,
 *              and the system only consumes the products of one family
 *
 ********************************************************************************/

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Shape {
public:
    virtual void draw() = 0;
};

class Color {
public:
    virtual void fill() = 0;
};

class Rectangle : public Shape {
public:
    virtual void draw() {
        cout << "Inside Rectangle::draw() method.\n";
    }
};

class Triangle : public Shape {
public:
    virtual void draw() {
        cout << "Inside Triangle::draw() method.\n";
    }
};

class Square : public Shape {
public:
    virtual void draw() {
        cout << "Inside Square::draw() method.\n";
    }
};

class Circle : public Shape {
public:
    virtual void draw() {
        cout << "Inside Circle::draw() method.\n";
    }
};

class Others : public Shape {
public:
    virtual void draw() {
        cout << "No such shape.\n";
    }
};

class Red : public Color {
public:
    virtual void fill() {
        cout << "Inside Red::fill() method.\n";
    }
};

class Yellow : public Color {
public:
    virtual void fill() {
        cout << "Inside Yellow::fill() method.\n";
    }
};

class Blue : public Color {
public:
    virtual void fill() {
        cout << "Inside Blue::fill() method.\n";
    }
};

class OtherColor : public Color {
public:
    virtual void fill() {
        cout << "No such color.\n";
    }
};

/********************************************************************************/

class AbstractFactory {
public:
    virtual Shape *getShape(const string shapeType) = 0;
    virtual Color *getColor(const string colorType) = 0;
};

class ShapeFactory : public AbstractFactory {
public:
    virtual Shape *getShape(const string shapeType) {
        if (shapeType == "Triangle") {
            return new Triangle;
        }
        else if (shapeType == "Rectangle") {
            return new Rectangle;
        }
        else if (shapeType == "Square") {
            return new Square;
        }
        else if (shapeType == "Circle") {
            return new Circle;
        }
        else {
            return new Others;
        }
    }

    virtual Color *getColor(const string colorType) {
        return new OtherColor;
    }
};

class ColorFactory : public AbstractFactory {
public:
    virtual Shape *getShape(const string shapeType) {
        return new Others;
    }

    virtual Color *getColor(const string colorType) {
        if (colorType == "Red") {
            return new Red;
        }
        else if (colorType == "Yellow") {
            return new Yellow;
        }
        else if (colorType == "Blue") {
            return new Blue;
        }
        else {
            return new OtherColor;
        }
    }
};

/****************************************************************************************/

int main() {
    //ShapeFactory *SF = new ShapeFactory;
    AbstractFactory *SF = new ShapeFactory;
    AbstractFactory *CF = new ColorFactory;

    Shape *s1 = SF->getShape("Triangle");
    s1->draw();

    Shape *s2 = SF->getShape("Rectangle");
    s2->draw();

    Shape *s3 = SF->getShape("Square");
    s3->draw();

    Shape *s4 = SF->getShape("Circle");
    s4->draw();

    Shape *s5 = SF->getShape("Type");
    s5->draw();

    //ColorFactory *CF = new ColorFactory;

    Color *c1 = CF->getColor("Red");
    c1->fill();

    Color *c2 = CF->getColor("Blue");
    c2->fill();

    Color *c3 = CF->getColor("Yellow");
    c3->fill();

    Color *c4 = CF->getColor("Purple");
    c4->fill();

    system("pause");

    return 0;
}
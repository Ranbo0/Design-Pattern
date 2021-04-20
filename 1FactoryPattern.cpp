/********************************************************************************
 *
 * @author: Cao Xingyu
 * @date: 2021-04-04
 * @description: Factory Pattern
 * @version: 1.0
 * @conditions: Create different instances under different conditions
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
        cout << "No such method.\n";
    }
};

/********************************************************************************/

class ShapeFactory {
public:
    static Shape *getShape(const string shapeType) {
        if (shapeType == "Triangle") {
            return new Triangle;
            //Triangle *tri = new Triangle;
            //return tri;
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
};

/****************************************************************************************/

int main() {
    ShapeFactory *SF = new ShapeFactory;

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

    system("pause");

    return 0;
}
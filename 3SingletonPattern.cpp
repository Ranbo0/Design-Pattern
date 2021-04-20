/********************************************************************************
 *
 * @author: Cao Xingyu
 * @date: 2021-04-04
 * @description: Factory Pattern
 * @version: 1.0
 * @conditions: A globally used class is frequently created and destroyed
 *
 ********************************************************************************/

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SingleObject {
private:
    SingleObject(){
        cout << "SingleObject is called!\n";
    }
    SingleObject(SingleObject &) = delete;
    SingleObject &operator=(const SingleObject &) = delete;
    static SingleObject *instance;

public:
    static SingleObject* getInstance() {
        if (instance == nullptr) {
            instance = new SingleObject;
            //return new SingleObject;
        }
        return instance;
    }
    ~SingleObject() {
        cout << "SingleObject is deconstructed!\n";
    }
};

SingleObject* SingleObject::instance = nullptr;

class SingleObject2 {
private:
    SingleObject2() {
        cout << "SingleObject2 is called!\n";
    }
    SingleObject2(SingleObject2 &) = delete;
    SingleObject2 operator=(SingleObject2 &) = delete;
public:
    ~SingleObject2() {
        cout << "SingleObject2 is deconstructed!\n";
    }
    static SingleObject2& getInstance() {
        static SingleObject2 SO;
        return SO;
    }
};

int main() {
    //SingleObject *SO = new SingleObject; //error: calling a private constructor of class 'SingleObject'
    SingleObject *SO1 = SingleObject::getInstance();
    SingleObject *SO2 = SingleObject::getInstance();

    SingleObject2 &SO_1 = SingleObject2::getInstance();
    SingleObject2 &SO_2 = SingleObject2::getInstance();

    //delete SO1;
    //delete SO2;   //cause problem

    system("pause");
    return 0;
}
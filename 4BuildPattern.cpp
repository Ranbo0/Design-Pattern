
/********************************************************************************
 *
 * @author: Cao Xingyu
 * @date: 2021-04-04
 * @description: Factory Pattern
 * @version: 1.0
 * @conditions: The basic components don't change, but their combinations often change
 *
 ********************************************************************************/

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Packing {
public:
    virtual string pack();
};

class Item {
public:
    virtual string name();
    virtual Packing* packing();
    virtual float price();
};

class Wrapper : public Packing {
public:
    virtual string pack() {
        return "Wrapper";
    }
};

class Bottle : public Packing {
public:
    virtual string pack() {
        return "Bottle";
    }
};

class Burger : public Item {
public:
    virtual Packing* packing() {
        return new Wrapper;
    }

    virtual float price();
};

class ColdDrink : public Item {
public:
    virtual Packing* packing() {
        return new Bottle;
    }
    virtual float price();
};

class VegBurger : public Burger {
public:
    virtual float price() {
        return 25.0f;
    }

    virtual string name() {
        return "Vegetable Burger";
    }
};

class ChickenBurger : public Burger {
public:
    virtual float price() {
        return 50.0f;
    }

    virtual string name() {
        return "Chicken Burger";
    }
};

class cokecola : public ColdDrink {
public:
    virtual float price() {
        return 30.0f;
    }

    virtual string name() {
        return "Coke Cola";
    }
};

class pepsi : public ColdDrink {
public:
    virtual float price() {
        return 36.0f;
    }

    virtual string name() {
        return "Pepsi";
    }
};

class Meal {
private:
    vector<Item> items;

public:
    float getCost() {
        float cost = 0;
        for (auto& item : items) {
            cost += item.price();
        }
        return cost;
    }

    void addItem(Item* item) {
        items.emplace_back(*item);
    }

    void showItems() {
        for (auto& item : items) {
            cout << "Item : " << item.name();
            cout << ",\t Packing : " << item.packing()->pack();
            cout << ",\t Price : " << item.price();
            cout << '\n';
        }
    }
};

class MealBuilder {
public:
    Meal* prepareVegMeal() {
        Meal *meal = new Meal;
        meal->addItem(new VegBurger);
        meal->addItem(new cokecola);

        return meal;
    }

    Meal* prepareMeatMeal() {
        Meal *meal = new Meal;
        meal->addItem(new ChickenBurger);
        meal->addItem(new pepsi);

        return meal;
    }
};

int main() {
    MealBuilder *mealbuilder = new MealBuilder;

    Meal *vegMeal = mealbuilder->prepareVegMeal();
    cout << "Veg meal" << endl;
    vegMeal->showItems();
    cout << "Total price is : " << vegMeal->getCost() << endl;

    cout << "\n\n";

    Meal *meatMeal = mealbuilder->prepareMeatMeal();
    cout << "Meat meal" << endl;
    meatMeal->showItems();
    cout << "Total price is : " << meatMeal->getCost() << endl;

    system("pause");
    return 0;
}
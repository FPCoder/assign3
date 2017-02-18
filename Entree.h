#ifndef ENTREE_H
#define ENTREE_H

#include <iostream>
#include <string>
using namespace std;

class Entree {
public:
    Entree() : name(""), price(0) {}
    Entree(string str, double p) : name(str), price(p) {}
    string getName() const { return name; }
    double getPrice() const { return price; }
    void setName(string str) { name = str; }
    void setPrice(double p) { price = p; }
    bool operator==(Entree lhs) { return name == lhs.getName(); }
    bool operator<(Entree lhs) { return name < lhs.getName(); }
    bool operator>(Entree lhs) { return name > lhs.getName(); }
    string operator<<(Entree lhs) { 
        string ret = lhs.getName();
        ret += " ";
        ret += lhs.getPrice();
        return ret;
    }
private:
    string name;
    double price;
};

#endif // ENTREE_H

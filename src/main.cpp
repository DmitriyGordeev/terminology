#include <iostream>
#include "WordEngine/Graph.h"
using namespace std;

struct Object {
    Object(double d) { this->d = d; }
    ~Object() { cout << "Object destructor" << endl; }
    double d;
};

struct CheckObject {
    CheckObject() {}
    ~CheckObject() { cout << "Check destructor" << endl; }
};

int main(int argc, char** argv) {

    shared_ptr<Object> s_ptr_1(new Object(0.01));
    shared_ptr<Object> s_ptr_2(new Object(0.02));
    shared_ptr<Object> s_ptr_3(new Object(0.03));

    vector<shared_ptr<Object>> v1;
    v1.push_back(s_ptr_1);
    v1.push_back(s_ptr_2);
    v1.push_back(s_ptr_3);

    CheckObject co;

    vector<shared_ptr<Object>> v2;
    v2.push_back(s_ptr_1);
    v2.push_back(s_ptr_2);
    v2.push_back(s_ptr_3);

    return 0;
}
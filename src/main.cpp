#include <iostream>
#include "WordEngine/Graph.h"
using namespace std;


void play_unique_ptr() {
    unique_ptr<double> u_ptr(new double(5.01));
    double* ptr = u_ptr.get();
    unique_ptr<double> other_u_ptr(ptr);
}


void play_shared_ptr() {
    shared_ptr<double> s_ptr(new double(5.01));
    double* ptr = s_ptr.get();
    shared_ptr<double> other_s_ptr(ptr);
}


int main(int argc, char** argv) {

    play_unique_ptr();
    return 0;
}
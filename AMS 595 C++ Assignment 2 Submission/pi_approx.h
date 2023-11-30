#pragma once 

#include <cmath>

// struct used in order to return both an approximation and an error
// from the pi_approx() function
struct PiResults {
    double approx;
    double error;
};

double fx(double x);

PiResults pi_approx(int N);
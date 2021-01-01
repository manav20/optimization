/*
    code for backtracking line search function. Use the alpha nad beta values to tune the algorithm,
    @file: lineSearch.cpp
    @author: Manav
*/


#include "line_search.hpp"
#include "cost_function.hpp"


using namespace std;

double backtracking(const double& x_1, const double& x_2, const vector<double>& direction, const vector<double>& gradient) { 
    double alpha = 0.3;
    double beta = 0.7;
    double t = 1;
    while(1) {
        double left = rosenb_f({x_1 + t*direction[0], x_2 + t*direction[1]});
        double right = rosenb_f({x_1, x_2}) + alpha*t*(gradient[0]*direction[0] + gradient[1]*direction[1]);
        if (left <= right)
            break;
        t = beta * t;
    }
    return t;
}   


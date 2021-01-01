/*
    contains commonly used matrix math functions.
    Edit:
        1. 12/23/2020: Zero error check of inverse.
        2. 12/25/2020: passing pointer in norm

    @file: math_function.cpp
    @author: Manav
*/

#include <cmath>
#include <iostream>
#include "math_function.hpp"

using namespace std;

vector<vector<double>> inverse_mat(vector<vector<double>> m) {
    vector<vector<double>> minv = {{0, 0}, {0, 0}};
    double det = m[0][0]*m[1][1] - m[1][0]*m[0][1];
    if (det == 0) {
        cout << "\nExiting...determinant of Hessian = 0\n";
        exit(0);
    }
    double invdet = 1/det;
    minv[0][0] = m[1][1]*invdet;
    minv[0][1] = m[0][1]*invdet*(-1);
    minv[1][0] = m[1][0]*invdet*(-1);
    minv[1][1] = m[0][0]*invdet;
    return minv;
}

double norm(const vector<double>& v) {
    double sum = 0;
    for (int i = 0; i < v.size(); i++)
        sum += v[i] * v[i];
    return sqrt(sum);
}

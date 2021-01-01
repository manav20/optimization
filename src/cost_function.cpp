/**
    contains fucntions for cost function value, gradient of cost function and hessian(double derevative) of cost function.
    Edit:
        1.  adding const in parameters
    
    
    @file: costFunction.cpp
    @author: Manav
*/
#include "cost_function.hpp"

using namespace std;

double rosenb_f(const vector<double>& x) {
    return 100*(x[1] - x[0]*x[0])*(x[1] - x[0]*x[0]) + (1 - x[0])*(1 - x[0]); 
}

vector<double> rosenb_grad(const vector<double>& x) {
    vector<double> ans(2, 0);
    ans[0] = -400*(x[1] - x[0]*x[0])*x[0] - 2*(1 - x[0]);
    ans[1] = 200*(x[1] - x[0]*x[0]);
    return ans;
}

vector<vector<double>> rosenb_d2f(const vector<double>& x) {
    vector<vector<double>> ans = {{0, 0}, {0, 0}};
    ans[0][0] = -400*(x[1]-3*x[0]*x[0]) + 2;
    ans[0][1] = -400*x[0];
    ans[1][0] = -400*x[0];
    ans[1][1] = 200;
    return ans;
}

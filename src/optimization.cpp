/*
    Contains two optimization functions, newtons algorithm and steepest descent.
    There are two stopping criteria, 
        1. epsilon_g,  specifies the minimum gradient below which algorithm stops.
        2. max_iter, specifies the maximum number of iterations.
    
    
    Updates: 
        1. 12/23/2020: Reduced repeated code in both algorithms.
                        Implemented an optimization class. 
                        Updated stopping criteria into a seperate function.
                        Removed data logging.
        2. 12/25/2020: made iter_data a const function





    @file: optmization.cpp
    @author: Manav
*/

#include <iostream>
#include <vector>
#include <iomanip>

#include "line_search.hpp"
#include "cost_function.hpp"
#include "optimization.hpp"
#include "math_function.hpp"

using namespace std;


Opt::Opt(double maximum_iteration) {
    max_iter = maximum_iteration;
}


bool Opt::CheckStop(const double& iter, const vector<double>& g_curr) {
    const double epsilon_x = 1.0000e-4;
    const double epsilon_g = 1.0000e-5;   
    bool stop_flag = false;
    if (norm(g_curr) < epsilon_g) { 
        cout << "Stopped due to low gradient\n";
        stop_flag = true;
    }
    if (iter >= max_iter) {
        cout << "Stopped due to max iteration limit reached\n";
        stop_flag = true;
    }  
    return stop_flag;
}   


void Opt::DisplayIteration(double iter_no, double x_1, double x_2, double step_size) const {
    cout.precision(20);
    cout << iter_no << '\t' <<  x_1 << '\t' << x_2  << '\t' << rosenb_f({x_1, x_2}) << '\t' << step_size << '\n';
}

vector<double> Opt::newton(const vector<double>& x0, const vector<double>& g_curr) {
    vector<vector<double>> F_curr, F_curr_inv;
    F_curr = rosenb_d2f({x0[0], x0[1]});
    F_curr_inv = inverse_mat(F_curr); 
    vector<double> d_curr(2, 0);
    d_curr[0] = -1 * (F_curr_inv[0][0]*g_curr[0] + F_curr_inv[0][1]*g_curr[1]);
    d_curr[1] = -1 * (F_curr_inv[1][0]*g_curr[0] + F_curr_inv[1][1]*g_curr[1]);
    return d_curr;
}

vector<double> Opt::steep_desc(const vector<double>& g_curr) {
    vector<double> d_curr(2, 0);
    d_curr[0] = -g_curr[0];
    d_curr[1] = -g_curr[1];
    return d_curr;
}


void Opt::optimize(const vector<double>& x0, const string& algo) {
    double iter_no = 1;
    double x_curr_1, x_curr_2;
    vector<double> d_curr(2, 0);
    double x_new_1 = x0[0], x_new_2 = x0[1];
   
    while(iter_no++) {
        x_curr_1 = x_new_1;
        x_curr_2 = x_new_2;
        vector<double> g_curr = rosenb_grad({x_curr_1, x_curr_2});
        if (algo == "newtons_algorithm")
            d_curr = newton({x_curr_1, x_curr_2}, g_curr);
        else if (algo == "steepest_descent")
            d_curr = steep_desc(g_curr);
        double alpha = backtracking(x_curr_1, x_curr_2, d_curr, g_curr);
        x_new_1 = x_curr_1 + alpha*d_curr[0];
        x_new_2 = x_curr_2 + alpha*d_curr[1];
        double step_size = alpha*norm(d_curr);
        DisplayIteration(iter_no, x_new_1, x_new_2, step_size);
        if (CheckStop(iter_no, g_curr))  break;
    }   
}




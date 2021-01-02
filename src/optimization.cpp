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


bool Opt::CheckStop(const double& iter_no, const vector<double>& gradient) {
    const double epsilon_x = 1.0000e-4;
    const double epsilon_g = 1.0000e-5;   
    bool stop_flag = false;
    if (norm(gradient) < epsilon_g) { 
        cout << "Stopped due to low gradient\n";
        stop_flag = true;
    }
    if (iter_no >= max_iter) {
        cout << "Stopped due to max iteration limit reached\n";
        stop_flag = true;
    }  
    return stop_flag;
}   


void Opt::DisplayIteration(double iter_no, double x_1, double x_2, double step_size) const {
    cout.precision(20);
    cout << iter_no << '\t' <<  x_1 << '\t' << x_2  << '\t' << rosenb_f({x_1, x_2}) << '\t' << step_size << '\n';
}

vector<double> Opt::newton(const vector<double>& x0, const vector<double>& gradient) {
    vector<vector<double>> hessian = rosenb_d2f({x0[0], x0[1]});
    vector<vector<double>> hessian_inverse = inverse_mat(hessian); 
    vector<double> direction(2, 0);
    direction[0] = -1 * (hessian_inverse[0][0]*gradient[0] + hessian_inverse[0][1]*gradient[1]);
    direction[1] = -1 * (hessian_inverse[1][0]*gradient[0] + hessian_inverse[1][1]*gradient[1]);
    return direction;
}

vector<double> Opt::steep_desc(const vector<double>& gradient) {
    vector<double> direction(2, 0);
    direction[0] = -gradient[0];
    direction[1] = -gradient[1];
    return direction;
}


void Opt::optimize(const vector<double>& x0, const string& algorithm_choice) {
    double iter_no = 0;
    double x_curr_1, x_curr_2;
    vector<double> direction(2, 0);
    double x_new_1 = x0[0], x_new_2 = x0[1];
   
    while(iter_no++) {
        x_curr_1 = x_new_1;
        x_curr_2 = x_new_2;
        vector<double> gradient = rosenb_grad({x_curr_1, x_curr_2});
        if (algorithm_choice == "newtons_algorithm")
            direction = newton({x_curr_1, x_curr_2}, gradient);
        else if (algorithm_choice == "steepest_descent")
            direction = steep_desc(gradient);
        double alpha = backtracking(x_curr_1, x_curr_2, direction, gradient);
        x_new_1 = x_curr_1 + alpha*direction[0];
        x_new_2 = x_curr_2 + alpha*direction[1];
        double step_size = alpha*norm(gradient);
        DisplayIteration(iter_no, x_new_1, x_new_2, step_size);
        if (CheckStop(iter_no, gradient))  break;
    }   
}





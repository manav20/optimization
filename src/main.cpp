/*
    main.cpp for the optimization profile
    Edits: 
        1.12/25/2020: timing, code duration code added 
        

    @file: main.cpp
    @author: Manav    
*/



#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>

#include "cost_function.hpp"
#include "line_search.hpp"
#include "math_function.hpp"
#include "optimization.hpp"



int main(int argc, char** argv) {
    
    std::cout << "Optimisation on Rosenbrock Function \n"; 
    
    std::string algo_choice = argv[1];
    double x_1 = atof(argv[2]);
    double x_2 = atof(argv[3]);
    double max_iter = atof(argv[4]);
    
    std::cout << "User Entry \n";
    std::cout << "Algorithm Choice: " << algo_choice << '\n';
    std::cout << "Starting Point: " << x_1 << "," << x_2 << '\n';
    std::cout << "Max Iterations for stopping: "<< max_iter << '\n';
    std::cout  << "-------------------------------------------\n";
    std::cout << "Iter_no. \t x_1 \t\t\t x_2 \t\t function_value \t\t step_size  \n"; 
   
    if (algo_choice != "newtons_algorithm" && algo_choice != "steepest_descent") {
        std::cout << "Invalid Choice\n";
        std::cout << "Please use the below sample inputs for reference,\n";
        std::cout << "./run steepest_descent 1.2 1.2 1000\n";
        std::cout << "./run newtons_algorithm 1.2 1.2 1000\n";
        exit(0);
    }


    auto time_start = std::chrono::high_resolution_clock::now();
    
    Opt optim(max_iter);
    optim.optimize({x_1, x_2}, algo_choice);
    
    auto time_stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(time_stop - time_start);
    std::cout << "Code duration: " << duration.count() << " ms\n";
    
    return 0;
}



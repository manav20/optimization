Optimization

Description:
The code implements two algorithms namely steepest descent and newtons algorithm to minimize a 2D rosenbrock function.

Algorithm:
    We chosse the direction of optimizaation usgin one of the two algorithm, along that particular direction the step size 
    step size of choosen according to the backtracking line search. Alpha = 0.3 and Beta = 0.7

Installation:     
    cd path/to/repo
    mkdir build
    cd build
    cmake ..
    make
    ./run steepest_descent 1.2 1.2 1000

Usage:
type the follwing on the command line,
    ./run steepest_descent 1.2 1.2 1000

             ./run - is the executable
            steepest_descent - is the algorithm, other available options : "newtons_algorithm".
            1.2 1.2 - starting point of the optimizer.
            1000 - maximum iterations, there are two stopping criteria, command line control of only one is given.

Data logging:
    Use the last parameter to record data in a text file.
    file location: working_directory/data/steep_desc_data.txt
                    working_directory/data/newton_data.txt

Analysis:
    Use the working_directory/scripts/plot.py
    contains python code to visualize the recorded data from text file.

Edits:
	12/23/2020:
	math_function.cpp - zero inverse check
	optimization.cpp/.hpp - Class Opt introduced, code reuse reduced.
	main.cpp - minor changes to suport the code updates.



Author:
    Manav Wadhawan - mwadhawa@purdue.edu


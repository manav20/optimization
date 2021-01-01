#ifndef COSTFUNCTION_HPP_
#define COSTFUNCTION_HPP_

#include <vector>

double rosenb_f(const std::vector<double>& x);
std::vector<double> rosenb_grad(const std::vector<double>& x);
std::vector<std::vector<double>> rosenb_d2f(const std::vector<double>& x);

#endif // COSTFUNCTION_HPP_

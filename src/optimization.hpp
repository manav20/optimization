#ifndef OPTIMIZATION_HPP_
#define OPTIMIZATION_HPP_

#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

class Opt
{
    public:
        double max_iter;
        Opt(double maximum_iteration);
        bool CheckStop(const double& iter, const std::vector<double>& gradient);
        void IterationData(const double iter_no, const double x_1, const double x_2, const double step_size, std::ofstream& myfile);
        std::vector<double> newton(const std::vector<double>& x0, const std::vector<double>& gradient);
        std::vector<double> steep_desc(const std::vector<double>& gradient);
        void optimize(const std::vector<double>& x0, const std::string& algorithm_choice);
};

#endif // OPTIMIZATION_HPP_

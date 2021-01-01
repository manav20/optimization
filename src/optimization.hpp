#ifndef OPTIMIZATION_HPP_
#define OPTIMIZATION_HPP_

#include <vector>
#include <string>

class Opt
{
    public:
        double max_iter;
        Opt(double maximum_iteration);
        bool CheckStop(const double& iter, const std::vector<double>& gradient);
        void DisplayIteration(double iter_no, double x_1, double x_2, double step_size) const;
        std::vector<double> newton(const std::vector<double>& x0, const std::vector<double>& gradient);
        std::vector<double> steep_desc(const std::vector<double>& gradient);
        void optimize(const std::vector<double>& x0, const std::string& algorithm_choice);
};

#endif // OPTIMIZATION_HPP_

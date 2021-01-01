#ifndef OPTIMIZATION_HPP_
#define OPTIMIZATION_HPP_

#include <vector>
#include <string>

class Opt
{
    public:
        double max_iter;
        Opt(double maximum_iteration);
        bool CheckStop(const double& iter, const std::vector<double>& g_curr);
        void DisplayIteration(double iter_no, double x_1, double x_2, double step_size) const;
        std::vector<double> newton(const std::vector<double>& x0, const std::vector<double>& g_curr);
        std::vector<double> steep_desc(const std::vector<double>& g_curr);
        void optimize(const std::vector<double>& x0, const std::string& algo);
};

#endif // OPTIMIZATION_HPP_

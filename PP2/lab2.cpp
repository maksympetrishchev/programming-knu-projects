// Programming project 2, variant 176.
// Author: Maksym Petrishchev, ITK-11.

#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

const double a = -0.4;
const double b = 0.4;

/// Possible outcomes of reading the input data.
enum class input_status
{
    ok,
    x_not_number,
    x_out_of_domain,
    eps_not_number,
    eps_not_positive
};

/// Prints the author and the purpose of the program.
void print_intro()
{
    cout << "The author of this program is Maksym Petrishchev, ITK-11.\n";
    cout << "Variant 176. The program calculates the sum of a power "
            "series S(x)\nat a given point x with a given accuracy eps.\n";
}

/// Reads x and then eps. Stops reading after the first problem
/// and returns what went wrong, or ok if both values are correct.
input_status read_input(double& x, double& eps)
{
    input_status status = input_status::ok;
    cout << "Enter x (" << a << " <= x <= " << b << "): ";
    cin >> x;
    if (cin.fail())
        status = input_status::x_not_number;
    else if (x < a || x > b)
        status = input_status::x_out_of_domain;
    else
    {
        cout << "Enter eps (eps > 0): ";
        cin >> eps;
        if (cin.fail())
            status = input_status::eps_not_number;
        else if (eps <= 0)
            status = input_status::eps_not_positive;
    }
    return status;
}

/// Calculates S(x) of variant 176. Summation stops at the first
/// term whose absolute value is less than eps; that term is included.
double s(double x, double eps)
{
    const double x2 = x * x;
    double term = x;
    double sum = term;
    int n = 0;
    while (abs(term) >= eps)
    {
        const int odd = 2 * n + 1;
        term *= -2.0 * odd * odd * x2 / ((n + 1) * (odd + 2));
        sum += term;
        ++n;
    }
    return sum;
}

/// Prints the error header and the reason why S(x) cannot be calculated.
void print_error(input_status status)
{
    cout << "\n***** error\n";
    if (status == input_status::x_not_number)
        cout << "input error: x must be a real number\n";
    else if (status == input_status::x_out_of_domain)
        cout << "wrong value: x is out of [" << a << "; " << b << "]\n";
    else if (status == input_status::eps_not_number)
        cout << "input error: eps must be a real number\n";
    else
        cout << "wrong value: eps must be greater than zero\n";
    cout << "S(x) cannot be calculated\n";
}

/// Prints the entered data and the calculated value of S(x).
void print_result(double x, double eps, double result)
{
    cout << scientific << uppercase;
    cout << "for x = " << setprecision(7) << x << '\n';
    cout << "for eps = " << setprecision(9) << eps << '\n';
    cout << fixed << setprecision(8) << "result = " << result << '\n';
}

int main()
{
    print_intro();

    double x = 0;
    double eps = 0;
    const input_status status = read_input(x, eps);

    if (status == input_status::ok)
    {
        cout << "\n***** do calculations ... ";
        const double result = s(x, eps);
        cout << "done\n";
        print_result(x, eps, result);
    }
    else
        print_error(status);
}

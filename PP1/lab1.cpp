// Programming project 1, variant 176.
// Author: Maksym Petrishchev, ITK-11.

#include <cmath>
#include <iomanip>
#include <iostream>
#include <numbers>
#include <optional>

using namespace std;

/// Prints the author and the purpose of the program.
void print_intro()
{
    cout << "The author of this program is Maksym Petrishchev, ITK-11.\n";
    cout << "This program calculates the value of the expression "
            "by given x. Variant 176.\n";
}

/// Checks whether x belongs to the domain of the expression: [5, 7].
bool is_in_domain(double x)
{
    return 5 <= x && x <= 7;
}

/// Calculates the value of the expression of variant 176 at x.
double f(double x)
{
    using numbers::e;
    using numbers::pi;
    return cos(18.0 / 45) + 21 * pi
           - 50 * e * 13 / ((x + 4) * (x + 5))
           - 10 * asin(x - 6) + log(x - 3) / log(15.0);
}

/// Returns f(x) if x is in the domain, otherwise nothing.
optional<double> calculate(double x)
{
    if (!is_in_domain(x))
        return nullopt;
    return f(x);
}

/// Prints the entered value and the result of the calculation.
void print_result(double x, optional<double> result)
{
    cout << fixed << setprecision(5) << "for x = " << x << '\n';
    cout << "result = ";
    if (result)
        cout << setprecision(9) << *result << '\n';
    else
        cout << "undefined\n";
}

int main()
{
    print_intro();

    double x;
    cout << "Enter x (5 <= x <= 7): ";
    cin >> x;

    if (cin.fail())
        cout << "\nwrong input\n";
    else
    {
        cout << "\n***** do calculations ... ";
        optional<double> result = calculate(x);
        cout << "done\n";
        print_result(x, result);
    }
}

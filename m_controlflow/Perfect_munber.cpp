#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int sum_of_divisors(int nb)
{
    int sum;
    int i;

    sum = 0;
    i = 1;
    while (i < nb)
    {
        if (nb % i == 0)
            sum += i;
        i++;
    }
    return (sum);
}

string perfectNumberList(int nb)
{
    string result;
    int i;

    result = "";
    i = 2;
    while (i <= nb)
    {
        if (sum_of_divisors(i) == i)
        {
            if (!result.empty())
                result += "-";
            result += to_string(i);
        }
        i++;
    }
    return (result.empty() ? "none" : result);
}

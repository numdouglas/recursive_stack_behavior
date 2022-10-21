#include <iostream>
#include <strstream>
#include <string>
#include <cassert>
#include <algorithm>

// Program demonstates call stacks LIFO and FIFO behavior
void print_out(int first, int second)
{
    std::cout << first << ',' << second << ',';
}

void enFib(int one, int two)
{
    static int calls{1};
    static int generate_target{10};

    // FIFO behavior before recursive call
    print_out(one, two);

    if (calls * 2 < generate_target)
    {
        calls++;
        enFib(one + two, one + two + two);
    }

    // LIFO behavior after recursive call
    // print_out(one, two);
}

std::string lifo_enFib(int one, int two)
{
    static int calls{1};
    static int generate_target{10};
    static std::string out;

    if (calls * 2 < generate_target)
    {
        calls++;

        lifo_enFib(one + two, one + two + two);
    }

    out.append(std::to_string(two));
    out.append(std::to_string(one));

    return out;
}

int main()
{
    std::string s = lifo_enFib(1, 1);

    std::reverse(s.begin(), s.end());

    std::cout << s << std::endl;

    enFib(1, 1);

    return 0;
}
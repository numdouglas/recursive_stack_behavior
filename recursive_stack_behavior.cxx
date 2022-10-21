#include <iostream>

//Program demonstates call stacks LIFO and FIFO behavior
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

int main()
{
    enFib(1, 1);
    return 0;
}
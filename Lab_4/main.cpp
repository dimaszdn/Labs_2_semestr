#include <iostream>
#include<Matrix.h>

int main()
{
    try
    {
        Matrix<int, 3, 3> M3({ {1, 2, 3}, {4, 5, 6}, {7, 8, 9} });
        Matrix<int, 3, 2> M4({ {1, 2}, {4, 5}, {7, 8} });
        std::cout << M3 * M4 << "\n";
        M3.at(-1, 2);
    }
    catch (const std::out_of_range& ex)
    {
        std::cout << ex.what() << "\n";
    }
    return 0;
}
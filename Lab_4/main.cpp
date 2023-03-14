#include <iostream>
#include<Matrix.h>

void f()
{
    std::cout << "Enter Matrix: " << "\n";
}

int main()
{   Matrix<int, 2, 2> M1;
    Matrix<int, 2, 1> M2;
    f();
    std::cin >> M1;
    f();
    std::cin >> M2;




    return 0;
}

/*const size_t row = 3, cols = 3;
    int array2[row][cols] = {{50, 1, 478}, {-21, 8, 1}, {57, -325, 0}};
    int array[row][cols];
    int sum = 0;
    for (int k = 0; k < row; ++k)
    {
        for (int i = 0; i < cols; ++i)
        {
            for (int j = 0; j < row; ++j)
            {
                sum += array1[k][j] * array2[j][i];
                std::cout << sum << std::endl;
            }
            array[k][i] = sum;
            sum = 0;
        }
    }

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << array[i][j] << " ";
        }
        std::cout << "\n";
    }*/

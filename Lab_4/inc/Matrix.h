#pragma once
#include<vector>

int maxSize(const int a, const int b)
{
    return a > b ? a : b;
}

template<typename T, int row, int col>
class Matrix
{
private:
    T m_matrix[row][col] = { 0 };

public:
    Matrix() = default;

    ~Matrix() = default;

    Matrix<T, row, col>& operator += (const Matrix<T, row, col>& right)
    {
        if (std::is_same_v<T, int> || std::is_same_v<T, double>)
        {
            for (int i = 0; i < row; ++i)
            {
                for (int j = 0; j < col; ++j)
                {
                    m_matrix[i][j] += right.m_matrix[i][j];
                }
            }
        }
        return *this;
    }

    template<int S, int N> // N - str, M - row
    Matrix<T, S, N>& operator *= (const Matrix<T, S, N>& right)
    {
        if (N == row)
        {
            Matrix<T, S, N> tmp;
            for (int k = 0; k < row; ++k)
            {
                for (int i = 0; i < N; ++i)
                {
                    for (int j = 0; j < row; ++j)
                    {
                        tmp.m_matrix[k][i] += m_matrix[k][j] * right.m_matrix[j][i];
                    }
                }
            }
            *this = tmp;
        }
        return *this;
    }
    /*
    Matrix<T, row, col> (const Matrix<T, row, col>& right)
    {
        memcpy(m_matrix, right.m_matrix, sizeof right.m_matrix);
    }*/
    /*
    Matrix& operator = (const Matrix right)
    {
        Matrix tmp = right;
        std::swap(m_matrix, tmp.m_matrix);
        return *this;
    }*/

    template<typename U, int ROW, int COL>
    friend std::ostream& operator << (std::ostream& out, const Matrix<U, ROW, COL>& A);

    template<typename U, int ROW, int COL>
    friend std::istream& operator >> (std::istream& in, Matrix<U, ROW, COL>& A);
};

template<typename U, int ROW, int COL>
Matrix<U, ROW, COL> operator + (const Matrix<U, ROW, COL>& left, const Matrix<U, ROW, COL>& right)
{
    Matrix<U, ROW, COL> tmp;
    if (std::is_same_v<U, int> || std::is_same_v<U, double>)
    {
        tmp = left;
        tmp += right;
    }
    return tmp;
}

template<typename U, int ROW, int COL>
std::ostream& operator << (std::ostream& out, const Matrix<U, ROW, COL>& A)
{
    for (int i = 0; i < ROW; ++i)
    {
        for (int j = 0; j < COL; ++j)
        {
            out << A.m_matrix[i][j] << "\t";
        }
        out << "\n";
    }
    return out;
}

template<typename U, int ROW, int COL>
std::istream& operator >> (std::istream& in, Matrix<U, ROW, COL>& A)
{
    for (int i = 0; i < ROW; ++i)
    {
        for (int j = 0; j < COL; ++j)
        {
            in >> A.m_matrix[i][j];
        }
    }
    return in;
}

using Matrix22i = Matrix<int, 2, 2>;
using Matrix33i = Matrix<int, 3, 3>;
using Matrix21i = Matrix<int, 2, 1>;
using Matrix12i = Matrix<int, 1, 2>;
using Matrix22d = Matrix<double, 2, 2>;
using Matrix33d = Matrix<double, 3, 3>;
using Matrix21d = Matrix<double, 2, 1>;
using Matrix12d = Matrix<double, 1, 2>;
using Matrix22c = Matrix<char, 2, 2>;
using Matrix33c = Matrix<char, 3, 3>;
using Matrix21c = Matrix<char, 2, 1>;
using Matrix12c = Matrix<char, 1, 2>;
using Matrix31i = Matrix<int, 3, 1>;
using Matrix31c = Matrix<char, 3, 1>;
using Matrix31d = Matrix<double, 3, 1>;
using Matrix13i = Matrix<int, 1, 3>;
using Matrix13c = Matrix<char, 1, 3>;
using Matrix13d = Matrix<double, 1, 3>;
using MatrixZero33i = Matrix<int, 3, 3>;
using MatrixZero33c = Matrix<char, 3, 3>;
using MatrixZero33d = Matrix<double, 3, 3>;

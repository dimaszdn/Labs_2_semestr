#pragma once

template<typename T, int row, int col>
class Matrix
{
private:
    T m_matrix[row][col] = { 0 };

public:
    Matrix() = default;

    Matrix(const T( &matrix)[row][col])
    {
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                m_matrix[i][j] = matrix[i][j];
    }

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

    Matrix<T, row, col> operator *= (const Matrix<T, row, col>& right)
    {
        Matrix tmp = *this;
        int sum = 0;
        for (int k = 0; k < row; ++k)
        {
            for (int i = 0; i < col; ++i)
            {
                for (int j = 0; j < row; ++j)
                {
                    sum += tmp.m_matrix[k][j] * right.m_matrix[j][i];
                }
                m_matrix[k][i] = sum;
                sum = 0;
            }
        }
        return *this;
    }

    T get(unsigned int i, unsigned int j) const
    {
        return m_matrix[i][j];
    }

    T& set(unsigned int i, unsigned int j)
    {
        return m_matrix[i][j];
    }

    T& at(int i, int j)
    {
        if (i < 0 || i >= row || j < 0 || j >= col)
            throw std::out_of_range("Invalid index!");
        return m_matrix[i][j];
    }

    template<int r_row, int r_col>
    Matrix<T, row, r_col> operator * (const Matrix<T, r_row, r_col>& right)
    {
        Matrix<T, row, r_col> tmp{};
        int sum = 0;
        if (col == r_row)
        {
            for (int k = 0; k < row; ++k)
            {
                for (int i = 0; i < r_col; ++i)
                {
                    tmp.set(k, i) = 0;
                    for (int j = 0; j < col; ++j)
                    {
                        tmp.set(k, i) += m_matrix[k][j] * right.get(j, i);
                    }
                }
            }
        }
        return tmp;
    }

    Matrix<T, row, col> & operator++()
    {
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                ++m_matrix[i][j];
        return *this;
    }

    T Det()
    {
        if (row == col)
        {
            if (col == 1)
                return m_matrix[0][0];

            if (col == 2)
                return (m_matrix[0][0] * m_matrix[1][1] - m_matrix[0][1] * m_matrix[1][0]);

            if (col == 3)
            {
                int positive = (m_matrix[0][0] * m_matrix[1][1] * m_matrix[2][2]) + (m_matrix[1][0] * m_matrix[2][1] *
                        m_matrix[0][2]) + (m_matrix[0][1] * m_matrix[1][2] * m_matrix[2][0]);

                int negative = -1 * (m_matrix[0][2] * m_matrix[1][1] * m_matrix[2][0]) - (m_matrix[0][0] * m_matrix[2][1] *
                        m_matrix[1][2]) - (m_matrix[0][1] * m_matrix[1][0] * m_matrix[2][2]);

                return (positive + negative);
            }
        }
    }

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
#pragma once

class Complex
{
private:
    double m_real = 0.0;
    double m_im = 0.0;

public:
    explicit Complex(double real = 0.0, double im = 0.0) : m_real(real), m_im(im) {}

    ~Complex() {}

    Complex(const Complex& right) : Complex(right.m_real, right.m_im) {}

    Complex& operator = (const Complex& right)
    {
        Complex tmp = right;
        std::swap(m_real, tmp.m_real);
        std::swap(m_im, tmp.m_im);
        return *this;
    }

    Complex& operator += (const Complex& right)
    {
        (*this).m_real += right.m_real;
        (*this).m_im += right.m_im;
        return *this;
    }

    Complex& operator *= (const Complex& right)
    {
        double tmp_im = (m_real * right.m_im + right.m_real * m_im);
        double tmp_real = (m_real * right.m_real) - (m_im * right.m_im);
        (*this).m_im = tmp_im;
        (*this).m_real = tmp_real;
        return *this;
    }

    Complex& operator ++()
    {
        this->m_real += 1;
        return *this;
    }

    Complex operator ++(int)
    {
        Complex tmp = *this;
        this->m_real += 1;
        return tmp;
    }

    friend std::ostream& operator << (std::ostream& out, const Complex& right);
    friend std::istream& operator >> (std::istream& in, Complex& right);
};

Complex operator + (const Complex& left, const Complex& right)
{
    Complex tmp = left;
    tmp += right;
    return tmp;
}

Complex operator * (const Complex& left, const Complex& right)
{
    Complex tmp = left;
    tmp *= right;
    return tmp;
}

std::ostream& operator << (std::ostream& out, const Complex& right)
{
    if (right.m_im >= 0)
        out << right.m_real << "+" << right.m_im << "i";
    else
        out << right.m_real << right.m_im << "i";
    return out;
}

std::istream& operator >> (std::istream& in, Complex& right)
{
    in >> right.m_real >> right.m_im;
    return in;
}
#pragma once
#include<iostream>
#include<cstring>

namespace ch
{
    size_t Max(const size_t N1, const size_t N2)
    {
        if (N1 > N2)
            return N1;
        else
            return N2;
    }

    class String
    {
    private:
        size_t m_size = 0;
        char* m_str = nullptr;

    public:
        String() = default;

        String(char* str) : m_size(std::strlen(str)), m_str(new char[m_size + 1])
        {
            std::copy(str, str + m_size, m_str);
            m_str[m_size] = '\0';
        }

        ~String()
        {
            //std::cout << "Destructor" << "\n";
            if (m_str != nullptr)
                delete[] m_str;
        }

        String(const String &other) : String(other.m_str)
        {
            std::cout << "Copy constructor" << "\n";
        }

        size_t Length() const
        {
            return m_size;
        }

        int find(const char* substring, int n)
        {
            if ((std::strlen(substring) > m_size) || (n < 0) || (n >= m_size))
                return -1;
            for (int i = n; i < m_size; ++i)
            {
                for (int j = 0;; ++j)
                {
                    if (!substring[j])
                        return i;
                    if (m_str[i + j] != substring[j])
                        break;
                }
            }
            return -1;
        }

        char& at(int index)
        {
            if (index < 0 || index >= m_size)
                throw std::out_of_range("Invalid index!");
            return m_str[index];
        }

        const char* c_str()
        {
            return (*this).m_str;
        }

        String& operator=(const String& other)
        {
            String tmp = other;
            std::swap(m_size, tmp.m_size);
            std::swap(m_str, tmp.m_str);
            return *this;
        }

        char& operator[](int index)
        {
            return m_str[index];
        }

        String& operator+=(const String& other)
        {
            size_t size = (*this).m_size + other.m_size;
            char* tmp = new char[size + 1];
            std::memcpy(tmp, m_str, m_size);

            if (other.m_str != nullptr)
                std::memcpy(tmp + m_size, other.m_str, other.m_size + 1);
            else
                tmp[m_size] = '\0';

            delete [] (*this).m_str;
            m_str = tmp;
            m_size = size;
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& out, const String& s);
        friend std::istream& operator>>(std::istream& in, String& s);
        friend bool operator==(const String& left, const String& right);
        friend bool operator < (const String& left, const String& right);
        friend bool operator > (const String& left, const String& right);
    };

    bool operator == (const String& left, const String& right)
    {
        size_t size = Max(left.m_size, right.m_size);
        if (left.m_str != nullptr && right.m_str != nullptr)
            return std::memcmp(left.m_str, right.m_str, size) == 0;
    }

    bool operator < (const String& left, const String& right)
    {
        size_t size = Max(left.m_size, right.m_size);
        if (left.m_str != nullptr && right.m_str != nullptr)
            return std::memcmp(left.m_str, right.m_str, size) < 0;
    }

    bool operator > (const String& left, const String& right)
    {
        size_t size = Max(left.m_size, right.m_size);
        if (left.m_str != nullptr && right.m_str != nullptr)
            return std::memcmp(left.m_str, right.m_str, size) > 0;
    }

    String operator+(const String& left, const String& right)
    {
        String tmp;
        tmp += left;
        tmp += right;
        return tmp;
    }

    std::ostream& operator<<(std::ostream& out, const String& s)
    {
        out << s.m_str;
        return out;
    }

    std::istream& operator>>(std::istream& in, String& s)
    {
        s.m_str = new char [s.m_size + 1];
        char a;
        while (in.peek() != '\n')
        {
            in.get(a);
            ++s.m_size;
            s.m_str[s.m_size - 1] = a;
        }
        s.m_str[s.m_size] = '\0';
        return in;
    }
}